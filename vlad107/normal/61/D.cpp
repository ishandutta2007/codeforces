#include <stdio.h>
#include <math.h>
#include <memory.h>
#include <algorithm>
#include <vector>

#define MAXN 100500

long long f[MAXN],sum[MAXN];
int n;
std::vector<std::pair<int,int> >g[MAXN];

void dfssum(int x,int px){
	sum[x]=0;
	for (int i=0;i<g[x].size();i++)
		if (g[x][i].first!=px){
			dfssum(g[x][i].first,x);
			sum[x]+=sum[g[x][i].first]+g[x][i].second;
		}
}
void dfs(int x,int px){
	f[x]=sum[x]+sum[x];
	for (int i=0;i<g[x].size();i++)
		if (g[x][i].first!=px){
			int y=g[x][i].first,z=g[x][i].second;
			dfs(y,x);
			long long q=sum[x]-sum[y]-z;
			q*=2;
			if (f[y]+q+z<f[x])f[x]=f[y]+q+z;
		}
}

int main(){
	scanf("%d",&n);
	for (int i=0;i<n-1;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);--x;--y;
		g[x].push_back(std::make_pair(y,z));
		g[y].push_back(std::make_pair(x,z));
	}
	dfssum(0,-1);
	dfs(0,-1);
	printf("%I64d\n",f[0]);
}