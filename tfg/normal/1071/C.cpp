#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <set>
#include <queue>
#include <map>
#include <algorithm>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 1 << 20;
int dist[ms];
std::pair<int, int> use[ms];
std::string str;

void prep(int n) {
	dist[0] = 0;
	for(int i = 1; i < (1 << n); i++) {
		dist[i] = (int) 1e9;
	}
	std::queue<int> q;
	q.push(0);
	while(!q.empty()) {
		int on = q.front();
		q.pop();
		for(int i = 0; i < n; i++) {
			for(int j = i + 1; j + (j - i) < n; j++) {
				int k = j + (j - i);
				int to = on ^ (1 << i) ^ (1 << j) ^ (1 << k);
				if(dist[to] > dist[on] + 1) {
					dist[to] = dist[on] + 1;
					use[to] = {i, j};
					q.push(to);
				}
			}
		}
	}
}

void getPath(std::vector<std::pair<int, int>> &ans, int x, int off) {
	while(x > 0) {
		int i = use[x].first, j = use[x].second;
		int k = j + (j - i);
		ans.emplace_back(use[x].first + off, use[x].second + off);
		x ^= (1 << i) ^ (1 << j) ^ (1 << k);
	}
}

int getVal(int l, int r) {
	int ans = 0;
	for(int i = 0; i < r - l; i++) {
		if(str[l + i] == '1') {
			ans |= 1 << i;
		}
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		char c;
		c = char('0' + rng() % 2);
		std::cin >> c;
		str += c;
	}
	std::vector<std::pair<int, int>> ans;
	int l = 0, r = n;
	while(r - l >= 20) {
		//std::cout << "soving for [" << l << ", " << r << ")" << std::endl;
		std::vector<int> posR;
		for(int i = 1; i <= 3; i++) {
			if(str[r - i] == '1') {
				posR.push_back(r - i);
			}
		}
		std::vector<int> posL;
		for(int i = 0; i < 3; i++) {
			if(str[l + i] == '1') {
				posL.push_back(l + i);
			}
		}
		if(posR.size() == posL.size() && posR.size() == 2 && (posL[0] + posL[1]) % 2 == 1 && (posR[0] + posR[1]) % 2 == 1) {
			for(int i = 0; i < 2; i++) {
				for(int j = 0; j < 2; j++) {
					if(posL[i] % 2 == posR[j] % 2) {
						ans.emplace_back(posL[i], (posR[j] + posL[i]) / 2);
						int ii = posL[i], jj = (posR[j] + posL[i]) / 2, kk = posR[j];
						str[ii] = str[ii] == '0' ? '1' : '0';
						str[jj] = str[jj] == '0' ? '1' : '0';
						str[kk] = str[kk] == '0' ? '1' : '0';
					}
				}
			}
			assert(str[r-1] == '0' && str[r-2] == str[r-1] && str[r-3] == str[r-1]);
			assert(str[l] == '0' && str[l+1] == str[l] && str[l+2] == str[l]);
			l += 3;
			r -= 3;
			//std::cout << "getting border" << std::endl;
			continue;
		}
		if(posR.size() == 0) {
			r -= 3;
			continue;
		}
		if(posL.size() == 0) {
			l += 3;
			continue;
		}
		//std::cout << "got here" << std::endl;
		int i, j, k;
		if(posR.size() == 1) {
			k = posR[0];
			j = r - 4;
			i = j - (k - j);
		} else if(posR.size() == 2) {
			k = posR[0];
			j = posR[1];
			i = j - (k - j);
		} else {
			k = posR[0];
			j = posR[1];
			i = posR[2];
		}
		if(i != r - 3 || posR.size() == 3) {
			str[i] = str[i] == '0' ? '1' : '0';
			str[j] = str[j] == '0' ? '1' : '0';
			str[k] = str[k] == '0' ? '1' : '0';
			assert(str[r-1] == '0' && str[r-2] == str[r-1] && str[r-3] == str[r-1]);
			ans.emplace_back(i, j);
			r -= 3;
			//std::cout << "got right" << std::endl;
			continue;
		} else {
			assert(i == r - 3 && posR.size() == 2 && (posR[0] + posR[1]) % 2 == 1);
			assert(posR[0] == r - 1 && posR[1] == r - 2);
		}
		if(posL.size() == 1) {
			i = posL[0];
			j = l + 3;
			k = j + (j - i);
		} else if(posL.size() == 2) {
			i = posL[0];
			j = posL[1];
			k = j + (j - i);
			assert(k != l + 2);
		} else {
			i = posL[0];
			j = posL[1];
			k = posL[2];
		}
		ans.emplace_back(i, j);
		str[i] = str[i] == '0' ? '1' : '0';
		str[j] = str[j] == '0' ? '1' : '0';
		str[k] = str[k] == '0' ? '1' : '0';
		assert(str[l] == '0' && str[l+1] == str[l] && str[l+2] == str[l]);
		l += 3;
		//std::cout << "got left " << std::endl;
	}
	prep(r - l);
	if(dist[getVal(l, r)] >= 100) {
		std::cout << "NO\n";
		return 0;
	}
	getPath(ans, getVal(l, r), l);
	std::cout << "YES\n";
	std::cout << ans.size() << '\n';
	for(auto p : ans) {
		std::cout << 1 + p.first << " " << 1 + p.second << " " << 1 + p.second + (p.second - p.first) << "\n";
	}
}