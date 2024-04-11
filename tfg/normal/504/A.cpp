#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <cstdio>

typedef std::pair<int, int> ii;

const int ms = 1001000;

int degree[ms];
int others[ms];

int main() {
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		scanf("%i %i", degree + i, others + i);
	}
	std::queue<int> q;
	for(int i = 0; i < n; i++) {
		if(degree[i] == 1) {
			q.push(i);
		}
	}
	std::vector<ii> ans;
	while(!q.empty()) {
		int on = q.front();
		q.pop();
		if(degree[on] == 0) {
			continue;
		}
		ans.push_back(ii(on, others[on]));
		degree[others[on]]--;
		others[others[on]] ^= on;
		if(degree[others[on]] == 1) {
			q.push(others[on]);
		}
	}
	std::cout << ans.size() << '\n';
	for(int i = 0; i < ans.size(); i++) {
		printf("%i %i\n", ans[i].first, ans[i].second);
	}
}