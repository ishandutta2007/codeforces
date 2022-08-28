//CF 840B
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
int d[333333],x[333333],y[333333];
vector<pair<int,int> > v[333333];
int vis[333333],rt,ans[333333],b[333333],s[333333];
void dfs(int u,int fa)
{
	int i,s,p;
	if(vis[u])
		return;
	vis[u]=1;
	s=v[u].size();
	for(i=0;i<s;i=i+1){
		p=v[u][i].first;
		if(p!=fa&&!vis[p]){
			b[p]=v[u][i].second;
			dfs(p,u);
		}
	}
	if(d[u]!=-1){
		ans[u]=d[u];
		if(d[fa]!=-1)
			d[fa]^=d[u];
	}
}
int main()
{
	int n,m,i,f;
	scanf("%d%d",&n,&m);
	rt=0;
	for(i=1;i<=n;i=i+1){
		scanf("%d",d+i);
		if(d[i]==-1)
			rt=i;
	}
	for(i=1;i<=m;i=i+1){
		scanf("%d%d",x+i,y+i);
		v[x[i]].push_back(make_pair(y[i],i));
		v[y[i]].push_back(make_pair(x[i],i));
	}
	if(!rt)
		rt=1;
	dfs(rt,0);
	if(d[rt]==1){
		cout<<-1<<endl;
		return 0;
	}
	f=0;
	for(i=1;i<=n;i=i+1)
		if(ans[i]){
			s[b[i]]=1;
			f++;
		}
	cout<<f<<endl;
	for(i=1;i<=m;i=i+1)
		if(s[i])
			cout<<i<<' ';
	cout<<endl;
	return 0;
}