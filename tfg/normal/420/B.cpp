#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<bool> present(n, false);
	std::vector<bool> a(n, false);
	std::vector<std::pair<char, int>> qries(m);
	int ghost = 0;
	for(int i = 0; i < m; i++) {
		std::cin >> qries[i].first >> qries[i].second;
		qries[i].second--;
		if(!present[qries[i].second]) {
			present[qries[i].second] = true;
			if(qries[i].first == '-') {
				a[qries[i].second] = true;
				ghost++;
			}
		}
	}
	std::vector<bool> good(n, true);
	int others = 0;
	for(int i = 0; i < n; i++) {
		if(!present[i]) {
			others++;
		}
	}
	std::vector<int> haha;
	for(int i = 0; i < n; i++) {
		if(present[i] && !a[i]) {
			haha.push_back(i);
		}
	}
	for(auto q : qries) {
		if(ghost) {
			while(!haha.empty()) {
				int on = haha.back();
				haha.pop_back();
				if(!a[on]) {
					good[on] = false;
				}
			}
		}
		if(q.first == '-') {
			a[q.second] = false;
			ghost--;
			haha.push_back(q.second);
		} else {
			a[q.second] = true;
			ghost++;
		}
		if(ghost) {
			while(!haha.empty()) {
				int on = haha.back();
				haha.pop_back();
				if(!a[on]) {
					good[on] = false;
				}
			}
		}
	}
	std::vector<int> ans;
	for(int i = 0; i < n; i++) {
		if(good[i]) {
			ans.push_back(i + 1);
		}
	}
	std::cout << ans.size() << std::endl;
	for(int i = 0; i < (int) ans.size(); i++) {
		std::cout << ans[i] << (i+1 == (int) ans.size() ? '\n' : ' ');
	}
}