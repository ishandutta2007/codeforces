//author: extraterrestrial_
#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,avx,tune=native")
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

const int N = 1510;
char arr[N][N];
pii used[N][N];
int n, m;
vector<pii> delta = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs(pii v, pii add = {1, 1}) {
  used[v.F][v.S] = add;
  for (auto it : delta) {
    pii u = {it.F + v.F, it.S + v.S};
    pii add2 = add;
    if (u.F == 0) {
      u.F += n;
      add2.F += 3228; 
    }
    if (u.F > n) {
      u.F -= n;
      add2.F -= 3228;
    }
    if (u.S == 0) {
      u.S += m;
      add2.S += 3228;
    }
    if (u.S > m) {
      u.S -= m;
      add2.S -= 3228;
    }
    if (used[u.F][u.S] != MP(0, 0) && used[u.F][u.S] != add2) {
      cout << "Yes";
      exit(0);
    }
    if (used[u.F][u.S] == MP(0, 0) && arr[u.F][u.S] != '#') {
      dfs(u, add2);
    }
  }
}

void source() {
  cin >> n >> m;
  pii start;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == 'S') {
        start = {i, j};
      }
    }
  }  
  dfs(start);
  cout << "No";
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