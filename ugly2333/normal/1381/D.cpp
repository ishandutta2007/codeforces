//CF1381D
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 111111;
int n,s,t,l,a[N],d[N];
vector<int> v[N],e;
int dfs1(int u,int fa){
	e.push_back(u);
	if(u==t)
		return 1;
	int i=v[u].size(),x;
	while(i--){
		x=v[u][i];
		if(x==fa)
			continue;
		if(dfs1(x,u))
			return 1;
	}
	e.pop_back();
	return 0;
}
void dfs2(int u,int fa){
	d[u]=0;
	int i=v[u].size(),x;
	while(i--){
		x=v[u][i];
		if(a[x]||x==fa)
			continue;
		dfs2(x,u);
		d[u]=max(d[u],d[x]+1);
	}
}
int ms,mt;
void dfst(int y);
void dfss(int x){
	int u,y,o;
	u=e[x];
	y=x-d[u]+(l-1);
	y=max(y,x+1);
	if(y<mt){
		o=mt;
		mt=y;
		while(y<o){
			dfst(y);
			y++;
		}
	}
}
void dfst(int y){
	int u,x,o;
	u=e[y];
	x=y+d[u]-(l-1);
	x=min(x,y-1);
	if(x>ms){
		o=ms;
		ms=x;
		while(x>o){
			dfss(x);
			x--;
		}
	}
}
int ok(int u,int fa){
	int i=v[u].size(),x,o=0;
	while(i--){
		x=v[u][i];
		if(a[x]||x==fa)
			continue;
		if(ok(x,u))
			return 1;
		o+=(d[x]>=(l-2));
	}
	return (o>=2);
}
int main()
{
	int T,i,x,y;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&s,&t);
		for(i=1;i<n;i=i+1){
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs1(s,0);
		l=e.size();
		for(i=0;i<l;i=i+1)
			a[e[i]]=1;
		for(i=0;i<l;i=i+1)
			dfs2(e[i],0);
		ms=0,mt=l-1;
		dfss(0),dfst(l-1);
		x=0;
		for(i=0;i<=ms;i=i+1)
			x|=ok(e[i],0);
		for(i=mt;i<l;i=i+1)
			x|=ok(e[i],0);
		for(i=mt;i<=ms;i=i+1)
			x|=(d[e[i]]>=(l-1));
		if(x)
			printf("YES\n");
		else
			printf("NO\n");
		for(i=0;i<=n;i=i+1)
			v[i].clear(),a[i]=0,d[i]=0;
		e.clear();
	}
	return 0;
}