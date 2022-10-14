/**
 *    author:  wxhtzdy
 *    created: 11.10.2022 17:17:00
**/
#include <bits/stdc++.h>

using namespace std;

string to_string(string s) {
  return '"' + s + '"';
}
string to_string(const char* s) {
  return to_string((string) s);
}
string to_string(bool b) {
  return (b ? "true" : "false");
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      --u; --v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    int fr;
    cin >> fr;
    vector<int> fi(fr);          
    for (int i = 0; i < fr; i++) {
      cin >> fi[i];
      --fi[i];
    }
    int k;
    cin >> k;
    vector<int> idx(n, -1);
    vector<bool> bad(fr);
    for (int i = 0; i < k; i++) {
      int x;
      cin >> x;
      --x;
      if (idx[fi[x]] == -1) {
        idx[fi[x]] = 0;
      }
      bad[x] = true;
      idx[fi[x]] = (idx[fi[x]] | (1 << i));    
    }    
    vector<bool> has(n);
    for (int i = 0; i < fr; i++) {
      if (!bad[i]) {
        has[fi[i]] = true;        
      }
    }
    vector<int> que(1, 0);
    vector<int> d(n, -1);
    d[0] = 0;
    vector<vector<int>> f(n);
    for (int b = 0; b < (int) que.size(); b++) {
      int i = que[b];
      for (int j : g[i]) {
        if (d[j] == -1) {
          que.push_back(j);
          d[j] = d[i] + 1;          
        }
        if (d[j] == d[i] + 1) {                       
          f[j].push_back(i);
        }
      }
    }
    vector<vector<bool>> state(n, vector<bool>(1 << k, false));
    state[0][0] = true;
    for (int b = 0; b < (int) que.size(); b++) {
      int i = que[b];
      for (int j : f[i]) {
        //cout << "sada sam na " << i + 1 << " pre je bio " << j + 1 << '\n';
        for (int p = 0; p < (1 << k); p++) {
          state[i][p] = (state[i][p] | state[j][p]);
        }
      }
      if (idx[i] != -1) {
        for (int p = 0; p < (1 << k); p++) {
          state[i][p | idx[i]] = (state[i][p | idx[i]] | state[i][p]);
        }
      }
    }   
    /* for (int i = 0; i < n; i++) {
      for (int j = 0; j < (1 << k); j++) {
        cout << state[i][j] << " ";
      }
      cout << '\n';
    } */
    vector<bool> dp(1 << k);
    dp[0] = true;
    vector<int> cars;
    for (int i = 0; i < fr; i++) {
      if (!bad[i]) {
        cars.push_back(fi[i]);
      }
    }
    for (int i : cars) {
      auto new_dp = dp;
      for (int mask = 0; mask < (1 << k); mask++) {
        if (!dp[mask]) {
          continue;
        }
        for (int sub = 0; sub < (1 << k); sub++) {
          if (state[i][sub]) {
            new_dp[mask | sub] = true;
          }
        }
      }
      swap(dp, new_dp);
    }   
    int ans = 0;
    for (int i = 0; i < (1 << k); i++) {
      if (dp[i]) {
        ans = max(ans, __builtin_popcount(i));
      }
    }
    cout << k - ans << '\n';
  }                                                                    
  return 0;
}