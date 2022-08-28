//CF1404B
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
const int N = 111111;
int n,a,b,da,db,d[N];
vector<int> v[N];
void dfs(int u,int fa){
	d[u]=d[fa]+1;
	int i=v[u].size(),x;
	while(i--){
		x=v[u][i];
		if(x!=fa)
			dfs(x,u);
	}
}
int main()
{
	int T,i,x,y,p,w;
	d[0]=-1;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d%d",&n,&a,&b,&da,&db);
		for(i=1;i<n;i=i+1){
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs(a,0);
		x=0;
		for(i=1;i<=n;i=i+1)
			if(d[x]<d[i])
				x=i;
		p=d[b];
		dfs(x,0);
		y=0;
		for(i=1;i<=n;i=i+1)
			if(d[y]<d[i])
				y=i;
		w=d[y];
		if(p>da&&db>2*da&&w>2*da)
			cout<<"Bob\n";
		else
			cout<<"Alice\n";
		for(i=1;i<=n;i=i+1)
			v[i].clear();
	}
	return 0;
}