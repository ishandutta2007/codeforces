//CF 277D
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
const int N = 1005;
const DB eps = 1e-13;
const LL T = 1e6;
int n,t,ts[N],tl[N];
LL ss[N],sl[N],pp[N];
DB p[N];
pair<DB,int> a[N];
LL f[N][1566];
DB g[N][1566];
int main()
{
	int i,j,o;
	LL x;
	DB y;
	cin>>n>>t;
	for(i=1;i<=n;i=i+1){
		cin>>ss[i]>>sl[i]>>ts[i]>>tl[i]>>p[i];
		pp[i]=(int)(p[i]*T+0.4);
		if(p[i]==1)
			a[i].first=1e18;
		else
			a[i].first=p[i]*tl[i]/(1.0-p[i]);
		a[i].second=i;
		for(j=0;j<=t;j=j+1)
			g[i][j]=1e9;
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i=i+1){
		o=a[i].second;
		for(j=0;j<=t;j=j+1)
			f[i][j]=f[i-1][j],g[i][j]=g[i-1][j];
		for(j=ts[o];j<=t;j=j+1){
			x=f[i-1][j-ts[o]]+ss[o]*T;
			y=g[i-1][j-ts[o]]+ts[o];
			if(f[i][j]<x||(f[i][j]==x&&g[i][j]>y))
				f[i][j]=x,g[i][j]=y;
		}
		for(j=ts[o]+tl[o];j<=t;j=j+1){
			x=f[i-1][j-ts[o]-tl[o]]+(T-pp[o])*sl[o]+T*ss[o];
			y=p[o]*(g[i-1][j-ts[o]-tl[o]]+ts[o])+(1.0-p[o])*j;
			if(f[i][j]<x||(f[i][j]==x&&g[i][j]>y))
				f[i][j]=x,g[i][j]=y;
		}
	}
	i=n;
	x=0,y=0;
	for(j=0;j<=t;j=j+1)
		if(x<f[i][j]||(x==f[i][j]&&y>g[i][j]))
			x=f[i][j],y=g[i][j];
	printf("%.12lf %.12lf",(DB)x/T,y);
	return 0;
}