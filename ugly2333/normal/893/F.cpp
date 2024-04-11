//CF 893F
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
const int N = 100005;
const int inf = 1e9+N;
int n,rt,a[N];
vector<int> v[N];
int d[N],tt,t[N],tin[N],tout[N];
vector<pair<int,int> > f[N*4];
void dfs(int u,int fa){
	int i,sz,x;
	d[u]=d[fa]+1;
	t[++tt]=u;
	tin[u]=tt;
	sz=v[u].size();
	for(i=0;i<sz;i=i+1){
		x=v[u][i];
		if(x!=fa)
			dfs(x,u);
	}
	tout[u]=tt;
}
int build(int k,int l,int r){
	if(l==r){
		f[k].push_back(make_pair(d[t[l]],a[t[l]]));
		return 1;
	}
	int md,i,x,y,sx,sy,z;
	pair<int,int> p;
	md=(l+r)>>1;
	sx=build(k<<1,l,md);
	sy=build(k<<1|1,md+1,r);
	x=0,y=0,z=0;
	for(i=0;i<sx+sy;i=i+1){
		if(x<sx&&(y==sy||f[k<<1][x]<f[k<<1|1][y]))
			p=f[k<<1][x++];
		else
			p=f[k<<1|1][y++];
		if((!z)||f[k][z-1].second>p.second)
			f[k].push_back(p),z++;//,cout<<p.second;
	}
	//cout<<l<<r<<x<<y<<z<<endl;
	return z;
}
int query(int k,int l,int r,int L,int R,int D){
	int res,md;
	if(L<=l&&r<=R){
		res=lower_bound(f[k].begin(),f[k].end(),make_pair(D+1,-1))-f[k].begin();
		if(!res)
			return inf;
		return f[k][res-1].second;
	}
	if(R<l||r<L||r<=l)
		return inf;
	res=inf;
	md=(l+r)>>1;
	if(L<=md)
		res=min(res,query(k<<1,l,md,L,R,D));
	if(md<R)
		res=min(res,query(k<<1|1,md+1,r,L,R,D));
	return res;
}
int main()
{
	int m,i,x,y,z;
	scanf("%d%d",&n,&rt);
	for(i=1;i<=n;i=i+1)
		scanf("%d",a+i);
	for(i=1;i<n;i=i+1){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(rt,0);
	build(1,1,n);
	scanf("%d",&m);
	z=0;
	for(i=1;i<=m;i=i+1){
		scanf("%d%d",&x,&y);
		x=(x+z)%n+1;
		y=(y+z)%n;
		//cout<<x<<tin[x]<<tout[x]<<d[x]<<y<<endl;
		z=query(1,1,n,tin[x],tout[x],d[x]+y);
		printf("%d\n",z);
	}
	return 0;
}