//CF 827E
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
const int N = 1<<21;
const DB pi = 3.14159265358979;
struct complex{
	DB x,y;
	complex(DB xx=0.0,DB yy=0.0){
		x=xx,y=yy;
	}
}A[N],B[N];
complex operator+(complex a,complex b){
	return complex(a.x+b.x,a.y+b.y);
}
complex operator-(complex a,complex b){
	return complex(a.x-b.x,a.y-b.y);
}
complex operator*(complex a,complex b){
	return complex(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);
}
complex operator/(complex a,DB d){
	return complex(a.x/d,a.y/d);
}
void DFT(complex C[],int n,int fl){
	complex u,v,w,cur;
	int i,j,k;
	i=n>>1;
	for(j=1;j<n;j=j+1){
		if(i<j)
			swap(C[i],C[j]);
		for(k=n>>1;i&k;k>>=1)
			i^=k;
		i^=k;
	}
	for(i=1;i<n;i<<=1){
		w=complex(cos(pi/i),sin(pi*fl/i));
		for(j=0;j<n;j=j+i+i){
			cur=complex(1.0,0.0);
			for(k=j;k<j+i;k=k+1){
				u=C[k],v=C[k+i]*cur;
				C[k]=u+v,C[k+i]=u-v;
				cur=cur*w;
			}
		}
	}
}
int n,a[N],b[N],c[N];
void FFT(){
	int i,l;
	for(l=1;l<n+n;l<<=1);
	for(i=0;i<l;i=i+1){
		A[i]=complex(a[i],0.0);
		B[i]=complex(b[i],0.0);
	}
	DFT(A,l,1);
	DFT(B,l,1);
	for(i=0;i<l;i=i+1)
		A[i]=A[i]*B[i];
	DFT(A,l,-1);
	for(i=0;i<l;i=i+1)
		c[i]=(int)(A[i].x/l+0.5);
}
int p[N];
char ch[N];
int main()
{
	int T,i,j,s;
	scanf("%d",&T);
	while(T--){
		scanf("%d%s",&n,ch);
		for(i=0;i<n;i=i+1){
			if(ch[i]=='V')
				a[i]=1;
			if(ch[i]=='K')
				b[n-1-i]=1;
		}
		FFT();
		for(i=0;i<n;i=i+1)
			if(c[i])
				p[n-1-i]=1;
		for(i=n;i<n+n;i=i+1)
			if(c[i])
				p[i-n+1]=1;
		s=0;
		for(i=1;i<=n;i=i+1){
			for(j=i;j<=n;j=j+i)
				if(p[j])
					break;
			if(j>n)
				s++;
			else
				p[i]=1;
		}
		printf("%d\n",s);
		for(i=1;i<=n;i=i+1)
			if(!p[i])
				printf("%d ",i);
		printf("\n");
		for(i=0;i<=n;i=i+1)
			a[i]=0,b[i]=0,c[i]=0,p[i]=0;
	}
	return 0;
}