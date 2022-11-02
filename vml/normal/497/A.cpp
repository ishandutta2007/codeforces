#pragma comment(linker, "/STACK:1000000000")

#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <ctime>
#include <vector>
#include <string>
#include <queue>

using namespace std;

const int maxn = 1010;

char s[maxn][maxn];
bool used[maxn];

int main() {
	int n, m;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("\n");
		for (int j = 0; j < m; j++) {
			scanf("%c", &s[i][j]);
		}
	}

	int cnt = 0;

	for (int j = 0; j < m; j++) {
		bool st = true;
		for (int i = 0; i < n - 1; i++) {
			if (s[i][j] > s[i + 1][j] && !used[i]) {
				st = false;
				cnt++;
				break;
			}
		}

		if (st) {
			for (int i = 0; i < n - 1; i++) {
				if (s[i][j] < s[i + 1][j]) {
					used[i] = true;
				}
			}
		}
	}

	cout << cnt << endl;

	return 0;
}