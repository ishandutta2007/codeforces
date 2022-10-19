#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
const int M = N * 2;

int c[N], n, m, fir[N], ne[M], to[M], cnt = 1, L[N], R[N], dlc, tot = 0, d[N];

void add(int x, int y) {
	ne[++ cnt] = fir[x];
	fir[x] = cnt;
	to[cnt] = y;
}

void link(int x, int y) {
	add(x, y);
	add(y, x);
}

#define Foreachson(i, x) for(int i = fir[x]; i; i = ne[i])

int S[N], All[N];

void dfs(int x, int f) {
	L[x] = ++ dlc; S[x] = c[x];
	Foreachson(i, x) {
		int V = to[i];
		if(V == f) continue;
		dfs(V, x); S[x] += S[V];
		if(c[x] && S[V]) {
			++ All[1], -- All[n + 1];
			-- All[L[V]];
			++ All[R[V] + 1];
		}
	}
	R[x] = dlc;
	if(S[x] != tot && c[x]) {
		++ All[L[x]]; -- All[R[x] + 1];
	}
	if(d[x] >= 2) {
		for(int i = 1; i <= n; ++ i) printf("1 ");
		puts("");
		exit(0);
	}
	if(c[x]) return;
	if(d[x]) {
		++ All[L[x]]; -- All[L[x] + 1];
		int now = 0;
		Foreachson(i, x) {
			int V = to[i];
			if(c[V]) {
				continue;
			}
			if(V == f) now += (S[x] != tot);
			else now += (S[V] != 0);
		}
		Foreachson(i, x) {
			int V = to[i];
			if(V == f || c[V]) continue;
			if(now == 1) {
				if(!S[V]) {
					++ All[L[V]]; -- All[R[V] + 1];
				}
			} else ++ All[L[V]], -- All[R[V] + 1];
		}
		if(now == 1) {
			if(!(tot - S[x])) {
				++ All[1]; -- All[L[x]];
				++ All[R[x] + 1]; -- All[n + 1];
			}
		}
		if(now >= 2) {
				++ All[1]; -- All[L[x]];
				++ All[R[x] + 1]; -- All[n + 1];			
		}
	}
}

int main() {
	cin >> n;
	for(int i = 1; i <= n; ++ i) scanf("%d", &c[i]), tot += c[i];
	for(int i = 1, x, y; i < n; ++ i) {
		scanf("%d%d", &x, &y);
		link(x, y);
		if(c[x] == 1) ++ d[y];
		if(c[y]) ++ d[x];
	}
	dfs(1, 0);
	for(int i = 1; i <= n; ++ i) All[i] += All[i - 1];
	for(int i = 1; i <= n; ++ i) {
		if(All[L[i]]) putchar('1');
		else putchar('0');
		putchar(' ');
	}
	puts("");
}