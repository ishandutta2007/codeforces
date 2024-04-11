//CF 286E
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
const int N = 1<<22;
const DB pi = 3.14159265358979;
struct complex{
	DB x,y;
	complex(DB xx=0.0,DB yy=0.0){
		x=xx,y=yy;
	}
}C[N];
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
void FFT(int n,int fl){
	int i,j,k,l;
	complex u,v,w,cur;
	i=n>>1;
	for(j=1;j<n;j=j+1){
		if(i<j)
			swap(C[i],C[j]);
		for(k=n>>1;i&k;k>>=1)
			i^=k;
		i^=k;
	}
	for(l=2;l<=n;l<<=1){
		w=complex(cos(2.0*pi/l),sin(2.0*pi*fl/l));
		for(i=0;i<n;i=i+l){
			cur=complex(1.0,0.0);
			for(j=i;j<i+(l>>1);j=j+1){
				u=C[j],v=C[j+(l>>1)]*cur;
				C[j]=u+v,C[j+(l>>1)]=u-v;
				cur=cur*w;
			}
		}
	}
}
int n,m,a[N],f[N];
LL b[N];
void solve(){
	int i,l;
	for(l=1;l<m+m;l<<=1);
	for(i=0;i<l;i=i+1)
		C[i]=complex(b[i],0.0);
	FFT(l,1);
	for(i=0;i<l;i=i+1)
		C[i]=C[i]*C[i];
	FFT(l,-1);
	for(i=0;i<m;i=i+1){
		b[i]=(LL)(C[i].x+0.5)/l;
		if(i){
			if(b[i]!=2)
				f[i]=0;
			else
				b[i]>>=1;
		}
	}
}
int main()
{
	int i,x,s=0;
	scanf("%d%d",&n,&m);
	m++;
	b[0]=1;
	for(i=1;i<=n;i=i+1){
		scanf("%d",&x);
		a[x]=1;
		b[x]=1;
		f[x]=1;
	}
	//for(i=1;i<=20;i=i+1)
		solve();
	for(i=1;i<m;i=i+1){
		if(!a[i]&&b[i]){
			cout<<"NO\n";
			return 0;
		}
		s+=f[i];
	}
	printf("YES\n%d\n",s);
	for(i=1;i<=m;i=i+1)
		if(f[i])
			printf("%d ",i);
	return 0;
}