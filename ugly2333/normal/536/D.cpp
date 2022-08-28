//CF536D
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
const int N = 2222;
const LL inf = 1e17;
void cmin(LL&x,LL y){
	if(x>y)
		x=y;
}
void cmax(LL&x,LL y){
	if(x<y)
		x=y;
}
int n,m,s,t,p[N],a[N],b[N];
bool c[N][N][2],g[N][N][2][2],w[N][N][2][2];
vector<int> v[N],h[N];
LL d[N],e[N][N][2],f[N][N][2][2],o;
priority_queue<pair<LL,int> > Q;
map<LL,int> M;
map<LL,int>::iterator it;
int dijk(int s){
	int i,x,y;
	LL z;
	for(i=1;i<=n;i=i+1)
		d[i]=inf;
	d[s]=0;
	Q.push(make_pair(0,s));
	while(!Q.empty()){
		x=Q.top().second;
		z=-Q.top().first;
		Q.pop();
		if(d[x]!=z)
			continue;
		for(i=v[x].size();i--;){
			y=v[x][i];
			z=d[x]+h[x][i];
			if(d[y]>z){
				d[y]=z;
				Q.push(make_pair(-z,y));
			}
		}
	}
	for(i=1;i<=n;i=i+1)
		M[d[i]]=1;
	x=0;
	for(it=M.begin();it!=M.end();it++)
		(*it).second=++x;
	for(i=1;i<=n;i=i+1)
		d[i]=M[d[i]];
	M.clear();
	return x;
}
void dfs(int i,int j,int x,int y){
	if(g[i][j][x][y])
		return;
	g[i][j][x][y]=1;
	if(i==s+1||j==t+1){
		if(y==1)
			w[i][j][x][y]=1;
		return;
	}
	if(x)
		f[i][j][x][y]=-inf;
	else
		f[i][j][x][y]=inf;
	if(y){
		dfs(i,j,x^1,0);
		if(w[i][j][x^1][0]){
			w[i][j][x][y]=1;
			if(x)
				cmax(f[i][j][x][y],f[i][j][x^1][0]);
			else
				cmin(f[i][j][x][y],f[i][j][x^1][0]);
		}
	}
	int z=y|c[i][j][x];
	dfs(i+x,j+1-x,x,z);
	if(w[i+x][j+1-x][x][z]){
		w[i][j][x][y]=1;
		if(x)
			cmax(f[i][j][x][y],f[i+x][j+1-x][x][z]+e[i][j][x]);
		else
			cmin(f[i][j][x][y],f[i+x][j+1-x][x][z]+e[i][j][x]);
	}
	//if(w[i][j][x][y])
	//cout<<i<<j<<x<<y<<' '<<f[i][j][x][y]<<endl;
}
int main()
{
	int i,j,x,y,z;
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(i=1;i<=n;i=i+1)
		scanf("%d",p+i);
	for(i=1;i<=m;i=i+1){
		scanf("%d%d%d",&x,&y,&z);
		v[x].push_back(y);
		h[x].push_back(z);
		v[y].push_back(x);
		h[y].push_back(z);
	}
	s=dijk(s);
	for(i=1;i<=n;i=i+1)
		a[i]=d[i];
	t=dijk(t);
	for(i=1;i<=n;i=i+1)
		b[i]=d[i];
	for(i=1;i<=n;i=i+1){
		c[a[i]][b[i]][0]=1;
		c[a[i]][b[i]][1]=1;
		e[a[i]][b[i]][0]-=p[i];
		e[a[i]][b[i]][1]+=p[i];
	}
	for(i=s;i>=1;i=i-1){
		for(j=t;j>=1;j=j-1){
			c[i][j][0]|=c[i+1][j][0];
			c[i][j][1]|=c[i][j+1][1];
			e[i][j][0]+=e[i+1][j][0];
			e[i][j][1]+=e[i][j+1][1];
		}
	}
	dfs(1,1,1,0);
	o=f[1][1][1][0];
	if(o>0)
		cout<<"Break a heart";
	if(o==0)
		cout<<"Flowers";
	if(o<0)
		cout<<"Cry";
	return 0;
}