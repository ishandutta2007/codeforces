#include <bits/stdc++.h>
using namespace std;

int N,K;
vector<int> adj[100013];
int up[20][100013];
int h[100013];
vector<int> bad[100013];
int cantup[100013];
int cantdown[100013];
int U[100013];
int D[100013];
int two[1000013];

const int MOD = 1e9+7;

void dfs(int x, int p=0, int d=0) {
	up[0][x] = p;
	h[x] = d;
	for (int i: adj[x]) if (i!=p) dfs(i,x,d+1);
}

int lca(int a, int b) {
	if (h[a]>h[b]) swap(a,b);
	for (int i=19;i>=0;i--) if ((h[b]-h[a])&(1<<i)) b = up[i][b];
	if (a==b) return a;
	for (int i=19;i>=0;i--) if (up[i][a]!=up[i][b]) a = up[i][a], b = up[i][b];
	return up[0][a];
}

int dfs2(int x, int p=0) {
	int res = 0;
	for (int i: adj[x]) if (i!=p) {
		res = (res+dfs2(i,x))%MOD;
		U[x]+=U[i];
		D[x]+=D[i];
	}
	if (cantup[x]) res = (res+two[U[x]]-1)%MOD;
	if (cantdown[x]) res = (res+two[D[x]]-1)%MOD;
	return res;
}

int main() {
	two[0] = 1;
	for (int i=1;i<1000013;i++) two[i] = (two[i-1]*2)%MOD;
	scanf("%d",&N);
	for (int i=1;i<N;i++) {
		int a,b,x;
		scanf("%d%d%d",&a,&b,&x);
		adj[a].push_back(b);
		adj[b].push_back(a);
		if (x) bad[a].push_back(b);
	}
	dfs(1);
	for (int i=1;i<=N;i++) for (int j: bad[i]) {
		if (h[j]<h[i]) cantdown[i] = 1;
		else cantup[j] = 1;
	}
	for (int i=1;i<20;i++) for (int j=1;j<=N;j++) {
		up[i][j] = up[i-1][up[i-1][j]];
	}
	int prev = 1;
	scanf("%d",&K);
	for (int i=0;i<K;i++) {
		int s;
		scanf("%d",&s);
		U[prev]+=1;
		D[s]+=1;
		int l = lca(prev,s);
		U[l]-=1;
		D[l]-=1;
		prev = s;
	}
	printf("%d\n",dfs2(1));

	return 0;
}