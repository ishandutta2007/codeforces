//CF 715C
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
const int N = 1e5+15;
const int T = 10;
int pw[N],inv[N];
int n,m;
int tot,v[N+N],h[N+N],pr[N+N],la[N];
int isc[N],t[N],mt[N];
vector<int> g[N],cur;
LL ans;
void adde(int x,int y,int z){
	v[++tot]=y;
	h[tot]=z;
	pr[tot]=la[x];
	la[x]=tot;
}
void sortv(vector<int>& vv){
	sort(vv.begin(),vv.end());
}
int cnt(vector<int>& vv,int x){
	return upper_bound(vv.begin(),vv.end(),x)-lower_bound(vv.begin(),vv.end(),x);
}
void gett(int u,int fa){
	int i,x;
	t[u]=1,mt[u]=0;
	for(i=la[u];i;i=pr[i]){
		x=v[i];
		if(x==fa||isc[x])
			continue;
		gett(x,u);
		t[u]+=t[x];
		mt[u]=max(mt[u],t[x]);
	}
}
pair<int,int> fndc(int u,int fa,int tt){
	pair<int,int> res;
	int i,x,mx;
	res=make_pair(max(tt-t[u],mt[u]),u);
	for(i=la[u];i;i=pr[i]){
		x=v[i];
		if(x==fa||isc[x])
			continue;
		res=min(res,fndc(x,u,tt));
	}
	return res;
}
void dfs1(int u,int fa,int dep,LL val,vector<int>& vv){
	
	int i,x,y;
	val%=m;
	cur.push_back(val);
	vv.push_back(val);
	for(i=la[u];i;i=pr[i]){
		x=v[i],y=h[i];
		if(x==fa||isc[x])
			continue;
		dfs1(x,u,dep+1,(LL)y*pw[dep]+val,vv);
	}
}
void dfs2(int u,int fa,int dep,LL val,vector<int>& vv){
	
	int i,x,y;
	LL t;
	val%=m;
	t=(LL)(m-val)*inv[dep]%m;
	//cout<<u<<' '<<fa<<' '<<dep<<' '<<val<<endl;
	ans+=cnt(cur,t);
	ans-=cnt(vv,t);
	for(i=la[u];i;i=pr[i]){
		x=v[i],y=h[i];
		if(x==fa||isc[x])
			continue;
		dfs2(x,u,dep+1,(LL)val*10+y,vv);
	}
}
void solve(int u){
	int i,x,y;
	gett(u,0);
	//cout<<t[u];
	u=fndc(u,0,t[u]).second;
	//cout<<u<<endl;
	isc[u]=1;
	for(i=la[u];i;i=pr[i]){
		x=v[i];
		if(isc[x])
			continue;
		solve(x);
	}
	cur.clear();
	cur.push_back(0);
	for(i=la[u];i;i=pr[i]){
		x=v[i],y=h[i];
		if(isc[x])
			continue;
		g[x].clear();
		dfs1(x,u,1,y,g[x]);
	}
	sortv(cur);
	ans+=cnt(cur,0)-1;
	for(i=la[u];i;i=pr[i]){
		x=v[i],y=h[i];
		if(isc[x])
			continue;
		sortv(g[x]);
		dfs2(x,u,1,y,g[x]);
	}
	isc[u]=0;
}
int main()
{
	int i,x,y,z;
	scanf("%d%d",&n,&m);
	for(i=1;i<T;i=i+1)
		if((LL)i*m%T==T-1)
			x=((LL)i*m+1)/T;
	//cout<<x<<endl;
	pw[0]=1,inv[0]=1;
	for(i=1;i<=n;i=i+1){
		pw[i]=(LL)pw[i-1]*T%m;
		inv[i]=(LL)inv[i-1]*x%m;
	}
	for(i=1;i<n;i=i+1){
		scanf("%d%d%d",&x,&y,&z);
		x++,y++;
		adde(x,y,z);
		adde(y,x,z);
	}
	solve(1);
	cout<<ans<<endl;
	return 0;
}
/*
6 7
0 1 2
4 2 4
2 0 1
3 0 9
2 5 7

7
*/