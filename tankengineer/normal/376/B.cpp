#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100;
int n, m;

int g[N][N];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		--u, --v;
		g[u][v] += w;
	}
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				int delta = min(g[i][k], g[k][j]);
				g[i][k] -= delta;
				g[k][j] -= delta;
				g[i][j] += delta;
			}
		}
	}
	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0 ;j < n; ++j) {
			sum += g[i][j];
		}
	}
	cout << sum << endl;
	return 0;
}