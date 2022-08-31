/**
 *    author:  tourist
 *    created: 17.12.2019 18:38:52       
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

vector<vector<int>> g;
vector<int> down;
vector<int> order;
vector<int> pv;

void Dfs(int v) {
  order.push_back(v);
  down[v] = 0;
  for (int u : g[v]) {
    if (u == pv[v]) {
      continue;
    }
    pv[u] = v;
    Dfs(u);
    down[v] = max(down[v], down[u] + 1);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  g.resize(n);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    --x; --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  down.resize(n);
  order.clear();
  pv.resize(n);
  pv[0] = -1;
  Dfs(0);
  vector<int> ans(n + 1, 1);
  vector<int> up(n, 0);
  vector<int> children;
  vector<int> cc;
  vector<vector<int>> vcc(n);
  for (int it = 0; it < (int) order.size(); it++) {
    children.clear();
    cc.clear();
    int v = order[it];
    for (int u : g[v]) {
      if (u == pv[v]) {
        continue;
      }
      children.push_back(u);
      cc.push_back(down[u] + 1);
    }
    cc.push_back(up[v]);
    if (up[v] != 0) {
      cc.push_back(0);
    }
    sort(cc.rbegin(), cc.rend());
//    debug(cc);
    int sz = (int) cc.size();
    for (int i = 1; i < sz - 1; i++) {
      ans[2 * cc[i] - 1] = max(ans[2 * cc[i] - 1], i + 1);
    }
    for (int i = 1; i < sz; i++) {
      if (cc[i] < cc[i - 1]) {
        ans[2 * cc[i] + 1] = max(ans[2 * cc[i] + 1], i + 1);
      }
    }
    for (int i = 1; i < sz - 1; i++) {
      ans[2 * cc[i]] = max(ans[2 * cc[i]], i + 1);
    }
    if (pv[v] != -1) {
      int id_up = 0;
      while (cc[id_up] != up[v]) {
        ++id_up;
      }
      int first = -1;
      int second = -1;
      for (int i = 0; i < sz; i++) {
        if (i == id_up) {
          continue;
        }
        if (first == -1) {
          first = cc[i];
        } else {
          second = cc[i];
          break;
        }
      }
      int ptr = 0;
      for (int h = second; h >= 1; h--) {
        while (ptr < sz && cc[ptr] >= h) {
          ++ptr;
        }
        int realz = ptr - (id_up < ptr);
        auto iter = lower_bound(vcc[pv[v]].begin(), vcc[pv[v]].end(), h);
        realz += (int) (vcc[pv[v]].end() - iter) - 1;
        ans[2 * h] = max(ans[2 * h], realz);
      }
    }
    vcc[v] = cc;
    reverse(vcc[v].begin(), vcc[v].end());
    for (int u : children) {
      if (cc[0] == down[u] + 1) {
        up[u] = cc[1] + 1;
      } else {
        up[u] = cc[0] + 1;
      }
    }
  }
  for (int i = n; i >= 3; i--) {
    ans[i - 2] = max(ans[i - 2], ans[i]);
  }
  for (int i = 1; i <= n; i++) {
    if (i > 1) {
      cout << " ";
    }
    cout << ans[i];
  }
  cout << '\n';
  return 0;
}