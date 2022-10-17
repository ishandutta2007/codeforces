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

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  set<pair<int, int>> st;
  vector<int> have(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> have[i];
  }
  vector<set<int>> g(n + 1);
  vector<vector<int>> kek(m + 1, vector<int>(2));
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    g[x].insert(i);
    g[y].insert(i);
    kek[i][0] = x;
    kek[i][1] = y;
  }
  for (int i = 1; i <= n; i++) {
    st.insert({have[i] - SZ(g[i]), i});
  }
  vector<int> rez;
  int sz = m;
  while (!st.empty() && sz > 0) {
    pair<int, int> cur = *(--st.end());
    st.erase(--st.end());
    if (cur.F < 0) {
      cout << "DEAD\n";
      exit(0);
    }
    for (auto it : g[cur.S]) {
      rez.pb(it);
      int v;
      if (kek[it][0] == cur.S) {
        v = kek[it][1];
      }
      else {
        v = kek[it][0];
      }
      if (!g[v].empty()) {
        st.erase({have[v] - SZ(g[v]), v});
        g[v].erase(it);
        st.insert({have[v] - SZ(g[v]), v});
      }
    }
    sz -= SZ(g[cur.S]);
    g[cur.S] = {};
  }  
  reverse(all(rez));
  cout << "ALIVE\n";
  for (auto it : rez) {
    cout << it << ' ';
  }
  cout << '\n';
}