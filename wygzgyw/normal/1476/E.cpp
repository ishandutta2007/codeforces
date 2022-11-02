#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e5)+10;
int n,m,k,x;
string s[maxn],t;
map<string,int> M;
int flag;
int deg[maxn];
vector<int> g[maxn];
queue<int> q;
void dfs(int pos) {
	if (pos==k) {
		if (s[x]==t||!M[t]) return;
		g[x].push_back(M[t]);
		deg[M[t]]++;
		return;
	}
	char ch=t[pos];
	dfs(pos+1);
	t[pos]='_';
	dfs(pos+1);
	t[pos]=ch;
}
int ans[maxn],tot;
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(m),read(k);
	for (int i=1;i<=n;i++) {
		cin>>s[i];
		M[s[i]]=i;
	}
	for (int i=1;i<=m;i++) {
		cin>>t>>x; flag=1;
		for (int j=0;j<k;j++)
			if (s[x][j]!=t[j]&&s[x][j]!='_') { flag=0; break; }
		if (!flag) { puts("NO"); return 0; }
		dfs(0);
	}
	for (int i=1;i<=n;i++) if (!deg[i]) q.push(i);
	while (!q.empty()) {
		int u=q.front(); q.pop();
		ans[++tot]=u;
		for (int i=0,v;i<g[u].size();i++) {
			v=g[u][i];
			deg[v]--;
			if (deg[v]==0) q.push(v);
		}
	}
	if (tot!=n) puts("NO");
	else {
		puts("YES");
		for (int i=1;i<=n;i++) printf("%d ",ans[i]);
		printf("\n");
	}
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