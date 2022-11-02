#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m;
vector<int> adj[100013];
int h[100013];
int s[100013];
ll len[100013];
int up[20][100013];
ll len2[100013];

void dfs(int x, int p=0) {
	up[0][x] = p;
	h[x] = h[p]+1;
	s[x] = 1;
	for (int i: adj[x]) if (i!=p) {
		dfs(i,x);
		s[x]+=s[i];
		len[x]+=len[i]+s[i];
	}
}

void dfs2(int x, int p=0, ll above=0) {
	len2[x] = above;
	ll tot = len2[x]+n-s[x];
	for (int i: adj[x]) if (i!=p) tot+=len[i]+s[i];
	for (int i: adj[x]) if (i!=p) {
		dfs2(i,x,tot-len[i]-s[i]);
	}
}

int lca(int a, int b) {
	if (h[a]>h[b]) swap(a,b);
	for (int i=19;i>=0;i--) if ((h[b]-h[a])&(1<<i)) b = up[i][b];
	if (a==b) return -a;
	for (int i=19;i>=0;i--) if (up[i][a]!=up[i][b]) a = up[i][a], b = up[i][b];
	return up[0][a];
}

int main() {
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	dfs2(1);
	for (int i=1;i<20;i++) {
		for (int j=1;j<=n;j++) up[i][j] = up[i-1][up[i-1][j]];
	}
	for (int i=0;i<m;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		int l = lca(a,b);
		if (h[a]>h[b]) swap(a,b);
		double ans = h[a]+h[b]-2*h[abs(l)]+1+1.*len[b]/s[b];
		if (l==-a) {
			for (int j=19;j>=0;j--) if ((h[b]-h[a]-1)&(1<<j)) b = up[j][b];
			ans+=1.*len2[b]/(n-s[b]);
		} else ans+=1.*len[a]/s[a];
		printf("%1.9f\n",ans);
	}

    return 0;
}