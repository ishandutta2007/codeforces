/**
 *    author:  tourist
 *    created: 28.10.2018 19:02:44       
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
  const int MAX = 300010;
  vector<int> p(MAX);
  iota(p.begin(), p.end(), 0);
  for (int i = 2; i < MAX; i++) {
    if (p[i] == i) {
      for (int j = i + i; j < MAX; j += i) {
        if (p[j] == j) {
          p[j] = i;
        }
      }
    }
  }
  int n;
  cin >> n;
  vector<int> has(MAX, 0);
  vector<vector<int>> d(n);
  int g = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    g = __gcd(g, x);
    has[x] = 1;
    while (x > 1) {
      if (d[i].empty() || d[i].back() != p[x]) {
        d[i].push_back(p[x]);
      }
      x /= p[x];
    }
  }
  if (g > 1) {
    cout << -1 << '\n';
    return 0;
  }
  for (int i = 1; i < MAX; i++) {
    for (int j = i + i; j < MAX; j += i) {
      has[i] += has[j];
    }
  }
  int ans = n + 1;
  for (int i = 0; i < n; i++) {
    int sz = (int) d[i].size();
    vector<int> cnt(1 << sz);
    for (int t = 0; t < (1 << sz); t++) {
      int u = 1;
      for (int j = 0; j < sz; j++) {
        if (t & (1 << j)) {
          u *= d[i][j];
        }
      }
      cnt[t] = has[u];
    }
    for (int bit = 0; bit < sz; bit++) {
      for (int t = 0; t < (1 << sz); t++) {
        if (t & (1 << bit)) {
          cnt[t ^ (1 << bit)] -= cnt[t];
        }
      }
    }
    for (int bit = 0; bit < sz; bit++) {
      for (int t = 0; t < (1 << sz); t++) {
        if (t & (1 << bit)) {
          cnt[t] += cnt[t ^ (1 << bit)];
        }
      }
    }
    vector<int> dp(1 << sz);
    dp[0] = 1;
    for (int t = 1; t < (1 << sz); t++) {
      dp[t] = n + 1;
      int u = t;
      while (u > 0) {
        if (cnt[(1 << sz) - 1 - u] > 0) {
          dp[t] = min(dp[t], dp[t - u] + 1);
        }
        u = (u - 1) & t;
      }
    }
    ans = min(ans, dp[(1 << sz) - 1]);
  }
  cout << ans << '\n';
  return 0;
}