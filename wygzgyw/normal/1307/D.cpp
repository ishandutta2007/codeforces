#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int INF=(1e9);
const int maxn=(2e5)+10;
int n,m,k,dis[2][maxn],a[maxn],ans,mx;
vector<int> g[maxn];
bool vis[maxn];
queue<int> q;
int tot;
pair<int,int> d[maxn];
void SPFA(int op,int s) {
	for (int i=1;i<=n;i++) dis[op][i]=INF;
	q.push(s);
	dis[op][s]=0;
	while (!q.empty()) {
		int u=q.front(); q.pop(); vis[u]=0;
		for (int i=0,v;i<g[u].size();i++) {
			v=g[u][i];
			if (dis[op][v]>dis[op][u]+1) {
				dis[op][v]=dis[op][u]+1;
				if (!vis[v]) q.push(v),vis[v]=1;
			}
		}
	}
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); int x,y;
	read(m); read(k);
	for (int i=1;i<=k;i++) read(a[i]);
	for (int i=1;i<=m;i++) {
		read(x); read(y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	SPFA(0,1);
	SPFA(1,n);
	for (int i=1;i<=k;i++)
		d[++tot]=make_pair(dis[0][a[i]]-dis[1][a[i]],a[i]);
	sort(d+1,d+tot+1);
	ans=0;
	mx=-INF;
	for (int i=1;i<=tot;i++) {
		x=d[i].second;
		ans=max(ans,mx+dis[1][x]+1);
		mx=max(mx,dis[0][x]);
	}
	printf("%d\n",min(dis[0][n],ans));
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/