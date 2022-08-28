//CF1449C
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
const int N = 1<<19;
int n,q,a[N],w[N],f[N];
LL t[N];
void ch(int k,int x,int le){
	w[k]=x;
	f[k]=x;
	t[k]=(LL)x*le;
}
void pd(int k,int le){
	if(!w[k])
		return;
	ch(k<<1,w[k],le-(le>>1));
	ch(k<<1|1,w[k],le>>1);
	w[k]=0;
}
void pu(int k){
	w[k]=0;
	f[k]=f[k<<1|1];
	t[k]=t[k<<1]+t[k<<1|1];
}
void bd(int k=1,int l=1,int r=n){
	if(l==r){
		ch(k,a[l],r-l+1);
		return;
	}
	int h=l+r>>1;
	bd(k<<1,l,h);
	bd(k<<1|1,h+1,r);
	pu(k);
}
void md(int L,int R,int X,int k=1,int l=1,int r=n){
	if(L<=l&&r<=R){
		ch(k,X,r-l+1);
		return;
	}
	int h=l+r>>1;
	pd(k,r-l+1);
	if(L<=h)
		md(L,R,X,k<<1,l,h);
	if(h<R)
		md(L,R,X,k<<1|1,h+1,r);
	pu(k);
}
int lb(LL x,int k=1,int l=1,int r=n){
	if(x<f[k])
		return r+1;
	if(l==r)
		return l;
	int h=l+r>>1;
	pd(k,r-l+1);
	if(f[k<<1]<=x)
		return lb(x,k<<1,l,h);
	else
		return lb(x,k<<1|1,h+1,r);
}
int go(LL x,int k=1,int l=1,int r=n){
	if(x>=t[k])
		return r+1;
	if(l==r)
		return l;
	int h=l+r>>1;
	pd(k,r-l+1);
	if(x<t[k<<1])
		return go(x,k<<1,l,h);
	return go(x-t[k<<1],k<<1|1,h+1,r);
}
LL qu(int p,int k=1,int l=1,int r=n){
	if(p<l)
		return 0;
	if(r<=p)
		return t[k];
	int h=l+r>>1;
	pd(k,r-l+1);
	return qu(p,k<<1,l,h)+qu(p,k<<1|1,h+1,r);
}
int main()
{
	int i,x,y,o,s;
	LL z;
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i=i+1)
		scanf("%d",a+i);
	bd();
	while(q--){
		scanf("%d%d%d",&i,&x,&y);
		if(i==1){
			o=lb(y);
			if(o<=x)
				md(o,x,y);
		}
		else{
			s=0;
			z=y;
			while(1){
				z+=qu(x-1);
				o=go(z);//cout<<z<<' '<<o<<endl;
				s+=o-x;
				if(o>n)
					break;
				z-=qu(o-1);
				x=lb(z);
				if(x>n)
					break;
			}
			printf("%d\n",s);
		}
	}
	return 0;
}