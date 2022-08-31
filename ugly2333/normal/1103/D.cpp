//CF1103D
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
const int N = 1e6+16;
const int M = 22;
const LL inf = 1e18;
LL gcd(LL x,LL y){
	if(!y)
		return x;
	return gcd(y,x%y);
}
LL Q(LL x,LL y){
	LL t=x;
	while(t%y==0){
		t/=y;
	}
	return x/t;
}
int n,m,w,b[N];
LL k,g,a[N],e[N],c[N],d[2222],f[M][2222],h[M][2222],r[M][2222],rr[M][2222];
LL p[M];
map<LL,int> E;
vector<LL> v[N];int main()
{
	int i,j,l,o,t;
	LL x,gg,u;
	scanf("%d%lld",&n,&k);
	g=0;
	for(i=1;i<=n;i=i+1)
		scanf("%lld",a+i),g=gcd(g,a[i]);
	for(i=1;i<=n;i=i+1)
		scanf("%d",e+i);
	gg=g;
	for(x=2;x*x<=g;x=x+1){
		if(g%x)
			continue;
		p[m]=x;
		while(g%x==0){
			g/=x;
		}
		m++;
	}
	if(g>1){
		p[m]=g;
		m++;
	}
	g=gg;
	for(i=1;i<=n;i=i+1){
		x=1;
		while(1){
			u=gcd(g,a[i]);
			a[i]/=u;
			x*=u;
			if(u==1)
				break;
		}
		a[i]=x;
		if(E.find(a[i])!=E.end())
			b[i]=E[a[i]];
		else{
			E[a[i]]=++w;
			b[i]=w;
			c[w]=a[i];
		}
		v[b[i]].push_back(e[i]);
	}
	for(i=0;i<=m;i=i+1)
		for(j=0;j<(1<<m);j=j+1)
			r[i][j]=inf;
	r[0][0]=0;
	for(i=1;i<=w;i=i+1){
		sort(v[i].begin(),v[i].end());
		d[0]=1;
		for(j=0;j<m;j=j+1)
			d[1<<j]=Q(c[i],p[j]);
		for(j=1;j<(1<<m);j=j+1)
			d[j]=d[j&-j]*d[j^(j&-j)];
		for(j=0;j<(1<<m);j=j+1)
			f[0][j]=inf,h[0][j]=0;
		f[0][0]=0;
		h[0][0]=1;
		for(o=0;o<m&&o<v[i].size();o=o+1){
			for(j=0;j<(1<<m);j=j+1)
				f[o+1][j]=inf,h[o+1][j]=0;
			for(j=0;j<(1<<m);j=j+1)
				if(h[o][j]){
					for(l=j;l<(1<<m);l=(l+1)|j)
						if(d[l^j]<=k&&f[o+1][l]>f[o][j]+v[i][o])
							f[o+1][l]=f[o][j]+v[i][o],h[o+1][l]=1;
				}
		}
		for(o=0;o<=m;o=o+1)
			for(j=0;j<(1<<m);j=j+1)
				rr[o][j]=inf;
		for(o=1;o<=m&&o<=v[i].size();o=o+1){
			for(j=0;j<(1<<m);j=j+1)
				if(h[o][j]){
					for(t=0;t+o<=m;t=t+1){
						for(l=j;l<(1<<m);l=(l+1)|j)
							if(rr[t+o][l]>r[t][l^j]+f[o][j])
								rr[t+o][l]=r[t][l^j]+f[o][j];
					}
				}
		}
		for(o=0;o<=m;o=o+1)
			for(j=0;j<(1<<m);j=j+1)
				r[o][j]=min(r[o][j],rr[o][j]);
	}
	x=inf;
	for(i=0;i<=m;i=i+1){
		if(r[i][(1<<m)-1]<inf)
			x=min(x,(LL)r[i][(1<<m)-1]*i);
	}
	if(x>=inf)
		x=-1;
	cout<<x;
	return 0;
}