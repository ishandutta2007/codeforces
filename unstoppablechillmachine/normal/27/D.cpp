//author: extraterrestrial_
#include <bits/stdc++.h>
//#pragma GCC optimize("O3,Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,avx,tune=native")
using namespace std;
//#define int ll
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

const int N = 110;
vector<int> g[N];
bool used[N];
int c[N];

int intersect(pii A, pii B, int n) {
  if (A.F == B.F || A.F == B.S || A.S == B.F || A.S == B.S) {
    return false;
  }
  vector<int> kek(n + 1);
  while (A.F != A.S) {
    kek[A.F] = 1;
    A.F++;
    if (A.F > n) {
      A.F = 1;
    }
  }
  return kek[B.F] ^ kek[B.S];
}

void dfs(int v, int color) {
  used[v] = true;
  c[v] = color;
  for (auto u : g[v]) {
    if (!used[u]) {
      dfs(u, color ^ 1);
    }
    else if (c[v] == c[u]) {
      cout << "Impossible";
      exit(0);
    }
  }
}

void source() {
  int n, m;
  cin >> n >> m;
  vector<pii> seg(m + 1);
  for (int i = 1; i <= m; i++) {
    cin >> seg[i].F >> seg[i].S;
  }
  for (int i = 1; i <= m; i++) {
    for (int j = i + 1; j <= m; j++) {
      if (intersect(seg[i], seg[j], n)) {
        g[i].pb(j);
        g[j].pb(i);
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    if (!used[i]) {
      dfs(i, 0);
    }
  }
  for (int i = 1; i <= m; i++) {
    cout << (c[i] ? 'i' : 'o');
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