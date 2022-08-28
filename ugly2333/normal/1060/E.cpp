//CF1060E
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
int n,d[N],t[N],w[2];
LL s[N],ans;
vector<int> v[N];
void dfs0(int u,int fa){
	int i=v[u].size(),x;
	d[u]=d[fa]+1;
	t[u]=1;
	while(i--){
		x=v[u][i];
		if(x!=fa)
			dfs0(x,u);
	}
	t[fa]+=t[u];
}
void dfs1(int u,int fa){
	int i=v[u].size(),x;
	while(i--){
		x=v[u][i];
		if(x!=fa){
			s[x]=s[u]-t[x]+(n-t[x]);
			dfs1(x,u);
		}
	}
}
int main()
{
	int i,x,y;
	scanf("%d",&n);
	for(i=1;i<n;i=i+1){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	d[0]=-1;
	dfs0(1,0);
	for(i=1;i<=n;i=i+1)
		w[d[i]&1]++,s[1]+=d[i];
	dfs1(1,0);
	ans=(LL)w[0]*w[1]*2;
	for(i=1;i<=n;i=i+1)
		ans+=s[i];
	cout<<ans/4;
	return 0;
}