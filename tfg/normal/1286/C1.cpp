#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <set>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const bool debug = false;

int n;
std::string randomString;

struct Info {
	Info(std::string str = "") {
		for(int i = 0; i < 26; i++) {
			a[i] = 0;
		}
		for(auto c : str) {
			a[c-'a']++;
		}
	}

	int sum() const {
		int ans = 0;
		for(int i = 0; i < 26; i++) {
			ans += a[i];
		}
		return ans;
	}

	int a[26];
	bool operator < (const Info &o) const {
		int got = sum() - o.sum();
		if(got != 0) {
			return got < 0;
		}
		for(int i = 0; i < 26; i++) {
			if(a[i] != o.a[i]) {
				return a[i] < o.a[i];
			}
		}
		return false;
	}

	char getDiff (const Info o) const {
		for(int i = 0; i < 26; i++) {
			if(a[i] != o.a[i]) return char(i + 'a');
		}
		assert(0);
		return '#';
	}

	std::string toString() const {
		std::string ans;
		for(int i = 0; i < 26; i++) {
			for(int j = 0; j < a[i]; j++) {
				ans += char(i + 'a');
			}
		}
		return ans;
	}
};

int total = 0;

std::multiset<Info> qry(int l, int r) {
	std::cout << "? " << l + 1 << " " << r << std::endl;
	std::multiset<Info> ans;
	total += (r-l)*(r-l+1)/2;
	const int LIMIT = 1000;
	assert(total <= ((n+1)*(n+1)*LIMIT+999)/1000);
	if(debug) {
		for(int i = l; i < r; i++) {
			for(int j = i+1; j <= r; j++) {
				ans.insert(Info(randomString.substr(i, j - i)));
			}
		}
	} else {
		for(int i = 0; i < (r-l)*(r-l+1)/2; i++) {
			std::string str;
			std::cin >> str;
			ans.insert(Info(str));
		}
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> n;
	if(debug) {
		for(int i = 0; i < n; i++) {
			randomString += char(rng() % 26 + 'a');
		}
	}
	if(n == 1) {
		auto st = qry(0, 1);
		std::cout << "! " << st.begin()->getDiff(Info()) << std::endl;
		return 0;
	}
	std::multiset<Info> sets[3];
	sets[0] = qry(1, n);
	sets[1] = qry(0, n);
	for(auto x : sets[0]) {
		sets[1].erase(sets[1].find(x));
	}
	std::string ans;
	//std::cout << sets[1].size() << std::endl;
	while((int) ans.size() < n) {
		auto it = *sets[1].begin();
		//std::cout << "first is " << it.toString() << std::endl;
		ans += it.getDiff(Info(ans));
		sets[1].erase(sets[1].begin());
	}
	std::cout << "! " << ans << std::endl;
	if(debug) {
		std::cout << "should be " << randomString << std::endl;
	}
}