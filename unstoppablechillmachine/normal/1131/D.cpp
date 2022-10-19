#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
typedef long double ld;
//#define int ll
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define pii pair<int, int>
const int INF = 1e9 + 10;
const int MOD = 998244353;

struct DSU {
  vector<int> p, sz;
  DSU(int n) {
    p.resize(n + 10);
    sz.resize(n + 10, 1);
    for (int i = 1; i <= n; i++) {
      p[i] = i;
    }
  }
  int find(int v) {
    return (p[v] == v ? v : p[v] = find(p[v]));
  }
  void merge(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) {
      return;
    }
    if (sz[a] < sz[b]) {
      swap(a, b);
    }
    p[b] = a;
    sz[a] += sz[b];
  }
};

const int N = 2010;
vector<int> g[N];
int used[N], res[N];

int calc(int v) {
  if (used[v] == 2) {
    return res[v];
  }
  if (used[v] == 1) {
    cout << "No";
    exit(0);
  }
  used[v] = 1;
  res[v] = 1;
  for (auto u : g[v]) {
    res[v] = max(res[v], calc(u) + 1);
  }
  used[v] = 2;
  return res[v];
}

void source() {
  int n, m;
  cin >> n >> m;
  vector<vector<char>> arr(n, vector<char>(m));
  DSU A(n + m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == '=') {
        A.merge(i + 1, n + j + 1);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] == '>') {
        int u = A.find(i + 1), v = A.find(n + j + 1);
        if (u == v) {
          cout << "No";
          exit(0);
        }
        g[u].pb(v);
      }
      else if (arr[i][j] == '<') {
        int u = A.find(i + 1), v = A.find(n + j + 1);
        if (u == v) {
          cout << "No";
          exit(0);
        }
        g[v].pb(u);
      }
    }  
  }
  vector<int> ans;
  for (int i = 1; i <= n + m; i++) {
    ans.pb(calc(A.find(i)));
  }
  cout << "Yes\n";
  for (int i = 0; i < n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
  for (int i = n; i < n + m; i++) {
    cout << ans[i] << ' ';
  }
}

signed main() {
#ifdef extraterrestrial_
  assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#else
#define TASK ""
  //assert(freopen(TASK".in", "r", stdin));
  //assert(freopen(TASK".out", "w", stdout));
  //assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  source();
  return 0;
}