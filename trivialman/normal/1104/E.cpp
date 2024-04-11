#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
const int N = 250010;

int dep[N],fa[N],n,m,k,x,y,maxdep=0,maxu;
bool leaf[N],v[N];
vector<int> g[N];

void dfs(int u){
	maxdep=dep[u]>maxdep?dep[maxu=u]:maxdep;
	v[u] = leaf[u] = true;
	for(auto x:g[u])if(!v[x]){
		leaf[u] = false;
		dep[x] = dep[u] + 1;
		fa[x] = u;
		dfs(x);
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,m){
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dep[1]=1;dfs(1);
	if(maxdep>n/k)
		for(printf("PATH\n%d\n",maxdep);maxu;maxu=fa[maxu])printf("%d ",maxu);
	else{
		printf("CYCLES");
		for(int u=1;k;++u)if(leaf[u]){
			--k;
			vector<int> a;
			for(auto x:g[u])if(x!=fa[u])a.push_back(x);
			if(dep[a[0]]>dep[a[1]])swap(a[0],a[1]);
			int d1=dep[a[0]],d2=dep[a[1]],d3=dep[u];
			if((d3-d1+1)%3)
				for(printf("\n%d\n",d3-d1+1),x=u;x!=fa[a[0]];x=fa[x])printf("%d ",x);
			else if((d3-d2+1)%3)
				for(printf("\n%d\n",d3-d2+1),x=u;x!=fa[a[1]];x=fa[x])printf("%d ",x);
			else
				for(printf("\n%d\n%d ",d2-d1+2,u),x=a[1];x!=fa[a[0]];x=fa[x])printf("%d ",x);
		}
	}
	return 0;
}