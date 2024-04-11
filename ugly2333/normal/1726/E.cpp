//CF1726E
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
const int N = 1<<20;
const int MO = 998244353;
int ad(int x,int y){
	x+=y;
	if(x>=MO)
		x-=MO;
	return x;
}
int mul(int x,int y){
	return (LL)x*y%MO;
}
int fpow(int x,int y=MO-2){
	if(!y)
		return 1;
	int z=fpow(x,y>>1);
	z=mul(z,z);
	if(y&1)
		return mul(z,x);
	return z;
}
void DFT(int C[],int n,int fl){
	int i,j,k,l;
	int u,v,w,cur;
	i=n>>1;
	for(j=1;j<n;j=j+1){
		if(i<j)
			swap(C[i],C[j]);
		for(k=n>>1;i&k;k>>=1)
			i^=k;
		i^=k;
	}
	for(l=2;l<=n;l<<=1){
		w=fpow(3,(MO-1)/l);
		if(fl==-1)
			w=fpow(w);
		for(i=0;i<n;i=i+l){
			cur=1;
			for(j=i;j<i+(l>>1);j=j+1){
				u=C[j],v=mul(C[j+(l>>1)],cur);
				C[j]=ad(u,v),C[j+(l>>1)]=ad(u,MO-v);
				cur=mul(cur,w);
			}
		}
	}
}
int m,A[N],B[N],C[N];
void FFT(){
	int i,l,o;
	for(l=1;l<m+m;l<<=1);
	DFT(A,l,1);
	DFT(B,l,1);
	for(i=0;i<l;i=i+1)
		C[i]=mul(A[i],B[i]);
	DFT(C,l,-1);
	o=fpow(l);
	for(i=0;i<l;i=i+1)
		C[i]=mul(C[i],o),A[i]=0,B[i]=0;
}
int n,f[N],g[N],hh[N],*h=hh+10;
int main()
{
	int T,i,x,y;
	n=300005;
	f[0]=1;
	for(i=1;i<=n;i++)
		f[i]=mul(f[i-1],i);
	g[n]=fpow(f[n]);
	for(i=n;i>=1;i--)
		g[i-1]=mul(g[i],i);
	h[-1]=1;
	for(i=1;i<=n;i+=2)
		h[i]=mul(h[i-2],i);
	for(i=0;i<=n;i+=2)
		A[i]=mul(g[i],h[i-1]);
	for(i=0;i<=n;i++)
		B[i]=g[i];
	m=n+1;
	FFT();
	for(i=0;i<=n;i++)
		C[i]=mul(C[i],f[i]);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		x=0;
		y=1;
		for(i=0;i*4<=n;i++){
			x=ad(x,mul(y,mul(mul(f[n-i*2],mul(g[i*2],g[n-i*4])),mul(h[i*2-1],C[n-i*4]))));
			y=mul(y,2);
		}
		printf("%d\n",x);
	}
	return 0;
}