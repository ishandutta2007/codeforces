//author: extraterrestrial_
#include <bits/stdc++.h>
//#pragma GCC optimize("O3,Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,avx,tune=native")
using namespace std;
#define int ll
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define _ inline
#define pb push_back
#define F first
#define S second
#define MP make_pair
#define SZ(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pw(x) (1ll << (x))
#ifdef extraterrestrial_
  #define debug(x) cerr << #x << ": " << x << '\n';
#else
  #define debug(x)
#endif
const int INF = 1e9 + 10;
const ll BINF = 1e18 + 10;

const int lim = 70 * 70;
const int N = 1e5 + 10;
bool used[N], was[N];
vector<int> g[N];
int edge[71 * 71][71 * 71];
int p[N];
pair<char, char> vl[N];

void dfs(int v) {
  used[v] = true;
  for (auto u : g[v]) {
    if (!used[u]) {
      dfs(u);
    }
  }
}

int f(char c) {
  if (c >= 'a' && c <= 'z') {
    return c - 'a';
  }
  if (c >= 'A' && c <= 'Z') {
    return int(c - 'A') + 26;
  }
  return 52 + (c - '0');
}

int get(char a, char b) {
  return f(a) * 65 + f(b);
}

void source() {
  int n;
  cin >> n;
  bool dif = false;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int a = get(s[0], s[1]), b = get(s[1], s[2]);
    g[a].pb(b);
    p[b]++;
    was[a] = was[b] = true;
    vl[a] = {s[0], s[1]};
    vl[b] = {s[1], s[2]};
    edge[a][b]++;
    if (a != b) {
      dif = true;
    }
  }
  int from = -1, to = -1, last = -1;
  for (int i = 0; i <= lim; i++) {
    if (!was[i]) {
      continue;
    }
    last = i;
    if (SZ(g[i]) != p[i]) {
      if (SZ(g[i]) > p[i]) {
        if (from == -1) {
          from = i;
        }
        else {
          cout << "NO\n";
          exit(0);
        }
      }
      else {
        if (to == -1) {
          to = i;
        }
        else {
          cout << "NO\n";
          exit(0);
        }
      }
    }
    if (!used[i]) {
      dfs(i);
    }
  }  
  if (from == -1) {
    from = last;
  }
  vector<int> S;
  S.pb(from);
  vector<int> ans;
  while (!S.empty()) {
    int cur = S.back();
    if (g[cur].empty()) {
      ans.pb(cur);
      S.pop_back();
    }
    else {
      S.pb(g[cur].back());
      g[cur].pop_back();
    }
  }
  reverse(all(ans));
  for (int i = 0; i + 1 < SZ(ans); i++) {
    if (edge[ans[i]][ans[i + 1]] == 0) {
      cout << "NO\n";
      exit(0);
    }
    edge[ans[i]][ans[i + 1]]--;
  }
  if (SZ(ans) < n + 1) {
    cout << "NO\n";
    exit(0);
  }
  cout << "YES\n";
  cout << vl[ans[0]].F;
  for (auto v : ans) {
    cout << vl[v].S;
  }
}

signed main() {
#ifdef extraterrestrial_
  assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#else
#define TASK ""
  //assert(freopen(TASK".in", "r", stdin));
  //assert(freopen(TASK".out", "w", stdout));
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  source();
#ifdef extraterrestrial_
  cerr << "\n\nTIME :: " << clock() * 1.0 / CLOCKS_PER_SEC;
#endif
  return 0;
}