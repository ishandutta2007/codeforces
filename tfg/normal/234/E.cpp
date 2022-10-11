#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

int x, a, b, c;

int getRand() {
	return x = (x * a + b) % c;
}

struct Team {
	int rating;
	std::string name;

	void read() {
		std::cin >> name >> rating;
	}
};

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n >> x >> a >> b >> c;
	std::vector<std::vector<Team>> groups(n / 4);
	std::vector<std::vector<Team>> pools(4);
	std::vector<Team> teams;
	for(int i = 0; i < n; i++) {
		Team cur;
		cur.read();
		teams.push_back(cur);
	}
	std::sort(teams.begin(), teams.end(), [](const Team &l, const Team &r) -> bool { return l.rating > r.rating; });
	for(int i = 0; i < n; i++) {
		pools[i / (n / 4)].push_back(teams[i]);
	}
	for(int i = 0; i < n; i++) {
		int pool = i % 4;
		int s = pools[pool].size();
		int idx = getRand() % s;
		std::sort(pools[pool].begin(), pools[pool].end(), [](const Team &l, const Team &r) -> bool { return l.rating > r.rating; });
		groups[i / 4].push_back(pools[pool][idx]);
		std::swap(pools[pool][idx], pools[pool].back());
		pools[pool].pop_back();
	}
	for(int i = 0; i < groups.size(); i++) {
		std::cout << "Group " << char(i + 'A') << ":" << std::endl;
		//std::sort(groups[i].begin(), groups[i].end(), [](const Team &l, const Team &r) -> bool { return l.name < r.name; });
		for(int j = 0; j < 4; j++) {
			std::cout << groups[i][j].name << std::endl;
		}
	}
}