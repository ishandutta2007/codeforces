#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 85, M = 100005, INF = 1000000000;

int n, m;

int x[N], s[N];

int f[M];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		f[i] = INF;
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", x + i, s + i);
		int l = x[i] - s[i], r = x[i] + s[i];
		if (l <= 1) {
			f[min(r, m)] = 0;
		} else {
			int nr = min(r + (l - 1), m);
			f[nr] = min(f[nr], l - 1);
		}
	}
	for (int i = 1; i < m; ++i) {
		if (f[i] == INF) {
			continue;
		}
		f[i + 1] = min(f[i + 1], f[i] + 1);
		for (int j = 0; j < n; ++j) {
			int l = x[j] - s[j], r = x[j] + s[j];
			if (r < i + 1) {
				continue;
			}
			if (l <= i + 1) {
				int nr = min(r, m);
				f[nr] = min(f[nr], f[i]);
			} else {
				int delta = l - (i + 1), nr = min(r + delta, m);
				f[nr] = min(f[nr], f[i] + delta);
			}
		}
	}
	printf("%d\n", f[m]);
	return 0;
}