#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
#define F first
#define S second

const int INF = 2e9 + 10;

struct line {
  int k, b;
  line() : k(INF), b(INF * INF) {};
  line(int k, int b) : k(k), b(b) {};
  int get(int x) {
    return k * x + b;
  }
  int inter(line l) {
    return (b - l.b) / (l.k - k);
  }
  bool operator==(line l) {
    return k == l.k && b == l.b;
  }
};

struct CHT {
  vector<int> from;
  vector<line> have;
  int ptr;
  CHT() {
    from.pb(-INF);
    have.pb(line());
    ptr = 0;
  }
  void add_line(line nl) {
    while (SZ(have) > 1) {
      if (nl.k == have.back().k) {
        if (nl.b < have.back().b) {
          have.pop_back();
          from.pop_back();
        }
        else {
          return;
        }
        continue;
      }
      int cur = nl.inter(have.back());
      if (cur < from.back()) {
        have.pop_back();
        from.pop_back();
      }
      else {
        break;  
      }
    }
    from.pb(nl.inter(have.back()));
    have.pb(nl);
  }
  int get(int x) {
    ptr = min(ptr, SZ(have) - 1);
    while (ptr + 1 < SZ(have) && have[ptr + 1].get(x) <= have[ptr].get(x)) {
      ptr++;
    }
    return have[ptr].get(x);
  }
};

const int N = 1e5 + 10;
CHT kek[N];
vector<line> arr[N];
vector<int> g[N];
int a[N], b[N], dp[N];

bool cmp(line l1, line l2) {
  return l1.k > l2.k; 
}

void dfs(int v, int par = 0) {
  if (SZ(g[v]) == 1 && v != 1) {
    dp[v] = 0;
    return;
  }
  kek[v] = CHT();
  for (auto u : g[v]) {
    if (u != par) {
      dfs(u, v);
      for (auto it : kek[u].have) {
        if (it == line(INF, INF * INF)) {
          continue;
        }
        arr[v].pb(it);
      }
      arr[v].pb(line(b[u], dp[u]));
    }
  }
  sort(all(arr[v]), cmp);
  for (auto it : arr[v]) {
    kek[v].add_line(it);
  }
  dp[v] = kek[v].get(a[v]);
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  dfs(1);
  for (int i = 1; i <= n; i++) {
    cout << dp[i] << ' ';
  }
  cout << '\n';
}