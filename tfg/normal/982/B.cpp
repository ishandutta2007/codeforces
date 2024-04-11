#include <iostream>
#include <set>
#include <utility>
#include <cstdio>

typedef std::pair<int, int> ii;

char str[400200];

int main() {
	int n;
	std::cin >> n;
	std::set<ii> seats[2];
	for(int i = 0; i < n; i++) {
		int w;
		scanf("%d", &w);
		seats[0].insert(ii(w, i + 1));
	}
	scanf(" %s", str);
	for(int i = 0; i < 2 * n; i++) {
		int cur;
		if(str[i] == '0') {
			auto it = seats[0].begin();
			cur = it->second;
			seats[1].insert(ii(-it->first, it->second));
			seats[0].erase(it);
		} else {
			auto it = seats[1].begin();
			cur = it->second;
			seats[1].erase(it);
		}
		printf("%d%c", cur, i + 1 == 2 * n ? '\n' : ' ');
	}
}