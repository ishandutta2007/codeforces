#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <set>
#include <utility>
#include <queue>
#include <iostream>

using namespace std;

int main() {
	int y0, x0, y, x, n; 
	scanf("%d %d %d %d %d", &y0, &x0, &y, &x, &n);
	set <pair <int, int> > table;
	for (int i = 0; i < n; i++) {
		int r, a, b;
		scanf("%d %d %d", &r, &a, &b);
		for (int j = a; j <= b; j++) {
			table.insert(make_pair(r, j));
		}
	}
	queue <pair <int, pair <int, int> > > way;
	way.push(make_pair(0, make_pair(y0, x0)));
	while (!way.empty()) {
		int new_y = way.front().second.first, new_x = way.front().second.second, c = way.front().first;
		way.pop();
		for (int i = new_y - 1; i <= new_y + 1; i++) {
			for (int j = new_x - 1; j <= new_x + 1; j++) {
				if (!(i == new_y && j == new_x)) {
					if (table.find(make_pair(i, j)) != table.end()) {
						if (i == y && j == x) {
							printf("%d", c + 1);
							exit(0);
						}
						table.erase(make_pair(i, j));
						way.push(make_pair(c + 1, make_pair(i, j)));
					}
				}
			}
		}

	}
	printf("-1");
	return 0;
}