// wygzgyw
#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
template <typename T> void write(T t) {
	if (t<0) { putchar('-'); write(-t); return; }
	if (t>9) write(t/10);
	putchar('0'+t%10);
}
template <typename T> void writeln(T t) { write(t); puts(""); }
#define MP make_pair
const int maxn=(2e5)+10;
int n,m;
vector<int> g[maxn];
int dis[maxn],vis[maxn],deg[maxn];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
void insert(int x,int d) { if (dis[x]>d) dis[x]=d,q.push(MP(dis[x],x)); }
int main() {
	read(n),read(m); int x,y;
	for (int i=1;i<=m;i++) {
		read(x),read(y);
		deg[x]++,g[y].push_back(x);
	}
	for (int i=1;i<=n;i++) dis[i]=1e9;
	insert(n,0);
	while (!q.empty()) {
		x=q.top().second; q.pop();
		if (vis[x]) continue;
		vis[x]=1;
		for (int &y : g[x]) {
			insert(y,dis[x]+deg[y]); deg[y]--;
		}
	}
	printf("%d\n",dis[1]);
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Integer overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/