#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>

using namespace std;

const int MAX_N = 1000 + 10;
const int MAX_M = 1000 + 10;

int table[MAX_N][MAX_M];
bool used[MAX_M][MAX_M];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &table[i][j]);
		}
	}
	int left = 0, right = 1000000000 + 1;
	while (right - left > 1) {
		int middle = (left + right) >> 1;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				used[i][j] = false;
			}
		}
		bool ok = false;
		for (int i = 0; i < n && !ok; i++) {
			vector <int> pos;
			for (int j = 0; j < m; j++) {
				if (table[i][j] >= middle) {
					pos.push_back(j);
				}
			}
			for (int i1 = 0; i1 < (int)pos.size() && !ok; i1++) {
				for (int i2 = i1 + 1; i2 < (int)pos.size() && !ok; i2++) {
					if (used[pos[i1]][pos[i2]]) {
						ok = true;
					} else {
						used[pos[i1]][pos[i2]] = true;
					}
				}
			}
		}
		if (ok) {
			left = middle;
		} else {
			right = middle;
		}
	}
	printf("%d", left);
	return 0;
}