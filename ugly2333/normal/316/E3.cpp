//CF 316E
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
typedef double DB;
const int N = 222222;
const int mod = 1e9;
int ADD(int& x,int y){
	x+=y;
	if(x>=mod)
		x-=mod;
	if(x<0)
		x+=mod;
}
int add(int x,int y){
	if(x+y<mod)
		return x+y;
	return x+y-mod;
}
int mul(int x,int y){
	return (LL)x*y%mod;
}
struct node{
	int w;
	int s0;
	int s1;
}T[N<<2];
int n,m,f[N],sf[N],ff[N];
void upd(int k,int t,int D){
	ADD(T[k].w,D);
	ADD(T[k].s0,mul(D,sf[t]));
	ADD(T[k].s1,mul(D,sf[t+1]-1));
}
void modify(int L,int R,int D,int k=1,int l=1,int r=n){
	if(L<=l&&r<=R){
		upd(k,r-l,D);
		return;
	}
	int h=l+r>>1;
	if(T[k].w){
		upd(k<<1,h-l,T[k].w);
		upd(k<<1|1,r-h-1,T[k].w);
		T[k].w=0;
	}
	if(L<=h)
		modify(L,R,D,k<<1,l,h);
	if(h<R)
		modify(L,R,D,k<<1|1,h+1,r);
	//cout<<k<<l<<r<<T[k].s0<<T[k].s1<<(k<<1|1)<<T[3].s1<<endl;
	T[k].s0=add(T[k<<1].s0,add(mul(T[k<<1|1].s0,ff[h-l+1]),mul(T[k<<1|1].s1,ff[h-l+2])));
	T[k].s1=add(T[k<<1].s1,add(mul(T[k<<1|1].s0,ff[h-l+2]),mul(T[k<<1|1].s1,ff[h-l+3])));
	
}
int query(int L,int R,int k=1,int l=1,int r=n){
	if(L<=l&&r<=R)
		return add(mul(T[k].s0,ff[l-L]),mul(T[k].s1,ff[l-L+1]));
	int h=l+r>>1,res=0;
	if(T[k].w){
		upd(k<<1,h-l,T[k].w);
		upd(k<<1|1,r-h-1,T[k].w);
		T[k].w=0;
	}
	if(L<=h)
		ADD(res,query(L,R,k<<1,l,h));
	if(h<R)
		ADD(res,query(L,R,k<<1|1,h+1,r));
	return res;
}
int main()
{
	int i,x,y,z;
	n=2e5+10;
	f[0]=1,f[1]=1;
	for(i=2;i<=n;i=i+1)
		f[i]=add(f[i-1],f[i-2]);
	sf[0]=1;
	for(i=1;i<=n;i=i+1)
		sf[i]=add(sf[i-1],f[i]);
	ff[0]=1,ff[1]=0;
	for(i=2;i<=n;i=i+1)
		ff[i]=add(ff[i-1],ff[i-2]);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i=i+1){
		scanf("%d",&x);
		modify(i,i,x);
	}
	while(m--){
		scanf("%d%d%d",&i,&x,&y);
		if(i==3)
			scanf("%d",&z);
		if(i==1){
			z=y-query(x,x);
			if(z<0)
				z+=mod;
			y=x;
			i=3;
		}
		if(i==2)
			printf("%d\n",query(x,y));
		if(i==3)
			modify(x,y,z);
	}
	return 0;
}