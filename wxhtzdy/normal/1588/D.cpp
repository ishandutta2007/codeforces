/**
 *    author:  wxhtzdy
 *    created: 19.07.2022 05:54:47
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
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
      string foo;
      cin >> foo;
      int m = (int) foo.size();
      a[i].resize(m);
      for (int j = 0; j < m; j++) {
        a[i][j] = (foo[j] >= 'a' && foo[j] <= 'z' ? (int) (foo[j] - 'a') : (int) (foo[j] - 'A') + 26);
      }
    }
    const int A = 52;          
    vector<vector<vector<int>>> pos(n, vector<vector<int>>(A));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < (int) a[i].size(); j++) {
        pos[i][a[i][j]].push_back(j);
      }
    }
    vector<vector<vector<int>>> at(A, vector<vector<int>>(1 << n));
    for (int c = 0; c < A; c++) {
      for (int s = 0; s < (1 << n); s++) {
        for (int i = 0; i < n; i++) {
          int f = (s >> i & 1);
          if ((int) pos[i][c].size() <= f) {
            at[c][s].clear();
            break;
          } else {
            at[c][s].push_back(pos[i][c][f]);
          }
        }
      }
    }                                                                 
    vector<vector<pair<vector<int>, int>>> idx(A);
    for (int c = 0; c < A; c++) {
      for (int s = 0; s < (1 << n); s++) {
        if (!at[c][s].empty()) {
          idx[c].emplace_back(at[c][s], s); 
        }
      }
      sort(idx[c].begin(), idx[c].end());
    }
    vector<vector<vector<pair<int, int>>>> g(A, vector<vector<pair<int, int>>>(1 << n));
    vector<vector<int>> in_deg(A, vector<int>(1 << n));
    auto Add = [&](int ca, int sa, int cb, int sb) {
      g[ca][sa].emplace_back(cb, sb);
      in_deg[cb][sb] += 1;  
    };
    for (int c = 0; c < A; c++) {
      for (int s = 0; s < (1 << n); s++) {
        for (int nc = 0; nc < A; nc++) {
          if (at[c][s].empty() || idx[nc].empty()) {
            continue;
          }
          int ns = 0;
          for (int i = 0; i < n; i++) {
            if (pos[i][nc].empty() || pos[i][nc].back() <= pos[i][c][s >> i & 1]) {
              ns = -1;
              break;
            }
            if (pos[i][nc][0] <= pos[i][c][s >> i & 1]) {
              ns |= (1 << i);              
            }
          }
          if (ns != -1) {
            Add(c, s, nc, ns);
          }
        }
      }
    }
    vector<pair<int, int>> que;
    for (int c = 0; c < A; c++) {  
      for (int s = 0; s < (1 << n); s++) {
        if (!at[c][s].empty() && in_deg[c][s] == 0) {
          que.emplace_back(c, s);
        }
      }
    }
    vector<vector<int>> dp(A, vector<int>(1 << n));
    vector<vector<pair<int, int>>> prv(A, vector<pair<int, int>>(1 << n, {-1, -1}));
    for (int b = 0; b < (int) que.size(); b++) {
      int c = que[b].first;
      int s = que[b].second;
      dp[c][s] = max(dp[c][s], 1);
      for (auto& p : g[c][s]) {
        int nc = p.first;
        int ns = p.second;
        if (dp[nc][ns] < dp[c][s] + 1) {
          dp[nc][ns] = dp[c][s] + 1;
          prv[nc][ns] = {c, s};
        }
        in_deg[nc][ns] -= 1;
        if (in_deg[nc][ns] == 0) {
          que.emplace_back(nc, ns);
        }
      }
    }
    pair<int, int> f = {-1, -1};
    for (int c = 0; c < A; c++) {
      for (int s = 0; s < (1 << n); s++) {
        if (dp[c][s] > 0 && (f.first == -1 || dp[f.first][f.second] < dp[c][s])) {
          f = {c, s};
        }
      }
    }             
    string ans = "";
    while (f.first != -1) {
      ans += (f.first < 26 ? (char) ('a' + f.first) : (char) ('A' + f.first - 26));
      f = prv[f.first][f.second];
    }
    reverse(ans.begin(), ans.end());
    cout << (int) ans.size() << '\n' << ans << '\n';
  }                                                                    
  return 0;
}