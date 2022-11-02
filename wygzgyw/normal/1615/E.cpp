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
typedef long long ll;
const int maxn=(2e5)+10;
int n,k; ll ans;
vector<int> g[maxn];
int dep[maxn],mx[maxn];
priority_queue<int> q;
void dfs(int u,int p) {
	dep[u]=dep[p]+1;
	mx[u]=u;
	for (int &v : g[u]) if (v!=p) {
		dfs(v,u);
		if (dep[mx[v]]>dep[mx[u]]) mx[u]=mx[v];
	}
	for (int &v : g[u]) if (v!=p&&mx[v]!=mx[u]) q.push(dep[mx[v]]-dep[u]);//,printf("?%d\n",dep[mx[v]]-dep[u]);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(k); int x,y;
	for (int i=1;i<n;i++) {
		read(x),read(y);
		g[x].push_back(y),g[y].push_back(x);
	}
	dfs(1,0);
	q.push(dep[mx[1]]);
	int bd=n; ans=-1e18;
	for (int r=0;r<=k;r++) {
		if (r&&!q.empty()) bd-=q.top(),q.pop();
		int BD=min(bd,n/2);
		//printf("%d %d %d\n",r,bd,BD);
		ans=max(ans,(ll)(n-r-BD)*(r-BD));
	}
	printf("%lld\n",ans);
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