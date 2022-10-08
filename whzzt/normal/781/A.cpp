#include "bits/stdc++.h"

using namespace std;

const int N = 200005;
int n,d[N],ans,h[N],nxt[N<<1],to[N<<1],tmp;

inline void add (int u,int v){
	to[++tmp] = v, nxt[tmp] = h[u], h[u] = tmp;
	to[++tmp] = u, nxt[tmp] = h[v], h[v] = tmp;
}

int color[N];
void dfs (int x, int fa, int col){
	ans = max (d[x]+1, ans), color[x] = col;
	int cnt_co = 0;
	for (int i = h[x]; i; i = nxt[i]) if (to[i] != fa){
		do cnt_co++; while (cnt_co == col || cnt_co == color[fa]);
		dfs (to[i], x, cnt_co);
	}
}

int main(){
	cin >> n; int u,v;
	for (int i = 1; i < n; i ++) {
		scanf ("%d%d", &u, &v);
		d[u] ++ , d[v] ++;
		add(u,v);
	}
	dfs (1, 0, 1);
	cout << ans << endl;
	for (int i = 1; i <= n; i ++)
		printf ("%d ", color[i]);
	return 0;
}