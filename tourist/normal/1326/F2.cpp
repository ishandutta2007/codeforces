/**
 *    author:  tourist
 *    created: 19.03.2020 18:29:16       
**/
#undef _GLIBCXX_DEBUG

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

const int N = 18;

long long dp[1 << N][N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> mask(n);
  for (int i = 0; i < n; i++) {
    string foo;
    cin >> foo;
    for (int j = 0; j < n; j++) {
      if (foo[j] == '1') {
        mask[i] |= (1 << j);
      }
    }
  }
  vector<vector<int>> ts(n + 1);
  for (int t = 0; t < (1 << n); t++) {
    ts[__builtin_popcount(t)].push_back(t);
  }
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    dp[1 << i][i] = 1;
  }
  vector<long long> ret(1 << (n - 1));
  vector<int> part(1, 1);
  function<void(int)> Dfs = [&](int r) {
    if (r == n) {
      long long res = 0;
      for (int i = 0; i < n; i++) {
        res += dp[(1 << n) - 1][i];
      }
      debug(part, res);
      vector<int> a = part;
      sort(a.begin(), a.end());
      do {
        int mask = 0;
        for (int x : a) {
          mask <<= 1;
          for (int i = 0; i < x - 1; i++) {
            mask = (mask << 1) | 1;
          }
        }
        ret[mask] += res;
      } while (next_permutation(a.begin(), a.end()));
      return;
    }
    if (part.size() == 1 || part.back() < part[part.size() - 2]) {
      part.back() += 1;
      for (int t : ts[r]) {
        int v = t;
        while (v > 0) {
          int i = __builtin_ctz(v);
          int u = ((1 << n) - 1 - t) & mask[i];
          while (u > 0) {
            int j = __builtin_ctz(u);
            dp[t | (1 << j)][j] += dp[t][i];
            u &= u - 1;
          }
          v &= v - 1;
        }
      }
      Dfs(r + 1);
      for (int t : ts[r + 1]) {
        int v = t;
        while (v > 0) {
          int i = __builtin_ctz(v);
          dp[t][i] = 0;
          v &= v - 1;
        }
      }
      part.back() -= 1;
    }
    {
      part.push_back(1);
      for (int t : ts[r]) {
        long long val = 0;
        for (int i = 0; i < n; i++) {
          val += dp[t][i];
        }
        {
          int u = ((1 << n) - 1 - t);
          while (u > 0) {
            int j = __builtin_ctz(u);
            dp[t | (1 << j)][j] += val;
            u &= u - 1;
          }
        }
      }
      Dfs(r + 1);
      for (int t : ts[r + 1]) {
        int v = t;
        while (v > 0) {
          int i = __builtin_ctz(v);
          dp[t][i] = 0;
          v &= v - 1;
        }
      }
      part.pop_back();
    }
  };
  Dfs(1);
  for (int i = 0; i < n - 1; i++) {
    for (int t = (1 << (n - 1)) - 1; t >= 0; t--) {
      if (!(t & (1 << i))) {
        ret[t] -= ret[t | (1 << i)];
      }
    }
  }
  for (int t = 0; t < (1 << (n - 1)); t++) {
    if (t > 0) {
      cout << " ";
    }
    cout << ret[t];
  }
  cout << '\n';
  debug(clock());
  return 0;
}