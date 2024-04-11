#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
using namespace std;

const int N=500005;
int n,m;
int pa[N],fa[N];
int ind[N],q[N],qq[N];
int dfn[N],ed[N];
vector<int> g[N],E[N],e[N];
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
void dfs(int x,int fa){
	dfn[x]=++*dfn;
	for (auto i:e[x])
		if (i!=fa) dfs(i,x);
	ed[x]=*dfn;
}
bool isfa(int x,int y){
	return dfn[x]<=dfn[y]&&ed[y]<=ed[x];
}
bool topo(){
	int h=0,t=0;
	For(i,1,n) for (auto j:e[i]) ++ind[j];
	For(i,1,n) if (!ind[i]) q[++t]=i;
	while (h!=t){
		int x=q[++h];
		for (auto i:e[x]) if (!--ind[i]) q[++t]=i;
	}
	if (t!=n) return 0;
	For(i,1,n) ind[i]=0;
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%d",&pa[i]);
	For(i,1,n) fa[i]=i;
	For(i,1,n) if (pa[i]!=0) e[pa[i]].PB(i);
	For(i,1,n) if (!pa[i]) dfs(i,0);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		if (isfa(y,x)||(isfa(x,y)&&pa[y]!=x)||get(x)==get(y)){
			puts("0");
			return 0;
		}
		fa[get(x)]=get(y);
		g[y].PB(x);
		e[x].PB(y);
	}
	if (!topo())
		return puts("0"),0;
	For(i,1,n) if (pa[i]!=0){
		int x=get(pa[i]),y=get(i);
		//cout<<x<<' '<<y<<endl;
		if (x!=y) E[x].PB(y),++ind[y];
	}
	vector<int> ans;
	int h=0,t=0;
	For(i,1,n) if (!ind[i]&&fa[i]==i) q[++t]=i;
	while (h!=t){
		int x=q[++h],tmp=0;
		for (int i=x;;){
			qq[++tmp]=i;
			if (!g[i].size()) break;
			i=g[i][0];
		}
		Rep(i,tmp,1) ans.PB(qq[i]);
		for (auto i:E[x])
			if (!--ind[i])
				q[++t]=i;
	}
	if (ans.size()!=n)
		puts("0");
	else{
		for (auto i:ans)
			printf("%d ",i);
	}
}