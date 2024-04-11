#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

vector <int> G[N];

int n, m, x, y, vis[N], used[N];

vector <int> ans, res;

main(void) {
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= m; ++ i) {
    scanf("%d%d", &x, &y);
    G[x].push_back(y);
  }
  for(int i = 1; i <= n; ++ i) if(!used[i]){
    ans.push_back(i);
    for(int j = 0; j < (int) G[i].size(); ++ j) {
      int V = G[i][j];
      used[V] = 1;
    }
  }
  for(int i = ans.size() - 1; i >= 0; -- i) {
    int V = ans[i];
    if(!vis[V]) {
      res.push_back(V);
      for(int j = 0; j < (int) G[V].size(); ++ j) {
	int K = G[V][j];
	vis[K] = 1;
      }
    }
  }
  cout << res.size() << endl;
  for(int i = 0; i < (int) res.size(); ++ i) printf("%d ", res[i]);
  puts("");
}