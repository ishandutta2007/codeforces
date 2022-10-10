#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

std::string l, r, a;
int n, k;
std::vector<int> v;

std::string reduce(std::string s) {
	std::string ans;
	for(auto id : v) {
		ans += s[id];
	}
	return ans;
}

int table[26][26], curStep = 0;

int p[26];
bool used[26];

bool brute(int on, int mask) {
	if(on == n || mask == 3) {
		return true;
	}
	// if it's already chosen, check here
	int c = a[on] - 'a';
	if(p[c] != -1) {
		if((mask & 1) == 0) {
			// check with lower
			if(p[c] + 'a' < l[on]) {
				return false;
			}
		}
		if((mask & 2) == 0) {
			// check with lower
			if(p[c] + 'a' > r[on]) {
				return false;
			}
		}
		if(p[c] + 'a' > l[on]) {
			mask = mask | 1;
		}
		if(p[c] + 'a' < r[on]) {
			mask = mask | 2;
		}
		return brute(on + 1, mask);
	}
	// needs to choose something
	if(mask == 0) {
		// needs to choose between [l[on], r[on]]
		for(int i = l[on] - 'a' + 1; i < r[on] - 'a'; i++) {
			if(!used[i]) {
				used[i] = true;
				p[c] = i;
				return true;
			}
		}
		// trying borders
		if(l[on] == r[on]) {
			if(!used[l[on] - 'a']) {
				p[c] = l[on] - 'a';
				used[p[c]] = true;
				if(brute(on, mask)) {
					return true;
				}
				used[p[c]] = false;
				p[c] = -1;
			}
			return false;
		} else {
			// try l
			if(!used[l[on] - 'a']) {
				p[c] = l[on] - 'a';
				used[p[c]] = true;
				if(brute(on, mask)) {
					return true;
				}
				used[p[c]] = false;
				p[c] = -1;
			}
			// try r
			if(!used[r[on] - 'a']) {
				p[c] = r[on] - 'a';
				used[p[c]] = true;
				if(brute(on, mask)) {
					return true;
				}
				used[p[c]] = false;
				p[c] = -1;
			}
			return false;
		}
	} else if(mask == 1) {
		// needs to choose between [0, r[on]]
		for(int i = 0; i < r[on] - 'a'; i++) {
			if(!used[i]) {
				used[i] = true;
				p[c] = i;
				return true;
			}
		}
		// try r
		if(!used[r[on] - 'a']) {
			p[c] = r[on] - 'a';
			used[p[c]] = true;
			if(brute(on, mask)) {
				return true;
			}
			used[p[c]] = false;
			p[c] = -1;
		}
		return false;
	} else if(mask == 2) {
		// needs to choose between [l[on], k]
		for(int i = l[on] - 'a' + 1; i < k; i++) {
			if(!used[i]) {
				used[i] = true;
				p[c] = i;
				return true;
			}
		}
		// try l
		if(!used[l[on] - 'a']) {
			p[c] = l[on] - 'a';
			used[p[c]] = true;
			if(brute(on, mask)) {
				return true;
			}
			used[p[c]] = false;
			p[c] = -1;
		}
		return false;
	} else {
		assert(false);
		return false;
	}
}

void solve() {
	std::cin >> k >> a >> l >> r;
	// get useful positions
	v.clear();
	curStep++;
	n = (int) a.size();
	for(int i = 0; i < n; i++) {
		int x = a[i] - 'a';
		int y = l[i] - 'a';
		if(table[x][y] != curStep) {
			table[x][y] = curStep;
			v.push_back(i);
		}
	}
	curStep++;
	for(int i = 0; i < n; i++) {
		int x = a[i] - 'a';
		int y = r[i] - 'a';
		if(table[x][y] != curStep) {
			table[x][y] = curStep;
			v.push_back(i);
		}
	}
	std::sort(v.begin(), v.end());
	v.resize(std::unique(v.begin(), v.end()) - v.begin());
	a = reduce(a);
	l = reduce(l);
	r = reduce(r);
	n = (int) a.size();
	// preparing for brute force
	for(int i = 0; i < k; i++) {
		p[i] = -1;
		used[i] = false;
	}
	// go brute
	if(brute(0, 0)) {
		for(int i = 0; i < k; i++) {
			if(p[i] != -1) continue;
			int j = 0;
			while(used[j]) j++;
			used[j] = true;
			p[i] = j;
		}
		std::cout << "YES\n";
		for(int i = 0; i < k; i++) {
			std::cout << char('a' + p[i]);
		}
		std::cout << '\n';
	} else {
		std::cout << "NO\n";
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}
}