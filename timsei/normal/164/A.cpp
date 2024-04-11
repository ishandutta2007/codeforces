#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int M = N * 2;

int n, m, val[N], fir[N], ne[M], to[M], cnt, x, y;
int vis[N], bi[N];

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

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++ i) scanf("%d", &val[i]);
	for(int i = 1; i <= m; ++ i) {
		scanf("%d%d", &x, &y);
		link(x, y);
	}
	queue < int > q;
	while(!q.empty()) q.pop();
	for(int i = 1; i <= n; ++ i) {
		vis[i] = 0;
		if(val[i] == 1) q.push(i), ++ bi[i], vis[i] = 1;
	}
	while(!q.empty()) {
		x = q.front(); q.pop();
		Foreachson(i, x) if(i & 1){
			int V = to[i];
			if(vis[V]) continue;
			vis[V] = 1;
			++ bi[V];
			if(val[V] != 1) q.push(V);
		}
	}
	for(int i = 1; i <= n; ++ i) {
		vis[i] = 0;
		if(val[i] == 2) q.push(i), ++ bi[i], vis[i] = 1;
	}
	while(!q.empty()) {
		x = q.front(); q.pop();
		Foreachson(i, x) if(i % 2 == 0){
			int V = to[i];
			if(vis[V]) continue;
			++ bi[V];
			vis[V] = 1;
			if(val[V] != 1) q.push(V);
		}
	}
	for(int i = 1; i <= n; ++ i) printf("%d\n", (bi[i] == 2));
}