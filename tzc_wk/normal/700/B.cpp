#include <bits/stdc++.h>
using namespace std;
int n,k;
bool u[200002];
vector<int> g[200002];
long long ans;
int r;
long long dfs(int x,int prev){
	long long s=u[x];
	for(int i=0;i<g[x].size();i++){
		int v=g[x][i];
		if(v==prev)	continue;
		s+=dfs(v,x);
	}
	while(s*2>r)	s-=2,r-=2;
	ans+=s;
	return s;
}
signed main(){
	scanf("%d%d",&n,&k);
	for(int i=1,x;i<=k*2;i++)	scanf("%d",&x),u[x]=1;
	r=k*2;
	for(int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,1);
	printf("%I64d\n",ans);
	return 0;
}