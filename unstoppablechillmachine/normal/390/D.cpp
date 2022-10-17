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

const int INF = 1e9 + 10;

string to_str(int x) {
  string res;
  while (x) {
    res.pb(char('0' + x % 10));
    x /= 10;
  }
  reverse(all(res));
  return res;
}

string get(pair<int, int> x) {
  string res = "(1, 1)";
  for (int i = 2; i <= x.F; i++) {
    res += " (";
    res += to_str(i);
    res += ", 1)";
  }
  for (int i = 2; i <= x.S; i++) {
    res += " (";
    res += to_str(x.F); 
    res += ", ";
    res += to_str(i);
    res += ")";
  }
  return res;
}

signed main() {
  ios_base::sync_with_stdio(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<pair<int, int>>> have(n + m);
  have[0].pb({1, 1});
  for (int i = 2; i <= n; i++) {
    pair<int, int> cur = {i, 1};
    while (cur.F >= 1 && cur.S <= m) {
      have[i - 1].pb(cur);
      cur.F--;
      cur.S++;
    }
  }  
  for (int i = 2; i <= m; i++) {
    pair<int, int> cur = {n, i};
    while (cur.F >= 1 && cur.S <= m) {
      have[n + i - 2].pb(cur);
      cur.F--;
      cur.S++;
    }
  }
  vector<string> ans;
  int sum = 0;
  for (int i = 0; i < n + m; i++) {
    if (k >= SZ(have[i])) {
      for (auto it : have[i]) {
        ans.pb(get(it));
      }
      k -= SZ(have[i]);
      sum += SZ(have[i]) * (i + 1);
    }
    else {
      sum += k * (i + 1);
      for (int j = 0; j < k; j++) {
        ans.pb(get(have[i][j]));
      }
      k = 0;
    }
    //cout << SZ(ans) << '\n';
  }
  //cout << k << '\n';
  cout << sum << '\n';
  reverse(all(ans));
  for (auto it : ans) {
    cout << it << '\n';
  }
}