#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 110;

int n, m;
int hero[ms], hp[ms], pos[ms];
int left[ms], right[ms];
int pot[ms];

bool memo[ms][ms], visit[ms][ms];
int use[ms][ms];
int hl = ms, hr = 0;

bool dp(int l, int r) {
	if(l <= hl && hr <= r) {
		return true;
	}
	bool &ans = memo[l][r];
	if(visit[l][r]) return ans;
	ans = false;
	visit[l][r] = true;
	for(int i = 1; i < l; i++) {
		if(!hero[i] || right[hero[i]] < l) continue;
		if(dp(i, r)) {
			ans = true;
			use[l][r] = i;
			//return ans;
		}
	}
	for(int i = r + 1; i <= n; i++) {
		if(!hero[i] || left[hero[i]] > r) continue;
		if(dp(l, i)) {
			ans = true;
			use[l][r] = i;
			//return ans;
		}
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		std::cin >> pos[i] >> hp[i];
		hero[pos[i]] = i;
		hr = std::max(hr, pos[i]);
		hl = std::min(hl, pos[i]);
	}
	for(int i = 1; i <= n; i++) {
		std::cin >> pot[i];
	}
	for(int i = 1; i <= m; i++) {
		int curPos, curHp;
		curPos = pos[i], curHp = hp[i];
		while(curPos <= n && curHp >= 0) {
			curPos++;
			curHp += pot[curPos];
		}
		right[i] = curPos;
		curPos = pos[i], curHp = hp[i];
		while(curPos >= 1 && curHp >= 0) {
			curPos--;
			curHp += pot[curPos];
		}
		left[i] = curPos;
		//std::cout << "for hero " << i << " that's in pos " << pos[i] << " got (" << left[i] << ", " << right[i] << ")\n";
	}
	for(int i = 1; i <= m; i++) {
		if(dp(left[i] + 1, pos[i])) {
			//std::cout << "first type for " << i  << "\n";
			hp[i] = -1;
			std::cout << left[i] + 1 << "\n";
			std::vector<int> ans;
			ans.push_back(i);
			int l = left[i] + 1, r = pos[i];
			while(l > hl || r < hr) {
				int got = use[l][r];
				hp[hero[got]] = -1;
				ans.push_back(hero[got]);
				if(got < l) {
					l = got;
				} else {
					r = got;
				}
			}
			for(int j = 1; j <= m; j++) {
				if(hp[j] != -1) {
					ans.push_back(j);
				}
			}
			for(int j = 0; j < m; j++) {
				std::cout << ans[j] << (j + 1 == m ? '\n' : ' ');
			}
			return 0;
		} else if(dp(pos[i], right[i] - 1)) {
			//std::cout << "second type for " << i  << "\n";
			hp[i] = -1;
			std::cout << right[i] - 1 << "\n";
			std::vector<int> ans;
			ans.push_back(i);
			int l = pos[i], r = right[i] - 1;
			while(l > hl || r < hr) {
				int got = use[l][r];
				hp[hero[got]] = -1;
				ans.push_back(hero[got]);
				if(got < l) {
					l = got;
				} else {
					r = got;
				}
			}
			for(int j = 1; j <= m; j++) {
				if(hp[j] != -1) {
					ans.push_back(j);
				}
			}
			for(int j = 0; j < m; j++) {
				std::cout << ans[j] << (j + 1 == m ? '\n' : ' ');
			}
			return 0;
		}
	}
	std::cout << "-1\n";
}