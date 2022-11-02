#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(4e5)+10;
const int INF=(1e9);
int n,m,d[maxn],s,t,a1,a2;
vector<int> g[maxn];
int dis[maxn],tot;
int nxt[maxn],head[maxn],to[maxn];
void add(int x,int y) {
	tot++; nxt[tot]=head[x];
	head[x]=tot; to[tot]=y;
}
bool vis[maxn];
queue<int> q;
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m);
	int x,y;
	while (m--) {
		read(x); read(y);
		g[y].push_back(x);
		add(x,y);
	}
	read(m);
	for (int i=1;i<=m;i++) read(d[i]);
	s=d[1],t=d[m];
	q.push(t); vis[t]=1;
	for (int i=1;i<=n;i++) dis[i]=INF;
	dis[t]=0;
	while (!q.empty()) {
		int u=q.front(); q.pop(); vis[u]=0;
		for (int i=0,v;i<g[u].size();i++) {
			v=g[u][i];
			if (dis[v]>dis[u]+1) {
				dis[v]=dis[u]+1;
				if (!vis[v]) q.push(v),vis[v]=1;
			}
		}
	}
	for (int i=1;i<m;i++) {
		x=d[i],y=d[i+1];
		if (dis[y]+1==dis[x]) {
			bool flag=0;
			for (int j=head[x],v;j;j=nxt[j]) {
				v=to[j];
				if (dis[v]+1==dis[x]&&v!=y) { flag=1; break; }
			}
			if (flag) a2++;
		} else a1++,a2++;
	}
	printf("%d %d\n",a1,a2);
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