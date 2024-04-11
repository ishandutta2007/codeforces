/**
 *    author:  tourist
 *    created: 16.04.2021 18:25:16       
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

void my_assert(bool x) {
  if (!x) {
    cout << "NO" << '\n';
    exit(0);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> pos(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    --a[i];
    pos[a[i]] = i;
  }
  vector<vector<int>> g(n);
  vector<int> pv(n, -1);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    g[u].push_back(v);
    pv[v] = u;
  }
  vector<int> depth(n);
  function<void(int)> Dfs = [&](int v) {
    for (int u : g[v]) {
      depth[u] = depth[v] + 1;
      Dfs(u);
    }
  };
  depth[0] = 0;
  Dfs(0);
  vector<int> deg(n);
  for (int i = 0; i < n; i++) {
    deg[i] = (int) g[i].size();
  }
  vector<int> aux = a;
  long long ans = 0;
  vector<bool> used(n, false);
  vector<int> post;
  for (int i = 0; i < n; i++) {
    int v = pos[i];
    ans += depth[v];
    if (deg[v] == 0) {
      used[v] = true;
      post.push_back(v);
      if (pv[v] != -1) {
        deg[pv[v]] -= 1;
      }
      continue;
    }
    while (v != 0) {
      swap(aux[v], aux[pv[v]]);
      v = pv[v];
    }
    break;
  }
  function<void(int)> Restore = [&](int v) {
    if (used[v]) {
      return;
    }
    sort(g[v].begin(), g[v].end(), [&](int i, int j) {
      return aux[i] < aux[j];
    });
    for (int u : g[v]) {
      Restore(u);
    }
    post.push_back(v);
  };
  Restore(0);
  my_assert((int) post.size() == n);
  vector<int> pos_post(n, -1);
  for (int i = 0; i < n; i++) {
    pos_post[post[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    my_assert(pos_post[i] != -1);
  }
  vector<int> pre;
  function<void(int)> Build = [&](int v) {
    pre.push_back(v);
    sort(g[v].begin(), g[v].end(), [&](int i, int j) {
      return pos_post[i] < pos_post[j];
    });
    for (int u : g[v]) {
      Build(u);
    }
  };
  Build(0);
  my_assert((int) pre.size() == n);
  vector<int> pos_pre(n, -1);
  for (int i = 0; i < n; i++) {
    pos_pre[pre[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    my_assert(pos_pre[i] != -1);
  }
  vector<int> new_post;
  function<void(int)> BuildAgain = [&](int v) {
    sort(g[v].begin(), g[v].end(), [&](int i, int j) {
      return pos_pre[i] < pos_pre[j];
    });
    for (int u : g[v]) {
      BuildAgain(u);
    }
    new_post.push_back(v);
  };
  BuildAgain(0);
  debug(post);
  debug(pre);
  debug(new_post);
  debug(ans);
  my_assert(post == new_post);
  vector<int> mark(n, -1);
  long long got = 0;
  for (int i = 0; i < n; i++) {
    int v = post[i];
    if (got + depth[v] <= ans) {
      got += depth[v];
      mark[v] = i;
      continue;
    }
    vector<int> foo;
    for (int j = 0; j < n; j++) {
      if (mark[j] == -1) {
        foo.push_back(j);
      }
    }
    my_assert((int) foo.size() == n - i);
    sort(foo.begin(), foo.end(), [&](int ii, int j) {
      return pos_pre[ii] < pos_pre[j];
    });
    for (int j = 0; j < n - i; j++) {
      mark[foo[j]] = i + j;
    }
    long long extra = got + depth[v] - ans;
    int me = v;
    debug(me, extra);
    while (extra > 0) {
      my_assert(pv[me] != -1);
      me = pv[me];
      extra -= 1;
    }
    vector<int> path;
    while (me != -1) {
      path.push_back(me);
      me = pv[me];
    }
    reverse(path.begin(), path.end());
    for (int j = 0; j < (int) path.size() - 1; j++) {
      swap(mark[path[j]], mark[path[j + 1]]);
    }
    got = ans;
    break;
  }
  my_assert(got == ans);
  for (int i = 0; i < n; i++) {
    my_assert(mark[i] == a[i]);
  }
  cout << "YES" << '\n';
  cout << ans << '\n';
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << pos_pre[i] + 1;
  }
  cout << '\n';
  return 0;
}