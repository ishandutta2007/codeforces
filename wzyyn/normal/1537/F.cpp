#include<bits/stdc++.h>
using namespace std;

const int N=200005;
vector<int> e[N];
int n,m,vis[N],ring;
int v[N],t[N];

void dfs(int x,int c){
	vis[x]=c;
	for (auto i:e[x])
		if (vis[i]==-1)
			dfs(i,c^1);
		else if (vis[i]==vis[x])
			ring=1;
}
void solve(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		e[i].resize(0);
		vis[i]=-1;
	}
	for (int i=1;i<=n;i++) scanf("%d",&v[i]);
	for (int i=1;i<=n;i++) scanf("%d",&t[i]);
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	ring=0;
	dfs(1,0);
	if (!ring){
		long long d0=0,d1=0;
		for (int i=1;i<=n;i++)
			if (vis[i]==0)
				d0+=t[i]-v[i];
			else d1+=t[i]-v[i];
		puts(d0==d1?"YES":"NO");
	}
	else{
		long long d=0;
		for (int i=1;i<=n;i++)
			d+=t[i]-v[i];
		puts(d&1?"NO":"YES");
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}