//CF 150E
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
const pair<int,int> P = make_pair(-N,-1);
int n,l,r;
int v[N+N],w[N+N],tw[N+N],pr[N+N],la[N];
pair<int,int> p[N],pp;
int t[N],ms[N],isc[N];
int ansx,ansy,sq;
pair<int,int> ans[N],q[N],T[N<<2];
void adde(int i,int x,int y,int z){
	v[i]=y;
	w[i]=z;
	pr[i]=la[x];
	la[x]=i;
}
void dfsu(int u,int fa){
	int i,x;
	t[u]=1,ms[u]=0;
	for(i=la[u];i;i=pr[i]){
		x=v[i];
		if(x==fa||isc[x])
			continue;
		dfsu(x,u);
		t[u]+=t[x];
		ms[u]=max(ms[u],t[x]);
	}
}
pair<int,int> fndc(int u,int fa,int tt){
	int i,x;
	pair<int,int> res;
	res=make_pair(max(ms[u],tt-t[u]),u);
	for(i=la[u];i;i=pr[i]){
		x=v[i];
		if(x==fa||isc[x])
			continue;
		res=min(res,fndc(x,u,tt));
	}
	return res;
}
void dfsc(int u,int fa,int dep,int sw){
	int i,x;
	pp=make_pair(sw,u);
	if(sq<dep)
		q[++sq]=pp;
	if(q[dep]<pp)
		q[dep]=pp;
	for(i=la[u];i;i=pr[i]){
		x=v[i];
		if(x==fa||isc[x])
			continue;
		dfsc(x,u,dep+1,sw+tw[i]);
	}
}
void ini(int k,int l,int r){
	T[k]=P;
	if(l==r)
		return;
	int md;
	md=(l+r)>>1;
	ini(k<<1,l,md);
	ini(k<<1|1,md+1,r);
}
void modify(int k,int l,int r,int p,pair<int,int> v){
	//cout<<k<<l<<r<<p<<v.first<<T[k].first;
	if(T[k]<v)
		T[k]=v;
	//cout<<T[k].first<<endl;
	if(l==r)
		return;
	int md;
	md=(l+r)>>1;
	if(p<=md)
		modify(k<<1,l,md,p,v);
	else
		modify(k<<1|1,md+1,r,p,v);
	//T[k]=max(T[k<<1],T[k<<1|1]);
}
pair<int,int> query(int k,int l,int r,int L,int R){
	//cout<<k<<l<<r<<L<<R<<' '<<T[k].first<<endl;
	if(r<L||R<L||R<l)
		return P;
	if(L<=l&&r<=R)
		return T[k];
	int md;
	pair<int,int> res;
	md=(l+r)>>1;
	res=P;
	if(L<=md)
		res=max(res,query(k<<1,l,md,L,R));
	if(md<R)
		res=max(res,query(k<<1|1,md+1,r,L,R));
	//cout<<k<<pp.first<<endl;
	return res;
}
bool solve(int u){
	
	int i,j,x,c,tt;
	dfsu(u,0);
	tt=t[u];
	pp=fndc(u,0,tt);
	tt=pp.first;
	c=pp.second;
	if(t[u]<l||tt+tt<l)
		return 0;
	isc[c]=1;
	//cout<<"solve "<<u<<' '<<c<<' '<<tt<<endl;
	for(i=la[c];i;i=pr[i]){
		x=v[i];
		if(isc[x])
			continue;
		//cout<<c<<x<<endl;
		if(solve(x)){
			isc[c]=0;
			return 1;
		}
	}
	for(i=0;i<=tt;i=i+1)
		ans[i].first=-N;
	ini(1,0,tt);
	ans[0]=make_pair(0,c);
	modify(1,0,tt,0,ans[0]);
	//cout<<tt<<query(1,0,tt,0,1).first<<endl;
	for(i=la[c];i;i=pr[i]){
		x=v[i];
		if(isc[x])
			continue;
		sq=0;
		dfsc(x,c,1,tw[i]);
		for(j=1;j<=sq;j=j+1){
			if(l-j>tt||r-j<0)
				continue;
			pp=query(1,0,tt,max(0,l-j),min(tt,r-j));
			//cout<<q[j].first<<' '<<max(0,l-j)<<' '<<min(tt,r-j)<<' '<<pp.first<<endl;
			if(pp.first+q[j].first>=0){
				ansx=pp.second;
				ansy=q[j].second;
				isc[c]=0;
				return 1;
			}
		}
		//cout<<u<<' '<<c<<' '<<x<<' '<<sq<<endl<<endl;
		for(j=1;j<=sq;j=j+1)
			if(q[j]>ans[j])
				ans[j]=q[j],modify(1,0,tt,j,q[j]);
	}
	isc[c]=0;
	return 0;
}
int main()
{
	int i,x,y,z;
	scanf("%d%d%d",&n,&l,&r);
	for(i=1;i<n;i=i+1){
		scanf("%d%d%d",&x,&y,&z);
		adde(i,x,y,z);
		adde(i+n,y,x,z);
		p[i]=make_pair(z,i);
	}
	sort(p+1,p+n);
	//for(i=1;i<n;i=i+1) cout<<p[i].first;
	x=1,z=n-1;
	while(x<=z){
		y=(x+z+1)>>1;
		for(i=1;i<n;i=i+1){
			if(w[i]>=p[y].first)
				tw[i]=1;
			else
				tw[i]=-1;
			//cout<<tw[i]<<' ';
			tw[i+n]=tw[i];
		}
		//cout<<"xyzw= "<<x<<y<<z<<' '<<p[y].first<<endl;
		if(x==z){
			solve(1);
			cout<<ansx<<' '<<ansy<<endl;
			return 0;
		}
		if(solve(1))
			x=y;//,cout<<ansx<<ansy<<endl;
		else
			z=y-1;
	}
	return 0;
}
/*
20 4 9
4 8 8
18 19 0
14 20 4
2 11 2
10 8 0
6 10 4
9 14 7
3 14 9
13 18 4
16 20 0
17 7 3
11 19 1
15 7 4
5 3 7
12 14 2
19 14 7
8 20 6
1 9 0
7 19 4

*/