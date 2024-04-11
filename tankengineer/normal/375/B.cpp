#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define right RIGHT

const int N = 5005;
int n, m, right[N];
char map[N][N];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%s", map[i]);
	}
	memset(right, 0, sizeof(right));
	int ans = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if ((i == 0 || map[j][i - 1] == '0') && (map[j][i] == '1')) {
				int k = i;
				while (k < m && map[j][k] == '1') {
					++right[k++];
				}
			}
		}
		for (int j = i; j < m; ++j) {
			ans = max(ans, (j - i + 1) * right[j]);
		}
	}
	printf("%d\n", ans);
	return 0;
}