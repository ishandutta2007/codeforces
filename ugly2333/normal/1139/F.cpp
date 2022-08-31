//CF1139F
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
const int W = 1<<23;
const int inf = 1e9;
int n,m,p[N],s[N],b[N],a[N],r[N],e[N];
pair<int,int> c[N+N];
int tot,wl,wr,rt,ls[W],rs[W],t[W];
void modify(int&k,int L,int R,int l=wl,int r=wr){
	if(!k){
		k=++tot;
		ls[k]=0,rs[k]=0,t[k]=0;
	}
	if(L<=l&&r<=R){
		t[k]++;
		return;
	}
	LL h=(LL)l+r;
	h/=2;
	if(L<=h)
		modify(ls[k],L,R,l,h);
	if(h<R)
		modify(rs[k],L,R,h+1,r);
}
int query(int k,int p,int l=wl,int r=wr){
	if(!k)
		return 0;
	if(l==r)
		return t[k];
	LL h=(LL)l+r;
	h/=2;
	if(p<=h)
		return query(ls[k],p,l,h)+t[k];
	return query(rs[k],p,h+1,r)+t[k];
}
int main()
{
	int i,x,y,o;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i=i+1)
		scanf("%d",p+i);
	for(i=1;i<=n;i=i+1)
		scanf("%d",s+i);
	for(i=1;i<=n;i=i+1)
		scanf("%d",b+i);
	for(i=1;i<=m;i=i+1)
		scanf("%d",a+i);
	for(i=1;i<=m;i=i+1)
		scanf("%d",r+i);
	o=0;
	for(i=1;i<=n;i=i+1)
		c[o++]=make_pair(-s[i],-i);
	for(i=1;i<=m;i=i+1)
		c[o++]=make_pair(-a[i],i);
	sort(c,c+o);
	wl=0,wr=2e9;
	tot=0,rt=0;
	y=0;
	for(i=0;i<o;i=i+1){
		x=c[i].second;
		if(x<0){
			x=-x;
			modify(rt,wl,p[x]+b[x]-1);
			y++;
		}
		else{
			e[x]+=y;
			e[x]-=query(rt,a[x]+r[x]);
		}
	}
	tot=0,rt=0;
	for(i=0;i<o;i=i+1){
		x=c[i].second;
		if(x<0){
			x=-x;
			modify(rt,wl,p[x]-b[x]-1+inf);
		}
		else{
			e[x]-=query(rt,a[x]-r[x]+inf);
		}
	}
	o=0;
	for(i=1;i<=n;i=i+1)
		c[o++]=make_pair(-(p[i]+b[i]),i);
	for(i=1;i<=m;i=i+1)
		c[o++]=make_pair(-(a[i]+r[i]),-i);
	sort(c,c+o);
	tot=0,rt=0;
	for(i=0;i<o;i=i+1){
		x=c[i].second;
		if(x>0){
			modify(rt,wl,p[x]-b[x]-1+inf);
		}
		else{
			x=-x;
			e[x]+=query(rt,a[x]-r[x]+inf);
		}
	}
	for(i=1;i<=m;i=i+1)
		printf("%d ",e[i]);
	return 0;
}