#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll

const int N = 3e5 + 10;
set<int> kek[N], unused;
int sz;
int comp[N];
bool was[N], roflan[N];
vector<int> have;
void dfs(int v) { 
  comp[v] = sz;
  have.pb(v);
  int lst = 0;
  for (;;) {
    auto it = unused.upper_bound(lst);
    if (it == unused.end()) {
      break;
    }
    lst = *it;
    if (kek[v].find(lst) == kek[v].end()) {
      unused.erase(it);
      dfs(lst);
    }
  }  
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    kek[u].insert(v);
    kek[v].insert(u);
  }
  for (int i = 2; i <= n; i++) {
    unused.insert(i);
  }
  for (int i = 2; i <= n; i++) {
    if (unused.find(i) != unused.end()) {
      sz++;
      unused.erase(i);
      have = {};
      dfs(i);
      bool eb = false;
      for (auto it : have) {
        if (kek[1].find(it) == kek[1].end()) {
          eb = true;
        }
      }
      if (!eb) {
        cout << "impossible\n";
        exit(0);
      }
    }
  }
  if (k >= sz && k <= n - 1 - SZ(kek[1])) {
    cout << "possible\n";
  }
  else {
    cout << "impossible\n";
  }
}