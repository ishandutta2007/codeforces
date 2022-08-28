//CF 70E
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
const int N = 222;
const int inf = 1e9;
int n,m,c[N],a[N][N],f[N][N],g[N];
int ff[N][N],gg[N];
vector<int> v[N];
int tt,tin[N],tout[N];
bool isin(int x,int y){
	return tin[x]<=tin[y]&&tout[y]<=tout[x];
}
void dfs(int u,int fa=-1){
	//cout<<u<<fa<<endl;
	int i,j,sz,x,y;
	tin[u]=++tt;
	sz=v[u].size();
	for(j=0;j<sz;j=j+1){
		x=v[u][j];
		if(x!=fa)
			dfs(x,u);
	}
	tout[u]=tt;
	g[u]=inf;
	for(i=1;i<=n;i=i+1){
		f[u][i]=c[a[u][i]];
		//cout<<u<<' '<<i<<' '<<a[u][i]<<endl;
		for(j=0;j<sz;j=j+1){
			x=v[u][j];
			if(x!=fa){
				y=f[x][i];
				if(!isin(x,i))
					y=min(y,g[x]);
				f[u][i]+=y;
			}
		}
		if(isin(u,i)&&g[u]>f[u][i]){
			g[u]=f[u][i];
			gg[u]=i;
		}
		//cout<<f[u][i]<<' ';
	}
	//cout<<u<<' '<<g[u]<<endl;
}
int ans[N];
void getans(int u,int fa=-1,int isg=1){
	//cout<<u<<' '<<fa<<' '<<isg<<endl;
	int i,j,sz,x;
	if(isg)
		ans[u]=gg[u];
	i=ans[u];
	sz=v[u].size();
	for(j=0;j<sz;j=j+1){
		x=v[u][j];
		if(x!=fa){
			//cout<<x<<' '<<i<<' '<<f[x][i]<<' '<<g[x]<<endl;
			if(f[x][i]>=g[x]&&!isin(x,i))
				getans(x,u,1);
			else{
				ans[x]=i;
				getans(x,u,0);
			}
		}
	}
}
int main()
{
	int i,j,k,x,y;
	cin>>n>>c[0];
	for(i=1;i<n;i=i+1)
		cin>>c[i];
	for(i=1;i<=n;i=i+1)
		for(j=1;j<=n;j=j+1)
			if(i!=j)
				a[i][j]=inf;
	for(i=1;i<n;i=i+1){
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
		a[x][y]=1;
		a[y][x]=1;
	}
	for(k=1;k<=n;k=k+1)
		for(i=1;i<=n;i=i+1)
			for(j=1;j<=n;j=j+1)
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
	for(i=1;i<=n;i=i+1)
		tin[i]=0,tout[i]=n;
	dfs(1);
	cout<<g[1]<<endl;
	getans(1);
	for(i=1;i<=n;i=i+1)
		cout<<ans[i]<<' ';
	return 0;
}