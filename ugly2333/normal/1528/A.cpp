//CF1528A
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
int n,l[N],r[N];
LL f[N],g[N];
vector<int> v[N];
void dfs(int u,int fa){
	int i,x;
	f[u]=0,g[u]=0;
	for(i=0;i<v[u].size();i++){
		x=v[u][i];
		if(x==fa)
			continue;
		dfs(x,u);
		f[u]+=max(f[x]+abs(l[x]-l[u]),g[x]+abs(r[x]-l[u]));
		g[u]+=max(f[x]+abs(l[x]-r[u]),g[x]+abs(r[x]-r[u]));
	}
}
int main()
{
	int T,i,x,y;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d%d",l+i,r+i);
		for(i=1;i<n;i++){
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs(1,0);
		cout<<max(f[1],g[1])<<endl;
		for(i=1;i<=n;i++)
			v[i].clear();
	}
	return 0;
}