#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(2e5)+10;
int n,a[maxn],b[maxn],ans[maxn];
vector<int> g[maxn];
void add(int x,int y) {
	g[x].push_back(y);
}
void dfs(int u) {
	for (int i=0,v;i<g[u].size();i++) {
		v=g[u][i];
		if (ans[v]!=-1) continue;
		ans[v]=ans[u]^1;
		dfs(v);
	}
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); int x,y;
	for (int i=1;i<=n;i++) {
		read(x); read(y);
		if (a[x]) add(a[x],i),add(i,a[x]),a[x]=0;
		else a[x]=i;
		if (b[y]) add(b[y],i),add(i,b[y]),b[y]=0;
		else b[y]=i;
	}
	memset(ans,-1,sizeof(ans));
	for (int i=1;i<=n;i++)
		if (ans[i]==-1) ans[i]=0,dfs(i);
	for (int i=1;i<=n;i++)
		if (!ans[i]) printf("r");
		else printf("b");
	printf("\n");
	return 0;
}
/*
  REMEMBER:
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Array size? Integer overflow? Time complexity? Memory usage? Precision error?
*/