#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(3e5)+10;
int n,len,cnt;
bool vis[maxn];
char s[60];
vector<int> g[maxn];
void add(int x,int y) {
	g[x].push_back(y);
	g[y].push_back(x);
	vis[x]=vis[y]=0;
}
void dfs(int u) {
	if (vis[u]) return; vis[u]=1;
	for (int i=0;i<g[u].size();i++) dfs(g[u][i]);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	memset(vis,1,sizeof(vis));
	for (int i=1;i<=n;i++) {
		scanf("%s",s+1);
		len=strlen(s+1);
		for (int j=1;j<=len;j++)
			add(i,s[j]-'a'+n+1);
	}
	for (int i=n+1;i<=n+26;i++)
		if (!vis[i]) dfs(i),cnt++;
	printf("%d\n",cnt);
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