#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back  
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
 
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
 
#ifdef PC
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
 
const int N = 3e5 + 10;
int t[4 * N], f[4 * N];
 
void push(int v) {
  if (f[v] != -1) {
    f[2 * v] = f[2 * v + 1] = t[2 * v] = t[2 * v + 1] = f[v];
    f[v] = -1;
  }
}
 
void update(int v, int l, int r, int a, int b, int val) {
  if (l > b || r < a) {
    return;
  }
  if (l >= a && r <= b) {
    f[v] = val;
    t[v] = val;
    return;
  }
  push(v);
  int mid = (l + r) / 2;
  update(2 * v, l, mid, a, b, val);
  update(2 * v + 1, mid + 1, r, a, b, val);
  t[v] = max(t[2 * v], t[2 * v + 1]);
}
 
/*void update(int v, int l, int r, int a, int b, int val) {
  for (int i = a; i <= b; i++) {
    t[i] = val;
  }
}*/
 
int get_max(int v, int l, int r, int a, int b) {
  if (l > b || r < a) {
    return 0;
  }
  if (l >= a && r <= b) {
    return t[v];
  }
  push(v);
  int mid = (l + r) / 2;
  return max(get_max(2 * v, l, mid, a, b), get_max(2 * v + 1, mid + 1, r, a, b));
  /*int result = 0;
  for (int i = a; i <= b; i++) {
    result = max(result, t[i]);
  }
  return result;*/
}
 
vector<int> g1[N], g2[N];
int pos[N], sz[N], timer, n;
 
void precalc(int v, int parent) {
  pos[v] = ++timer;
  sz[v] = 1;
  for (auto u : g2[v]) {
    if (u != parent) {
      precalc(u, v);
      sz[v] += sz[u];
    }
  }
  debug(v, pos[v], sz[v]);
}
 
int lst[N];
 
inline void apply(int v, int& cur_sum) {
  int colorv_v = get_max(1, 1, n, pos[v], pos[v]), color_subtree = get_max(1, 1, n, pos[v], pos[v] + sz[v] - 1);
  debug(colorv_v, color_subtree);
  if (color_subtree == 0) {
    debug(v, "CASE 1");
    update(1, 1, n, pos[v], pos[v] + sz[v] - 1, v);
    cur_sum++;
  }
  else {
    if (colorv_v != 0) {
      debug(v, "CASE 2");
      update(1, 1, n, pos[colorv_v], pos[colorv_v] + sz[colorv_v] - 1, 0);
      update(1, 1, n, pos[v], pos[v] + sz[v] - 1, v);
      lst[v] = colorv_v;
    } else {
      debug(v, "CASE 3");
    }
  }
}
 
inline void undo(int v, int& cur_sum) {
  if (get_max(1, 1, n, pos[v], pos[v] + sz[v] - 1) == v) {
    update(1, 1, n, pos[v], pos[v] + sz[v] - 1, 0);
    cur_sum--;
    if (lst[v] != 0) {
      update(1, 1, n, pos[lst[v]], pos[lst[v]] + sz[lst[v]] - 1, lst[v]);
      cur_sum++;
    }
  }
  lst[v] = 0;
}
 
int mx;
 
void dfs(int v, int parent, int& cur_sum) {
  apply(v, cur_sum);
  debug(v, cur_sum);
  mx = max(mx, cur_sum);
  for (auto u : g1[v]) {
    if (u != parent) {
      dfs(u, v, cur_sum);
    }
  }
  undo(v, cur_sum);
}
 
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= 4 * n + 5; i++) {
      f[i] = -1;
      t[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
      g1[i] = {};
      g2[i] = {};
    }
    for (int i = 1; i < n; i++) {
      int p;
      cin >> p;
      g1[p].pb(i + 1);
    }
    for (int i = 1; i < n; i++) {
      int p;
      cin >> p;
      g2[p].pb(i + 1);
    }
    timer = 0;
    precalc(1, 0);
    mx = 0;
    int cur_sum = 0;
    dfs(1, 0, cur_sum);
    cout << mx << '\n';
  }
}