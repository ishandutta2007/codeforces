// windows line endings - two chars each
#include <bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int> a, vector<int> b) {a.insert(a.begin(),b.begin(),b.end());sort(a.begin(),a.end());a.erase(unique(a.begin(),a.end()),a.end());while (a.size()>10) a.pop_back();return a;}

int n,m,q;
vector<int> has[100013];
int h[100013];
int up[20][100013];
vector<int> low[20][100013];
vector<int> adj[100013];

int lca(int a, int b) {if (h[a]>h[b]) swap(a,b);for (int i=19;i>=0;i--) if ((h[b]-h[a])&(1<<i)) b = up[i][b];if (a==b) return a;for (int i=19;i>=0;i--) if (up[i][a]!=up[i][b]) a = up[i][a], b = up[i][b];return up[0][a];}

vector<int> go(int a, int d) {vector<int> res = has[a];for (int i=19;i>=0;i--) if (d&(1<<i)) res = merge(res,low[i][a]), a = up[i][a];return res;}

void dfs(int x, int p=0, int d=0) {h[x] = d;up[0][x] = p;low[0][x] = has[p];sort(has[x].begin(),has[x].end());while (has[x].size()>10) has[x].pop_back();for (int i: adj[x]) if (i!=p) dfs(i,x,d+1);}

void query(int u, int v, int a) {int l = lca(u,v);vector<int> res = merge(go(u,h[u]-h[l]),go(v,h[v]-h[l]));while (res.size()>a) res.pop_back();printf("%d",res.size());for (int i: res) printf(" %d",i);printf("\n");}

int main() {scanf("%d%d%d",&n,&m,&q);for (int i=1;i<n;i++) {int u,v;scanf("%d%d",&u,&v);adj[u].push_back(v);adj[v].push_back(u);}for (int i=1;i<=m;i++) {int c;scanf("%d",&c);has[c].push_back(i);}dfs(1);for (int i=1;i<20;i++) for (int j=1;j<=n;j++) {up[i][j] = up[i-1][up[i-1][j]];low[i][j] = merge(low[i-1][j],low[i-1][up[i-1][j]]);}for (int i=0;i<q;i++) {int u,v,a;scanf("%d%d%d",&u,&v,&a);query(u,v,a);}return 0;}