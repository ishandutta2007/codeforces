//CF1149D
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
const int N = 77;
const int W = 1<<17;
const int M = 222;
const int inf = 1e9+N;
int n,m,q,w,a,b,ex[M],ey[M],ez[M],f[N],r[N],t[N][N],d[N][W];
vector<int> c[N],v[N];
priority_queue<pair<int,int> > Q;
int fnd(int x){
	if(f[x]==x)
		return x;
	return f[x]=fnd(f[x]);
}
int main()
{
	int i,j,k,x,y,z,xx,yy,zz;
	scanf("%d%d%d%d",&n,&m,&a,&b);
	for(i=1;i<=n;i=i+1)
		f[i]=i;
	for(i=1;i<=n;i=i+1)
		for(j=1;j<=n;j=j+1)
			if(i!=j)
				t[i][j]=inf;
	for(i=1;i<=m;i=i+1){
		scanf("%d%d%d",&x,&y,&z);
		ex[i]=x,ey[i]=y,ez[i]=z;
		if(z==a)
			f[fnd(x)]=fnd(y),t[x][y]=a,t[y][x]=a;
	}
	for(k=1;k<=n;k=k+1)
		for(i=1;i<=n;i=i+1)
			for(j=1;j<=n;j=j+1)
				t[i][j]=min(t[i][j],t[i][k]+t[k][j]);
	for(i=1;i<=n;i=i+1)
		c[fnd(i)].push_back(i);
	q=0;
	for(i=1;i<=n;i=i+1){
		r[i]=-1;
		if(c[i].size()<=3)
			continue;
		r[i]=q++;
	}
	w=1<<q;
	for(i=1;i<=m;i=i+1){
		x=ex[i],y=ey[i],z=ez[i];
		if(z==b){
			if(f[x]==f[y])
				continue;
			v[x].push_back(y);
			v[y].push_back(x);
		}
	}
	for(i=1;i<=n;i=i+1)
		for(j=0;j<w;j=j+1)
			d[i][j]=inf;
	if(r[f[1]]<0)
		j=0;
	else
		j=1<<r[f[1]];
	d[1][j]=0;
	Q.push(make_pair(0,(1<<17)|j));
	while(!Q.empty()){
		x=Q.top().second>>17;
		y=Q.top().second&(W-1);
		z=-Q.top().first;
		Q.pop();
		if(d[x][y]!=z)
			continue;
		k=f[x];
		for(i=c[k].size();i--;){
			xx=c[k][i];
			yy=y;
			zz=z+t[x][xx];
			if(d[xx][yy]>zz){
				d[xx][yy]=zz;
				Q.push(make_pair(-zz,xx<<17|yy));
			}
		}
		for(i=v[x].size();i--;){
			xx=v[x][i];
			j=r[f[xx]];
			if(j>=0&&(y&(1<<j)))
				continue;
			if(j>=0)
				yy=y|(1<<j);
			else
				yy=y;
			zz=z+b;
			if(d[xx][yy]>zz){
				d[xx][yy]=zz;
				Q.push(make_pair(-zz,xx<<17|yy));
			}
		}
	}
	for(i=1;i<=n;i=i+1){
		z=inf;
		for(j=0;j<w;j=j+1)
			z=min(z,d[i][j]);
		cout<<z<<' ';
	}
	return 0;
}