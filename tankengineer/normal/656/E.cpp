#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 10;

int n;

int g[N][N];

int ans;

void (*f)(int, int, int);

void read(int i, int j, int k) {
	scanf("%d", &g[i][j]);
}

void floyd(int k, int i, int j) {
	g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}

void maxs(int i, int j, int k) {
	i == j ? 0 : ans = max(ans, g[i][j]);
}

void loop1(int i, int n, int j, int m, int k, int l);

int loop0(int i, int n, int j, int m, int k, int l) {
	f(i, j, k);
	loop1(i, n, j, m, k + 1, l);
	return 0;
}

void loop1(int i, int n, int j, int m, int k, int l) {
	k == l ? ++j, k = 0 : 0;
	j == m ? ++i, j = 0 : 0;
	i == n ? 0 : loop0(i, n, j, m, k, l);
}

int main() {
	scanf("%d", &n);
	f = &read;
	loop1(0, n, 0, n, 0, 1);
	f = &floyd;
	loop1(0, n, 0, n, 0, n);
	f = &maxs;
	loop1(0, n, 0, n, 0, 1);
	printf("%d\n", ans);
	return 0;
}