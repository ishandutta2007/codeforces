#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
#include <cctype>
#include <vector>
#include <set>
#include <string>
using namespace std;
#define N 100005
int fa[N],n,m,need[N],is[N],aa[N];
int rtis[N],ans[N],K,head[N],to[N<<1],nxt[N<<1],val[N<<1],cnt;
int siz[N],mx;
inline void add(int u,int v,int w) {
	to[++cnt]=v; nxt[cnt]=head[u]; head[u]=cnt; val[cnt]=w;
}
struct E {
	int x,y,z;
	friend bool operator < (const E &v,const E &u) {return v.z<u.z;}
}a[N];
inline int find(int x) {return fa[x]==x?x:fa[x]=find(fa[x]);}
void dfs(int x,int y) {
	siz[x]=rtis[x];
	for(int i=head[x];i;i=nxt[i]) if(to[i]!=y) {
		dfs(to[i],x);
		siz[x]+=siz[to[i]];
		if(siz[to[i]]&&siz[to[i]]<K) mx=max(mx,val[i]);
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&K);	
	for(int i=1;i<=K;i++)scanf("%d",&aa[i]),rtis[aa[i]]=1;
	for(int i=1;i<=m;i++)scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
	sort(a+1,a+m+1);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) {
		int dx=find(a[i].x),dy=find(a[i].y);
		if(dx!=dy) {
			fa[dx]=dy; need[i]=1; add(a[i].x,a[i].y,a[i].z); add(a[i].y,a[i].x,a[i].z);
		}
	}
	dfs(1,0);
	for(int i=1;i<=K;i++) printf("%d ",mx);
}