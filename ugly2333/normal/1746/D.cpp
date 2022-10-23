//CF1746D
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
const int N = 222222;
int n,k,a[N],p[N];
LL f[N],g[N];
vector<int> v[N];
void dfs(int u,int k){
	if(v[u].size()==0){
		f[u]=(LL)k*a[u];
		g[u]=f[u]+a[u];
		return;
	}
	int i,x,o=k/v[u].size();
	vector<int> e;
	e.clear();
	f[u]=(LL)k*a[u];
	for(i=0;i<v[u].size();i++){
		x=v[u][i];
		dfs(x,o);
		f[u]+=f[x];
		e.push_back(g[x]-f[x]);
	}
	sort(e.begin(),e.end());
	reverse(e.begin(),e.end());
	for(i=0;i<k%v[u].size();i++)
		f[u]+=e[i];
	g[u]=f[u]+a[u]+e[i];
}
int main()
{
	int T,i,x;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		for(i=2;i<=n;i++)
			scanf("%d",p+i),v[p[i]].push_back(i);
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		dfs(1,k);
		printf("%lld\n",f[1]);
		for(i=1;i<=n;i++)
			v[i].clear();
	}
	return 0;
}