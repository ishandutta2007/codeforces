//CF243D
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
const int N = 1111;
const int M = N*N;
const int W = 1<<21;
const int inf = 2e9;
int n,vx,vy,m,e,a[N][N],b[N][N],p[M];
pair<int,int> q[M];
int t[W],w[W];
void ch(int k,int x){
	t[k]=x,w[k]=x;
}
void pd(int k){
	if(w[k]>=0){
		ch(k<<1,w[k]);
		ch(k<<1|1,w[k]);
		w[k]=-1;
	}
}
void pu(int k){
	t[k]=min(t[k<<1],t[k<<1|1]);
	if(w[k<<1]==w[k<<1|1])
		w[k]=w[k<<1];
	else
		w[k]=-1;
}
void modify(int L,int R,int V,int k=1,int l=0,int r=m){
	if(t[k]>=V)
		return;
	if(L<=l&&r<=R&&w[k]>=0){
		ch(k,V);
		return;
	}
	pd(k);
	int h=l+r>>1;
	if(L<=h)
		modify(L,R,V,k<<1,l,h);
	if(h<R)
		modify(L,R,V,k<<1|1,h+1,r);
	pu(k);
}
int query(int L,int R,int k=1,int l=0,int r=m){
	if(L<=l&&r<=R)
		return t[k];
	if(w[k]>=0)
		return w[k];
	int h=l+r>>1,o=inf;
	if(L<=h)
		o=min(o,query(L,R,k<<1,l,h));
	if(h<R)
		o=min(o,query(L,R,k<<1|1,h+1,r));
	return o;
}
int main()
{
	int i,j,o,x;
	LL s=0;
	scanf("%d%d%d",&n,&vx,&vy);
	for(i=1;i<=n;i=i+1)
		for(j=1;j<=n;j=j+1)
			scanf("%d",a[i]+j);
	if(vx<0){
		for(i=1;i<n+1-i;i=i+1)
			for(j=1;j<=n;j=j+1)
				swap(a[i][j],a[n+1-i][j]);
		vx=-vx;
	}
	if(vy<0){
		for(i=1;i<=n;i=i+1)
			for(j=1;j<n+1-j;j=j+1)
				swap(a[i][j],a[i][n+1-j]);
		vy=-vy;
	}
	m=0;
	for(i=0;i<=n;i=i+1)
		for(j=0;j<=n;j=j+1)
			b[i][j]=i*vy-j*vx,p[m++]=b[i][j];
	sort(p,p+m);
	m=unique(p,p+m)-p;
	for(i=0;i<=n;i=i+1)
		for(j=0;j<=n;j=j+1)
			b[i][j]=lower_bound(p,p+m,b[i][j])-p;
	e=0;
	for(i=1;i<=n;i=i+1)
		for(j=1;j<=n;j=j+1)
			q[e++]=make_pair(i*vx+j*vy,i*N+j);
	sort(q,q+e);
	for(o=0;o<e;o=o+1){
		x=q[o].second;
		i=x/N,j=x%N;
		x=query(b[i-1][j],b[i][j-1]-1);
		if(x>=a[i][j])
			continue;
		s+=a[i][j]-x;
		modify(b[i-1][j],b[i][j-1]-1,a[i][j]);
	}
	cout<<s;
	return 0;
}