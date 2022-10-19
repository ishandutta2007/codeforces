#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int INF = 1e9 + 1;

int n, fa[N], who[N], sz = 0, A[N];

int getf(int x) {
	return (fa[x] == x) ? x : fa[x] = getf(fa[x]);
}

int main() {
	scanf("%d", &n);
	for(int i = 1, ty, x, y; i <= n; ++ i) {
		scanf("%d", &ty);
		if(ty == 1) {
			scanf("%d", &x); ++ sz; fa[sz] = sz;
			if(!who[x]) who[x] = sz;
			else fa[sz] = getf(who[x]);
		} else {
			scanf("%d%d", &x, &y);
			if(!who[x] || x == y) continue;
			if(!who[y]) swap(who[x], who[y]);
			else {
				fa[who[x]] = getf(who[y]);
				who[x] = 0;
			}
		}
	}
	for(int i = 1; i < N; ++ i) A[who[i]] = i;
	for(int i = 1; i <= sz; ++ i) {
		int now = getf(i);
		printf("%d ", A[now]);
	}
	puts("");
}