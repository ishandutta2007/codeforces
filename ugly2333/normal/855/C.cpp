//CF 855C
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
const int N = 111111;
const int mod = 1e9+7;
int n,m,k,p;
vector<int> v[N];
LL f[N][12],g[N][12],h[N][12];//k <k >k
void dfs(int u,int fa){
	int i,j,l,s,x;
	LL ff,gg,hh;
	s=v[u].size();
	f[u][1]=1;
	g[u][0]=k-1;
	h[u][0]=m-k;
	for(i=0;i<s;i=i+1){
		x=v[u][i];
		if(x==fa)
			continue;
		dfs(x,u);
		for(j=p;j>=0;j=j-1){
			ff=0,gg=0,hh=0;
			for(l=0;l<=j;l=l+1){
				ff+=f[u][j-l]*g[x][l]%mod;
				gg+=g[u][j-l]*(f[x][l]+g[x][l]+h[x][l])%mod;
				hh+=h[u][j-l]*(g[x][l]+h[x][l])%mod;
			}
			if(j)
				f[u][j]=ff%mod;
			g[u][j]=gg%mod;
			h[u][j]=hh%mod;
		}
	}
}
int main()
{
	int i,x,y;
	LL ans;
	scanf("%d%d",&n,&m);
	for(i=1;i<n;i=i+1){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	scanf("%d%d",&k,&p);
	dfs(1,0);
	ans=0;
	for(i=0;i<=p;i=i+1)
		ans+=(LL)f[1][i]+g[1][i]+h[1][i];
	cout<<ans%mod<<endl;
	//cout<<f[1][0]<<g[1][0]<<h[1][0];
	return 0;
}