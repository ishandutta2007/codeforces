//CF1394B
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
const int N = 200022;
const int P = 45;
int n,m,d[N];
vector<pair<int,int> > v[N];
int k,p,e[P][P],f[P][P],g[P];
bitset<N> h[P];
int a[P],ans;
void dfs(int u){
	if(u>k){
		ans++;
		return;
	}
	int i,j,x;
	for(i=1;i<=u;i=i+1){
		if(g[f[u][i]])
			continue;
		x=1;
		for(j=1;j<u;j=j+1)
			if(e[a[j]][f[u][i]])
				x=0;
		if(x){
			a[u]=f[u][i];
			dfs(u+1);
		}
	}
}
int main()
{
	int i,j,x,y,z;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=m;i=i+1){
		scanf("%d%d%d",&x,&y,&z);
		d[x]++;
		v[x].push_back(make_pair(z,y));
	}
	for(i=1;i<=k;i=i+1)
		for(j=1;j<=i;j=j+1)
			f[i][j]=p++;
	for(i=1;i<=n;i=i+1){
		sort(v[i].begin(),v[i].end());
		for(j=0;j<d[i];j=j+1){
			if(h[f[d[i]][j+1]][v[i][j].second])
				g[f[d[i]][j+1]]=1;
			h[f[d[i]][j+1]][v[i][j].second]=1;
		}
	}
	for(i=0;i<p;i=i+1)
		for(j=i+1;j<p;j=j+1)
			e[i][j]=(h[i]&h[j]).count()>0;//,cout<<i<<j<<e[i][j]<<endl;
	dfs(1);
	cout<<ans<<endl;
	return 0;
}