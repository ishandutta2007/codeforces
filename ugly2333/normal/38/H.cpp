//CF 38H
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
const int N = 55;
const int inf = 1e9;
int n,m,g1,g2,s1,s2;
int d[N][N],mx[N],mn[N];
int g[N],s[N],b[N];
LL f[N][N][N],ans;
int main()
{
	int i,j,x,y,z;
	cin>>n>>m;
	for(i=1;i<=n;i=i+1)
		for(j=1;j<=n;j=j+1)
			if(i!=j)
				d[i][j]=inf;
	while(m--){
		cin>>x>>y>>z;
		d[x][y]=min(d[x][y],z);
		d[y][x]=min(d[y][x],z);
	}
	cin>>g1>>g2>>s1>>s2;
	for(x=1;x<=n;x=x+1)
		for(i=1;i<=n;i=i+1)
			for(j=1;j<=n;j=j+1)
				d[i][j]=min(d[i][j],d[i][x]+d[x][j]);
	for(i=1;i<=n;i=i+1){
		mx[i]=0,mn[i]=inf;
		for(j=1;j<=n;j=j+1){
			if(i==j)
				continue;
			d[i][j]=d[i][j]*N+i;
			mx[i]=max(mx[i],d[i][j]);
			mn[i]=min(mn[i],d[i][j]);
		}
	}
	for(x=1;x<=n;x=x+1){
		for(y=1;y<=n;y=y+1){
			if(x==y||mn[x]>mx[y])
				continue;
			for(i=1;i<=n;i=i+1){
				g[i]=0,s[i]=0,b[i]=0;
				if(i==x){
					g[i]=1;
					continue;
				}
				if(i==y){
					b[i]=1;
					continue;
				}
				for(j=1;j<=n;j=j+1){
					if(i==j)
						continue;
					if(d[i][j]<mn[x])
						g[i]=1;
					if(mn[x]<d[i][j]&&d[i][j]<mx[y])
						s[i]=1;
					if(mx[y]<d[i][j])
						b[i]=1;
				}
			}
			f[0][0][0]=1;
			for(z=1;z<=n;z=z+1)
				for(i=0;i<=n;i=i+1)
					for(j=0;j<=n;j=j+1){
						f[z][i][j]=0;
						if(g[z]&&i)
							f[z][i][j]+=f[z-1][i-1][j];
						if(s[z])
							f[z][i][j]+=f[z-1][i][j];
						if(b[z]&&j)
							f[z][i][j]+=f[z-1][i][j-1];
					}
			for(i=g1;i<=g2;i=i+1)
				for(j=s1;j<=s2;j=j+1)
					ans+=f[n][i][n-i-j];
		}
	}
	cout<<ans;
	return 0;
}