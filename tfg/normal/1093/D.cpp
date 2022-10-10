#include <bits/stdc++.h>
#define dbg(x) cerr << ">>> " << x << endl
#define _ << ", " <<

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int ms = 300300;
const int MOD = 998244353;

std::vector<int> edges[ms];
int f[2];
int c[ms];
bool visit[ms];

void dfs(int on) {
  assert(!visit[on]);
  visit[on] = true;
  for(auto to : edges[on]) {
    if(!visit[to]) {
      c[to] = 1 ^ c[on];
      dfs(to);
    }
  }
  f[c[on]]++;
}

int solve(int a, int b) {
  int ans = 1;
  while(a--) {
    ans = 2 * ans % MOD;
  }
  return ans;
}

void solve() {
  int n, m;
  std::cin >> n >> m;
  for(int i = 0; i < n; i++) {
    edges[i].clear();
    visit[i] = false;
  }
  for(int i = 0; i < m; i++) {
    int u, v;
    std::cin >> u >> v;
    u--;v--;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  long long ans = 1;
  for(int i = 0; i < n; i++) {
    if(!visit[i]) {
      f[0] = f[1] = 0;
      dfs(i);
      ans = ans * (solve(f[0], f[1]) + solve(f[1], f[0])) % MOD;
    }
    for(auto to : edges[i]) {
      if(c[to] == c[i]) {
        ans = 0;
      }
    }
  }
  std::cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  int t;
  std::cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}