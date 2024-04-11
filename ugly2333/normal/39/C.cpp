//CF39C
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
const int N = 4444;
const int inf = 2e9+N;
map<int,int> M;
map<int,int>::iterator it;
int n,m,l[N],r[N],a[N],f[N],g[N];
vector<int> v[N];
vector<pair<int,int> > w;
bool e[N][N];
void solve(int u){
	int i,j,k;
	for(i=0;i<=n;i=i+1)
		if(i!=u&&l[u]<=l[i]&&r[i]<=r[u])
			v[r[i]].push_back(i);
	f[0]=N+1;
	for(i=1;i<=m;i=i+1){
		f[i]=f[i-1];
		g[i]=0;
		for(j=v[i].size();j--;){
			k=v[i][j];
			if(f[i]<f[l[k]-1]+a[k])
				f[i]=f[l[k]-1]+a[k],g[i]=k;
		}
		v[i].clear();
	}
	a[u]=f[m]-N;
	for(i=m;i;i=i-1){
		k=g[i];
		if(k)
			e[u][k]=1,i=l[k];
	}
}
void dfs(int u){
	int i;
	if(u)
		cout<<u<<' ';
	for(i=0;i<=n;i=i+1)
		if(e[u][i])
			dfs(i);
}
int main()
{
	int i,x,y;
	scanf("%d",&n);
	l[0]=-inf,r[0]=inf;
	for(i=1;i<=n;i=i+1){
		scanf("%d%d",&x,&y);
		l[i]=x-y,r[i]=x+y;
	}
	for(i=0;i<=n;i=i+1)
		M[l[i]]=1,M[r[i]]=1;
	for(it=M.begin();it!=M.end();it++)
		(*it).second=++m;
	for(i=0;i<=n;i=i+1){
		l[i]=M[l[i]],r[i]=M[r[i]]-1;
		w.push_back(make_pair(r[i]-l[i],i));
	}
	sort(w.begin(),w.end());
	for(i=0;i<=n;i=i+1)
		solve(w[i].second);
	cout<<a[0]-1<<endl;
	dfs(0);
	return 0;
}