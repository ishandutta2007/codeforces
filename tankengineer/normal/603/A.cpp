#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005;

int n;

char s[N];

int f[N][2][3];

void update(int &a, int b) {
	a = max(a, b);
}

int main() {
	scanf("%d", &n);
	scanf("%s", s);
	memset(f, 0, sizeof(f));
	for (int i = 0; i < n; ++i) {
		int d = s[i] - '0';
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < 3; ++k) {
				if (k == 0) {
					update(f[i + 1][j][k], f[i][j][k]);
					if (d == j) {
						update(f[i + 1][j ^ 1][k], f[i][j][k] + 1);
						update(f[i + 1][j ^ 1][k + 1], f[i][j][k] + 1);
					}
					update(f[i + 1][j][k + 1], f[i][j][k]);
					if (d != j) {
						update(f[i + 1][j ^ 1][k + 1], f[i][j][k] + 1);
					}
				} else if (k == 1) {
					update(f[i + 1][j][k], f[i][j][k]);
					if (d != j) {
						update(f[i + 1][j ^ 1][k], f[i][j][k] + 1);
						update(f[i + 1][j ^ 1][k + 1], f[i][j][k] + 1);
					}
					update(f[i + 1][j][k + 1], f[i][j][k]);
					if (d == j) {
						update(f[i + 1][j ^ 1][k + 1], f[i][j][k] + 1);
					}
				} else if (k == 2) {
					update(f[i + 1][j][k], f[i][j][k]);
					if (d == j) {
						update(f[i + 1][j ^ 1][k], f[i][j][k] + 1);
					}
				}
			}
		}
	}
	int ans = 0;
	for (int j = 0; j < 2; ++j) {
		for (int k = 1; k < 3; ++k) {
			ans = max(ans, f[n][j][k]);
		}
	}
	printf("%d\n", ans);
	return 0;
}