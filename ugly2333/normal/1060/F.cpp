//CF1060F
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
const int N = 55;
int n,t[N];
DB f[N][N][N],g[N][N],p[N][N];
vector<int> v[N];
void go(int u){
	int i,j,k;
	DB s;
	for(i=0;i<=t[u];i=i+1){
		for(j=0;j<=t[u];j=j+1){
			s=0.0;
			if(i)
				s=(DB)i/t[u]*f[u][i-1][j];
			if(j){
				for(k=i+1;k<=t[u];k=k+1)
					s+=(DB)1/t[u]*f[u][k-1][j-1];
			}
			g[i][j]=s;
		}
	}
	for(i=0;i<=t[u];i=i+1)
		for(j=0;j<=t[u];j=j+1)
			f[u][i][j]=g[i][j],g[i][j]=0.0;
}
int getp(int x,int y){
	int i,j;
	for(i=0;i<=x;i=i+1)
		for(j=0;j<=y;j=j+1)
			p[i][j]=0.0;
	p[0][0]=1.0;
	for(i=0;i<=x;i=i+1){
		for(j=0;j<=y;j=j+1){
			if(i==x&&j==y)
				break;
			p[i+1][j]+=(DB)(x-i)/(x+y-i-j)*p[i][j];
			p[i][j+1]+=(DB)(y-j)/(x+y-i-j)*p[i][j];
		}
	}
}
void mrg(int x,int y){
	int i,j,k,l;
	DB s;
	getp(t[x],t[y]);
	for(i=0;i<=t[x];i=i+1){
		for(j=0;j<=t[x];j=j+1){
			for(k=0;k<=t[y];k=k+1){
				for(l=0;l<=t[y];l=l+1){
					s=f[x][i][j]*f[y][k][l]*p[i][k];
					g[i+k][j+l]+=s;
				}
			}
		}
	}
	t[x]+=t[y];
	for(i=0;i<=t[x];i=i+1)
		for(j=0;j<=t[x];j=j+1)
			f[x][i][j]=g[i][j],g[i][j]=0.0;
}
void dfs(int u,int fa){
	int i=v[u].size(),x;
	t[u]=0;
	f[u][0][0]=1.0;
	while(i--){
		x=v[u][i];
		if(x==fa)
			continue;
		dfs(x,u);
		go(x);
		mrg(u,x);
	}
	t[u]++;
}
void clr(){
	int i,j,k;
	for(i=0;i<N;i=i+1)
		for(j=0;j<N;j=j+1)
			for(k=0;k<N;k=k+1)
				f[i][j][k]=0.0;
}
int main()
{
	int i,x,y;
	DB s;
	cin>>n;
	for(i=1;i<n;i=i+1){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(i=1;i<=n;i=i+1){
		clr();
		dfs(i,0);
		s=0.0;
		for(x=n;x>=0;x=x-1)
			s=s/2+f[i][0][x];
		printf("%.9lf\n",s);
	}
	return 0;
}