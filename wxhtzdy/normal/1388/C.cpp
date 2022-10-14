#include<bits/stdc++.h>

using namespace std;

const int N=100050;

int n,m,p[N],h[N],a[N],b[N],pp[N];
vector<int> e[N];
void dfs(int u,int par){
	a[u]=p[u];
	pp[u]=par;
	for (int v:e[u]) if (v!=par)
		dfs(v,u),a[u]+=a[v];
}
bool solve(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		e[i].clear();
	for (int i=1;i<=n;i++)
		scanf("%d",&p[i]);
	for (int i=1;i<=n;i++)
		scanf("%d",&h[i]);
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(1,0);
	for (int i=1;i<=n;i++)
		if ((h[i]+a[i])%2!=0)
			return false;
	for (int i=1;i<=n;i++){
		b[i]=(a[i]+h[i])/2;
		if (b[i]<0||b[i]>a[i])
			return false;
	}
	for (int i=1;i<=n;i++){
		int adj=0;
		for (int j:e[i]) if (j!=pp[i])
			adj+=b[j];
		if (adj>b[i])
			return false;
	}
	return true;
}

int main(){
	int T;
	scanf("%d",&T);
	while (T--) puts(solve()?"YES":"NO");
	return 0;
}