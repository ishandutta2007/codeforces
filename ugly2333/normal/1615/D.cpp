//CF1615A
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
int n,m,e[N],f,a[N],b[N],c[N];
vector<int> v[N],w[N],g[N],h[N];
void dfs(int u,int c){
	if(e[u]){
		if(e[u]!=c)
			f=1;
		return;
	}
	e[u]=c;
	int i,x;
	for(i=0;i<g[u].size();i++){
		x=g[u][i];
		if(h[u][i])
			dfs(x,c^3);
		else
			dfs(x,c);
	}
}
void dfsv(int u,int fa){
	int i,x;
	for(i=0;i<v[u].size();i++){
		x=v[u][i];
		if(x!=fa){
			if(c[w[u][i]]<0)
				c[w[u][i]]=(e[u]!=e[x]);
			dfsv(x,u);
		}
	}
}
int main()
{
	int T,i,x,y,z;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(i=1;i<n;i++){
			scanf("%d%d%d",&x,&y,&z);
			v[x].push_back(y);
			v[y].push_back(x);
			w[x].push_back(i);
			w[y].push_back(i);
			a[i]=x,b[i]=y,c[i]=z;
			if(z>=0){
				z=__builtin_popcount(z)%2;
				g[x].push_back(y);
				g[y].push_back(x);
				h[x].push_back(z);
				h[y].push_back(z);
			}
		}
		for(i=1;i<=m;i++){
			scanf("%d%d%d",&x,&y,&z);
			g[x].push_back(y);
			g[y].push_back(x);
			h[x].push_back(z);
			h[y].push_back(z);
		}
		f=0;
		for(i=1;i<=n;i++)
			if(!e[i])
				dfs(i,1);
		if(f)
			printf("NO\n");
		else{
			printf("YES\n");
			dfsv(1,0);
			for(i=1;i<n;i++){
				printf("%d %d %d\n",a[i],b[i],c[i]);
			}
		}
		for(i=1;i<=n;i++){
			v[i].clear();
			w[i].clear();
			g[i].clear();
			h[i].clear();
			e[i]=0;
			a[i]=0,b[i]=0,c[i]=0;
		}
	}
	return 0;
}