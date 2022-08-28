//CF 8C
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
const int N = 24;
const int M = 1<<12;
int n,x[N],y[N],z[N],a[N][N],ans[N];
int nn,bb,cc,b[N],c[N];
int m,f[M],g[M];
int main()
{
	srand(19260817);
	int i,j,xx,yy,r,s,q,t;
	cin>>xx>>yy>>n;
	s=0;
	for(i=0;i<n;i=i+1){
		cin>>x[i]>>y[i];
		x[i]-=xx,y[i]-=yy;
		z[i]=x[i]*x[i]+y[i]*y[i];
		s+=z[i]+z[i];
	}
	for(i=0;i<n;i=i+1)
		for(j=0;j<n;j=j+1){
			if(i==j)
				continue;
			xx=x[i]-x[j],yy=y[i]-y[j];
			r=xx*xx+yy*yy;
			a[i][j]=max(0,z[i]+z[j]-r);
		}
	nn=n/2;
	r=0;
	q=2333;
	while(q--){
		do{
			t=rand()*rand()%(1<<n);
			bb=0,cc=0;
			for(i=0;i<n;i=i+1){
				if(t&(1<<i))
					c[cc++]=i;
				else
					b[bb++]=i;
			}
		}while(bb!=nn);
		yy=0;
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		m=(1<<cc)-1;
		for(i=1;i<=m;i=i+1){
			xx=0;
			for(j=0;j<cc;j=j+1)
				if(i&(1<<j))
					xx++;
			if(xx>bb)
				continue;
			xx=b[xx-1];
			for(j=0;j<cc;j=j+1){
				if(i&(1<<j))
					if(f[i]<f[i^(1<<j)]+a[xx][c[j]]){
						f[i]=f[i^(1<<j)]+a[xx][c[j]];
						g[i]=j;
					}
			}
			if(xx==b[bb-1]&&r<f[i]){
				r=f[i];
				yy=i;
			}
		}
		if(yy){
			memset(ans,0,sizeof(ans));
			xx=yy;
			for(j=bb-1;j>=0;j=j-1){
				if(a[b[j]][c[g[xx]]]){
					ans[b[j]]=c[g[xx]];
					ans[c[g[xx]]]=b[j];
				}
				xx=xx^(1<<g[xx]);
			}
		}
	}
	cout<<s-r<<endl<<0;
	for(i=0;i<n;i=i+1){
		if(ans[i]<0)
			continue;
		cout<<' '<<i+1;
		if(ans[i]){
			cout<<' '<<ans[i]+1;
			ans[ans[i]]=-1;
		}
		cout<<' '<<0;
	}
	return 0;
}