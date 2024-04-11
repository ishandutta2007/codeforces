#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <memory.h>
#define mp make_pair
#define pii pair<int, int>
#define ll long long
#define ui unsigned int
#define ld double

using namespace std;

vector <int> ed[510];
int v[510];
bool used[510][10];
bool edge[510][510];
int n;

bool dfs(int x, int y) {
	v[x] = y;

	for (int i = 1; i <= n; i++) {
		if (i == x) {
			continue;
		}
		if (edge[x][i]) {
			if (v[i] != -1 && abs(v[i] - y) == 2) {
				return false;
			}

			if (v[i] == -1) {
				if (!dfs(i, y)) {
					return false;
				}
			}
		} else {
			if (v[i] != -1 && abs(v[i] - y) <= 1) {
				return false;
			}

			if (v[i] == -1) {
				if (!dfs(i, y ^ 2)) {
					return false;
				}
			}
		}
	}

	return true;
}

int main() {
	int m;

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;

		scanf("%d %d", &x, &y);

		ed[x].push_back(y);
		ed[y].push_back(x);
		edge[x][y] = true;
		edge[y][x] = true;
	}

	memset(v, -1, sizeof v);

	for (int i = 1; i <= n; i++) {
		if ((int)ed[i].size() == n - 1) {
			v[i] = 2;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (v[i] == -1) {
			if (!dfs(i, 1)) {
				printf("No");
				return 0;
			}
		}
	}

	printf("Yes\n");

	for (int i = 1; i <= n; i++) {
		printf("%c", (char)(v[i] + 'a' - 1));
	}

	return 0;
}