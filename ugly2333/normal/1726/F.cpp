//CF1726F
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
const int N = 1<<18;
const int M = 1<<23;
int n,m,g[N],c[N];
int tot,rt,ls[M],rs[M];
LL t[M],w[M];
void ch(int&k,LL X,int r){
	if(!k)
		k=++tot;
	w[k]=X;
	if(X==-2)
		t[k]=r;
	else
		t[k]=X;
}
void pd(int k,int h,int r){
	if(w[k]!=-1){
		ch(ls[k],w[k],h);
		ch(rs[k],w[k],r);
		w[k]=-1;
	}
}
void pu(int k){
	t[k]=t[rs[k]];
}
void modify(int&k,int L,int R,LL X,int l=0,int r=m-1){
	//if(k==rt)
	//	cout<<L<<R<<' '<<X<<endl;
	if(L<=l&&r<=R){
		ch(k,X,r);
		return;
	}
	int h=l+r>>1;
	pd(k,h,r);
	if(L<=h)
		modify(ls[k],L,R,X,l,h);
	if(h<R)
		modify(rs[k],L,R,X,h+1,r);
	pu(k);
}
int query(int k,LL X,int l=0,int r=m-1){
	if(w[k]!=-1){
		if(w[k]==-2){
			if(r>=X)
				return max((int)X,l);
			return m;
		}
		if(w[k]>=X)
			return l;
		return m;
	}
	int h=l+r>>1;
	if(t[ls[k]]>=X)
		return query(ls[k],X,l,h);
	return query(rs[k],X,h+1,r);
}
LL ans;
void dfs(int k,int l=0,int r=m-1){
	if(w[k]!=-1){
		if(w[k]==-2)
			ans=0;
		else
			ans=min(ans,w[k]-r);
		//cout<<l<<r<<' '<<w[k]<<endl;
		return;
	}
	int h=l+r>>1;
	dfs(ls[k],l,h);
	dfs(rs[k],h+1,r);
}
int main()
{
	int i,x,y,s;
	LL p,d,ss;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d%d",g+i,c+i);
	s=0;
	ss=0;
	for(i=2;i<=n;i++){
		scanf("%d",&x);
		s=(s+x)%m;
		ss+=x;
		c[i]=(c[i]+s)%m;
	}
	ch(rt,-2,m-1);
	for(i=1;i<=n;i++){
		d=c[i];
		p=t[rt]+d;//cout<<i<<' '<<d<<' '<<p<<endl;
		if(p%m<g[i]){
			x=query(rt,p-p%m-d);
			y=query(rt,p-p%m-m+g[i]-d);
			if(y<x)
				modify(rt,y,x-1,p-p%m-d);
		}
		else{
			x=query(rt,p-p%m+g[i]-d);
			y=query(rt,p-p%m-d);
			if(0<y)
				modify(rt,0,y-1,p-p%m-d);
			if(x<m)
				modify(rt,x,m-1,p-p%m+m-d);
		}
	}
	ans=1e18;
	dfs(rt);
	printf("%lld\n",ans+ss);
	return 0;
}