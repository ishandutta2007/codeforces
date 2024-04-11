//author: extraterrestrial_
#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,avx,tune=native")
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define _ inline
#define pb push_back
#define int ll
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

const int N = 2e5 + 10;
const int root = 1;
map<char, int> mp[N];
int cnt = 1;
bool win[N], lose[N];

void add(string s) {
  int v = root;
  for (int i = 0; i < SZ(s); i++) {
    if (!mp[v][s[i]]) {
      mp[v][s[i]] = ++cnt;
    }
    v = mp[v][s[i]];
  }
}

void dfs(int v) {
  win[v] = false;
  for (auto u : mp[v]) {
    dfs(u.S);
    if (!win[u.S]) {
      win[v] = true;
    }
  }
}

void dfs2(int v) {
  if (mp[v].empty()) {
    lose[v] = true;
    return;
  }
  lose[v] = false;
  for (auto u : mp[v]) {
    dfs2(u.S);
    if (!lose[u.S]) {
      lose[v] = true;
    }
  }
}

void source() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    add(s);
  }
  dfs(root);
  if (win[root]) {
    if (k & 1) {
      cout << "First";
    }
    else {
      dfs2(root);
      cout << (lose[root] ? "First" : "Second");
    }
  }
  else {
    cout << "Second";
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