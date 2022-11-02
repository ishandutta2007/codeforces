#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e6)+10;
int n,m,in[maxn],out[maxn],cnt,tot,t2,sink[maxn];
vector<int> g[maxn];
set<int> s;
bool vis[21][maxn];
void dfs(int x,int u) {
	vis[x][u]=1;
	for (int i=0;i<g[u].size();i++) {
		int v=g[u][i];
		if (!vis[x][v]) dfs(x,v);
	}
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m);
	for (int i=1;i<=m;i++) {
		int x,y; read(x); read(y);
		g[x].push_back(y);
		in[y]++; out[x]++;
	}
	for (int i=1;i<=n;i++) {
		if (!in[i]) dfs(++tot,i);
		if (!out[i]) sink[++t2]=i;
	}
	for (int i=1;i<(1<<tot)-1;i++) {
		s.clear();
		cnt=0;
		for (int j=1;j<=tot;j++)
			if (i&(1<<(j-1))) {
				cnt++;
				for (int k=1;k<=t2;k++)
					if (vis[j][sink[k]])
						s.insert(sink[k]);
			}
		if (s.size()<=cnt) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}