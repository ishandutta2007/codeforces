#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

vector <int> G[N];

int n, m ,x, y, dep[N], du[N], fa[N], who[N], tot = 0, ans;

vector <int> Maxddd[N];

bool vis[N];

vector <int> cxt;

void dfs(int x, int f, int col) {
  fa[x] = f;
  int A = who[fa[x]], B = who[x];
  int now = 0;
  for(int i = 0; i < (int)G[x].size(); ++ i) {
    int V = G[x][i];
    if(V == f) continue;
    ++ now;
    while(now == A || now == B) ++ now;
    who[V] = now;
    dfs(V, x, col);
  }
}

main(void) {
  cin >> n;
  for(int i = 1; i < n; ++ i) {
    scanf("%d%d", &x, &y);
    G[x].push_back(y);
    G[y].push_back(x);
    ++ du[x];
    ++ du[y];
  }
  for(int i = 1; i <= n; ++ i) ans = max(ans, du[i] + 1);
  cout << ans << endl;
  for(int i = 1; i <= n; ++ i) {
    if(du[i] + 1 == ans) {
      who[i] = 1;
      dfs(i, 0, 0);
      break;
    }
  }
  for(int i = 1; i <= n; ++ i) printf("%d ", who[i]);
  puts("");
}