/**
 *  author: milos
 *  created: 04.01.2021 00:55:15
**/
#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
 
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
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
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}                
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
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
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> a(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }                        
  int moves = m / 2;
  const int inf = 1e9;
  vector<vector<vector<vector<int>>>> dp(n + 1, vector<vector<vector<int>>>(m + 1, vector<vector<int>>(max(2, m + 1), vector<int>(k, -inf))));  
  dp[0][1][0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      vector<vector<int>> new_dp(max(2, m + 1), vector<int>(k + 1, -inf));
      for (int l = 0; l <= moves; l++) {
        for (int t = 0; t < k; t++) {
          new_dp[l][t] = dp[i][j - 1][l][t];
        }
      }
      new_dp[0][0] = 0;
      for (int l = 0; l <= moves; l++) {
        for (int t = 0; t < k; t++) {
          new_dp[l][t] = max(new_dp[l][t], dp[i][j - 1][l][t]);
          new_dp[l + 1][(t + a[i][j]) % k] = max(new_dp[l + 1][(t + a[i][j]) % k], dp[i][j - 1][l][t] + a[i][j]);
        }
      }
      if (i == 1 && j == 1) {
        new_dp[1][a[i][j] % k] = a[i][j];
      }
      for (int l = 0; l <= moves; l++) {
        for (int t = 0; t < k; t++) {
          dp[i][j][l][t] = new_dp[l][t];
        }
      } 
    }   
    if (i < n) {
      for (int j = 0; j <= moves; j++) {
        for (int l = 0; l < k; l++) {
          dp[i + 1][0][0][l] = max(dp[i + 1][0][0][l], dp[i][m][j][l]);
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= moves; i++) {
    ans = max(ans, dp[n][m][i][0]); 
  }
  cout << ans << '\n';
  return 0;
}