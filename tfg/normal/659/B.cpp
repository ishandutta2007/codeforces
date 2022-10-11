#include <iostream>
#include <vector>
#include <algorithm>

struct Person {
	std::string name;
	int rating;
};

bool operator < (const Person &a, const Person &b) {
	return a.rating > b.rating;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<Person>> teams(m);
	for(int i = 0; i < n; i++) {
		Person cur;
		int where;
		std::cin >> cur.name >> where >> cur.rating;
		teams[where - 1].push_back(cur);
	}
	for(int i = 0; i < m; i++) {
		std::sort(teams[i].begin(), teams[i].end());
		if(teams[i].size() > 2 && teams[i][1].rating == teams[i][2].rating) {
			std::cout << "?\n";
		} else {
			std::cout << teams[i][0].name << ' ' << teams[i][1].name << std::endl;
		}
	}
}