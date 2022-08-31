/**
 *    author:  tourist
 *    created: 27.09.2020 19:10:12       
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

class matching {
 public:
  vector<vector<int>> g;
  vector<vector<int>> g_rev;
  vector<int> pa;
  vector<int> pb;
  vector<int> was_a;
  vector<int> was_b;
  vector<bool> imp_a;
  vector<bool> imp_b;
  int n, m;
  int res;
  int iter;

  matching(int _n, int _m) : n(_n), m(_m) {
    assert(0 <= n && 0 <= m);
    pa = vector<int>(n, -1);
    pb = vector<int>(m, -1);
    was_a = vector<int>(n, 0);
    was_b = vector<int>(m, 0);
    imp_a = vector<bool>(n, false);
    imp_b = vector<bool>(m, false);
    g.resize(n);
    g_rev.resize(m);
    res = 0;
    iter = 0;
  }

  void add(int from, int to) {
    assert(0 <= from && from < n && 0 <= to && to < m);
    g[from].push_back(to);
    g_rev[to].push_back(from);
  }

  bool dfs(int v) {
    was_a[v] = iter;
    for (int u : g[v]) {
      if (pb[u] == -1) {
        pa[v] = u;
        pb[u] = v;
        return true;
      }
    }
    for (int u : g[v]) {
      if (was_a[pb[u]] != iter && dfs(pb[u])) {
        pa[v] = u;
        pb[u] = v;
        return true;
      }
    }
    return false;
  }

  bool dfs_rev(int v) {
    was_b[v] = iter;
    for (int u : g_rev[v]) {
      if (pa[u] == -1) {
        pb[v] = u;
        pa[u] = v;
        return true;
      }
    }
    for (int u : g_rev[v]) {
      if (was_b[pa[u]] != iter && dfs_rev(pa[u])) {
        pb[v] = u;
        pa[u] = v;
        return true;
      }
    }
    return false;
  }

  int solve() {
    while (true) {
      int add = 0;
      iter++;
      for (int i = 0; i < n; i++) {
        if (imp_a[i] && pa[i] == -1 && dfs(i)) {
          add++;
        }
      }
      for (int i = 0; i < m; i++) {
        if (imp_b[i] && pb[i] == -1 && dfs_rev(i)) {
          add++;
        }
      }
      if (add == 0) {
        break;
      }
      res += add;
    }
    return res;
  }

  int run_one(int v) {
    if (pa[v] != -1) {
      return 0;
    }
    iter++;
    return (int) dfs(v);
  }
};

const int di[4] = {-1, 0, 1, 0};
const int dj[4] = {0, -1, 0, 1};
const string let = "ULDR";

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        cin >> a[i][j];
      }
    }
    vector<vector<int>> id(h, vector<int>(w, -1));
    vector<int> cnt(2);
    for (int rot = 0; rot < 2; rot++) {
      cnt[rot] = 0;
      for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
          if ((i + j) % 2 == rot) {
            id[i][j] = cnt[rot];
            cnt[rot] += 1;
          }
        }
      }
    }
    matching mat(cnt[0], cnt[1]);
    vector<vector<bool>> critical(h, vector<bool>(w, true));
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        for (int dir = 0; dir < 4; dir++) {
          int ni = i + di[dir];
          int nj = j + dj[dir];
          if (ni >= 0 && nj >= 0 && ni < h && nj < w) {
            if (a[ni][nj] < a[i][j]) {
              critical[i][j] = false;
            }
          }
        }
        if (critical[i][j]) {
          if ((i + j) % 2 == 0) {
            mat.imp_a[id[i][j]] = true;
          } else {
            mat.imp_b[id[i][j]] = true;
          }
        }
      }
    }
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (critical[i][j] && (i + j) % 2 == 0) {
          for (int dir = 0; dir < 4; dir++) {
            int ni = i + di[dir];
            int nj = j + dj[dir];
            if (ni >= 0 && nj >= 0 && ni < h && nj < w) {
              if (a[i][j] == a[ni][nj] && critical[ni][nj]) {
                mat.add(id[i][j], id[ni][nj]);
              }
            }
          }
        }
      }
    }
    mat.solve();
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if ((i + j) % 2 == 0) {
          for (int dir = 0; dir < 4; dir++) {
            int ni = i + di[dir];
            int nj = j + dj[dir];
            if (ni >= 0 && nj >= 0 && ni < h && nj < w) {
              if (a[i][j] == a[ni][nj]) {
                if (critical[i][j] != critical[ni][nj]) {
                  mat.add(id[i][j], id[ni][nj]);
                }
              }
            }
          }
        }
      }
    }
    mat.solve();
    bool ok = true;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if ((i + j) % 2 == 0) {
          if (critical[i][j] && mat.pa[id[i][j]] == -1) {
            ok = false;
          }
        } else {
          if (critical[i][j] && mat.pb[id[i][j]] == -1) {
            ok = false;
          }
        }
      }
    }
    if (!ok) {
      cout << "NO" << '\n';
      continue;
    }
    cout << "YES" << '\n';
    vector<vector<int>> cost(h, vector<int>(w, -1));
    vector<vector<char>> go(h, vector<char>(w, '?'));
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if ((i + j) % 2 == 0 && mat.pa[id[i][j]] != -1) {
          for (int dir = 0; dir < 4; dir++) {
            int ni = i + di[dir];
            int nj = j + dj[dir];
            if (ni >= 0 && nj >= 0 && ni < h && nj < w) {
              if (mat.pa[id[i][j]] == id[ni][nj]) {
                go[i][j] = let[dir];
                go[ni][nj] = let[dir ^ 2];
                cost[i][j] = 1;
                cost[ni][nj] = a[i][j] - 1;
              }
            }
          }
        }
      }
    }
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (cost[i][j] == -1) {
          for (int dir = 0; dir < 4; dir++) {
            int ni = i + di[dir];
            int nj = j + dj[dir];
            if (ni >= 0 && nj >= 0 && ni < h && nj < w) {
              if (a[ni][nj] < a[i][j]) {
                go[i][j] = let[dir];
                cost[i][j] = a[i][j] - a[ni][nj];
                break;
              }
            }
          }
        }
      }
    }
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        assert(go[i][j] != '?' && cost[i][j] != -1);
      }
    }
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (j > 0) {
          cout << " ";
        }
        cout << cost[i][j];
      }
      cout << '\n';
    }
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (j > 0) {
          cout << " ";
        }
        cout << go[i][j];
      }
      cout << '\n';
    }
  }
  return 0;
}