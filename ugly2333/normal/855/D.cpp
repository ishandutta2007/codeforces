//CF 855D
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int N = 111111;
vector<int> v[N];
int p[N],c[N],d[N],f[N],g[N];
int tin[N],tout[N],tt;
void dfs(int u){
	int i,s,x;
	s=v[u].size();
	if(c[u]!=0)
		f[u]=u;
	else
		f[u]=f[p[u]];
	if(c[u]!=1)
		g[u]=u;
	else
		g[u]=g[p[u]];
	tin[u]=++tt;
	for(i=0;i<s;i=i+1){
		x=v[u][i];
		dfs(x);
	}
	tout[u]=++tt;
}
bool isin(int x,int y){
	return tin[x]<=tin[y]&&tout[y]<=tout[x];
}
int main()
{
	int n,i,q,t,x,y;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1){
		scanf("%d%d",p+i,c+i);
		if(p[i]+1)
			v[p[i]].push_back(i);
	}
	for(i=1;i<=n;i=i+1)
		if(p[i]==-1)
			dfs(i);
	scanf("%d",&q);
	while(q--){
		scanf("%d%d%d",&t,&x,&y);
		if(t==1){
			if(x!=y&&f[x]==f[y]&&isin(x,y))
				cout<<"YES\n";
			else
				cout<<"NO\n";
		}
		else{
			if(g[y]!=y&&x!=y&&((g[f[x]]==g[y]&&isin(g[y],f[x])&&isin(f[x],y)&&f[x]!=y)||(f[x]==f[g[y]]&&isin(f[x],g[y])&&isin(g[y],x))))
				cout<<"YES\n";
			else
				cout<<"NO\n";
		}
	}
	return 0;
}
/*
3
-1 -1
1 0
2 0
2
2 3 1
2 1 3
*/