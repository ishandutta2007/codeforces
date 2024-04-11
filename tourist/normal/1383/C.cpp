/**
 *    author:  tourist
 *    created: 24.07.2020 17:34:32       
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

class dsu {
 public:
  vector<int> p;
  int n;

  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }

  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }

  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int len;
    cin >> len;
    string a, b;
    cin >> a >> b;
    int n = 20;
    dsu d(n);
    for (int i = 0; i < len; i++) {
      d.unite((int) (a[i] - 'a'), (int) (b[i] - 'a'));
    }
    vector<vector<int>> comps(n);
    for (int i = 0; i < n; i++) {
      comps[d.get(i)].push_back(i);
    }
    vector<int> mask_to(n);
    for (int i = 0; i < len; i++) {
      mask_to[(int) (b[i] - 'a')] |= (1 << ((int) (a[i] - 'a')));
    }
    int ans = 0;
    for (auto& comp : comps) {
      int cnt = (int) comp.size();
      if (cnt == 0) {
        continue;
      }
      vector<int> new_mask(cnt);
      for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < cnt; j++) {
          if (i == j) {
            continue;
          }
          if (mask_to[comp[i]] & (1 << comp[j])) {
            new_mask[i] |= (1 << j);
          }
        }
      }
      vector<int> dp(1 << cnt, 0);
      dp[0] = 0;
      for (int t = 0; t < (1 << cnt); t++) {
        for (int i = 0; i < cnt; i++) {
          if (t & (1 << i)) {
            continue;
          }
          int ft = dp[t];
          if ((new_mask[i] & t) == new_mask[i]) {
            ft += 1;
          }
          dp[t | (1 << i)] = max(dp[t | (1 << i)], ft);
        }
      }
//      debug(comp, dp.back());
      ans += 2 * cnt - 1 - dp.back();
    }
    cout << ans << '\n';
  }
  return 0;
}