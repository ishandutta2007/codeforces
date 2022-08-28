//CF1641E
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
const int MO = 998244353;
int AD(int x,int y){
	x+=y;
	if(x>=MO)
		return x-MO;
	return x;
}
void ad(int&x,int y){
	x+=y;
	if(x>=MO)
		x-=MO;
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
				C[j]=AD(u,v),C[j+(l>>1)]=AD(u,MO-v);
				cur=mul(cur,w);
			}
		}
	}
}
int len,A[N],B[N],C[N];
void bf(){
	int i,j;
	for(i=0;i<len*2;i++)
		C[i]=0;
	for(i=0;i<len;i++)
		for(j=0;j<len;j++)
			ad(C[i+j],mul(A[i],B[j]));
	for(i=0;i<len;i++)
		A[i]=0,B[i]=0;
}
void FFT(){
	if(len<100){
		bf();
		return;
	}
	int i,l,o;
	for(l=1;l<len*2;l<<=1);
	DFT(A,l,1);
	DFT(B,l,1);
	for(i=0;i<l;i=i+1)
		C[i]=mul(A[i],B[i]);
	DFT(C,l,-1);
	o=fpow(l);
	for(i=0;i<l;i=i+1)
		C[i]=mul(C[i],o),A[i]=0,B[i]=0;
}
int n,m,s,a[N],b[N],c[N],dl[N],dr[N],e[N],p2[N];
void solve(int l,int r){
	if(l==r){
		if(e[l]){
			ad(s,mul(p2[dr[l]],mul(l,b[l])+MO-c[l]));
			ad(s,mul(p2[dl[l]],c[n]+MO-c[l]));
			ad(s,mul(p2[dl[l]],mul(MO-l,b[n]+MO-b[l])));
		}
		return;
	}
	int h=l+r>>1,i;
	solve(l,h);
	len=r-l;
	
	for(i=l+h+1;i<=h+r;i++)
		A[i-l-h-1]=mul(2,c[i/2]);
	for(i=l;i<=h;i++)
		if(e[i])
			B[-i+h]=p2[dl[i]];
	FFT();
	for(i=h+1;i<=r;i++)
		if(e[i])
			ad(s,mul(p2[dr[i]],C[i-l-1]));
	
	for(i=l+h+1;i<=h+r;i++)
		A[i-l-h-1]=1;
	for(i=l;i<=h;i++)
		if(e[i])
			B[-i+h]=mul(p2[dl[i]],mul(i,b[i])+MO-c[i]);
	FFT();
	for(i=h+1;i<=r;i++)
		if(e[i])
			ad(s,mul(p2[dr[i]],C[i-l-1]));
	
	for(i=l+h+1;i<=h+r;i++)
		A[i-l-h-1]=1;
	for(i=l;i<=h;i++)
		if(e[i])
			B[-i+h]=p2[dl[i]];
	FFT();
	for(i=h+1;i<=r;i++)
		if(e[i])
			ad(s,mul(p2[dr[i]],mul(C[i-l-1],mul(i,b[i])+MO-c[i])));
	
	for(i=l+h+1;i<=h+r;i++)
		A[i-l-h-1]=b[i/2];
	for(i=l;i<=h;i++)
		if(e[i])
			B[-i+h]=mul(p2[dl[i]],MO-i);
	FFT();
	for(i=h+1;i<=r;i++)
		if(e[i])
			ad(s,mul(p2[dr[i]],C[i-l-1]));
	
	for(i=l+h+1;i<=h+r;i++)
		A[i-l-h-1]=b[i/2];
	for(i=l;i<=h;i++)
		if(e[i])
			B[-i+h]=p2[dl[i]];
	FFT();
	for(i=h+1;i<=r;i++)
		if(e[i])
			ad(s,mul(p2[dr[i]],mul(C[i-l-1],MO-i)));
	
	solve(h+1,r);
}
int main()
{
	int i,x;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",a+i),b[i]=a[i],c[i]=mul(a[i],i);
	for(i=1;i<=n;i++)
		ad(b[i],b[i-1]),ad(c[i],c[i-1]);
	p2[0]=1;
	for(i=1;i<=n;i++)
		p2[i]=mul(p2[i-1],2);
	for(i=1;i<=m;i++)
		scanf("%d",&x),e[x]=1;
	for(i=1;i<=n;i++)
		dl[i]=dl[i-1]+e[i-1];
	for(i=n;i>=1;i--)
		dr[i]=dr[i+1]+e[i+1];
	solve(1,n);
	x=p2[m]-1;
	s=mul(s,fpow(x));
	printf("%d\n",s);
	return 0;
}