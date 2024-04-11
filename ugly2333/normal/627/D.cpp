//CF627D
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
const int N = 222222;
const int inf = 1e6;
int n,k,m,a[N],b[N],c[N],f[N],ans,p;
vector<int> v[N];
void dfs1(int u,int fa){
	int i=v[u].size(),x;
	b[u]=1;
	c[u]=1;
	while(i--){
		x=v[u][i];
		if(x==fa)
			continue;
		if(a[x]<m){
			b[u]=0;
			continue;
		}
		if(!f[x])
			continue;
		dfs1(x,u);
		if(b[x])
			f[u]+=f[x],f[x]=0;
		else
			b[u]=0;
	}
	if(!b[u]&&!p)
		p=u;
}
void dfs2(int u,int fa){
	int i=v[u].size(),x,e=0;
	while(i--){
		x=v[u][i];
		if(x==fa||!f[x])
			continue;
		dfs2(x,u);
		ans=max(ans,e+f[u]+f[x]);
		e=max(e,f[x]);
	}
	f[u]+=e;
	ans=max(ans,f[u]);
}
int main()
{
	int i,l,r;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i=i+1)
		scanf("%d",a+i);
	for(i=1;i<n;i=i+1){
		scanf("%d%d",&l,&r);
		v[l].push_back(r);
		v[r].push_back(l);
	}
	l=1,r=inf;
	while(l<r){
		m=(l+r+1)>>1;
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(f,0,sizeof(f));
		for(i=1;i<=n;i=i+1)
			if(a[i]>=m)
				f[i]=1;
		ans=0;
		for(i=1;i<=n;i=i+1){
			if(a[i]>=m&&!c[i]){
				p=0;
				dfs1(i,0);
				if(!p)
					p=i;
				dfs1(p,0);
				dfs2(p,0);
			}
		}
		if(ans>=k)
			l=m;
		else
			r=m-1;
	}
	cout<<l;
	return 0;
}
/*
8 6
9 8 7 6 5 4 3 2
1 2
2 3
2 4
3 5
4 6
5 7
6 8

*/