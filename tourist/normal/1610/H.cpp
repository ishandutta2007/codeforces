/**
 *    author:  tourist
 *    created: 23.11.2021 20:08:36       
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
  int n, m;
  cin >> n >> m;
  vector<int> pv(n, -1);
  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++) {
    cin >> pv[i];
    --pv[i];
    g[pv[i]].push_back(i);
  }
  vector<int> qx(m), qy(m);
  vector<vector<int>> qs(n);
  for (int i = 0; i < m; i++) {
    cin >> qx[i] >> qy[i];
    --qx[i]; --qy[i];
    qs[qx[i]].push_back(qy[i]);
    qs[qy[i]].push_back(qx[i]);
  }
  for (int i = 0; i < m; i++) {
    if (pv[qx[i]] == qy[i] || pv[qy[i]] == qx[i]) {
      cout << -1 << '\n';
      return 0;
    }
  }
  vector<int> tin(n);
  vector<int> tout(n);
  int T = 0;
  function<void(int)> Dfs = [&](int v) {
    tin[v] = ++T;
    for (int u : g[v]) {
      Dfs(u);
    }
    tout[v] = ++T;
  };
  Dfs(0);
  auto Anc = [&](int x, int y) {
    return (tin[x] <= tin[y] && tout[y] <= tout[x]);
  };
  vector<int> dp(n);
  vector<int> value(n);
  for (int i = n - 1; i >= 0; i--) {
    for (int j : g[i]) {
      dp[i] += dp[j];
      value[j] = dp[j];
    }
    vector<int> need;
    for (int j : qs[i]) {
      if (Anc(i, j)) {
        int low = 0, high = (int) g[i].size() - 1;
        while (low < high) {
          int mid = (low + high) >> 1;
          if (tout[g[i][mid]] < tin[j]) {
            low = mid + 1;
          } else {
            high = mid;
          }
        }
        assert(Anc(g[i][low], j));
        if (value[g[i][low]] == value[j]) {
          need.push_back(g[i][low]);
        }
      }
    }
    sort(need.begin(), need.end());
    need.resize(unique(need.begin(), need.end()) - need.begin());
    for (int j : need) {
      value[j] += 1;
    }
    dp[i] += (int) need.size();
  }
  int ans = n + 1;
  function<void(int)> Solve = [&](int v) { 
    ans = min(ans, dp[v] + 1);
    for (int i : g[v]) {
      int old_dp_v = dp[v];
      int old_dp_i = dp[i];
      int old_value_v = value[v];
      dp[v] -= value[i];
      value[v] = dp[v];
      int add = 0;
      for (int j : qs[i]) {
        if (!Anc(i, j)) {
          if (value[v] == value[j]) {
            add = 1;
          }
        }
      }
      value[v] += add;
      dp[i] += value[v];
      Solve(i);
      dp[v] = old_dp_v;
      dp[i] = old_dp_i;
      value[v] = old_value_v;
    }
  };
  Solve(0);
  cout << ans << '\n';
  return 0;
}