//author: extraterrestrial_
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
typedef long double ld;
//#define int ll
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define pii pair<int, int>
const int INF = 1e9 + 10;
const ll BINF = 1e18 + 10;

const int LOG = 20;

void source() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<vector<int>> nxt(n + 2, vector<int>(LOG, n + 1));
  vector<int> lst(LOG, n + 1);
  for (int i = n; i >= 1; i--) {
    for (int j = 0; j < LOG; j++) {
      for (int j2 = 0; j2 < LOG; j2++) {
        if ((a[i] >> j2) & 1) {
          nxt[i][j] = min(nxt[i][j], nxt[lst[j2]][j]);
        }
      }
      if ((a[i] >> j) & 1) {
        nxt[i][j] = i;
      }
    }
    for (int j = 0; j < LOG; j++) {
      if ((a[i] >> j) & 1) {
        lst[j] = i;
      }
    }
  }
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    bool ok = false;
    for (int j = 0; j < LOG; j++) {
      if (((a[y] >> j) & 1) && nxt[x][j] <= y) {
        ok = true;
        break;
      } 
    }
    cout << (ok ? "Shi" : "Fou") << '\n';
  }
} 
     
signed main() {
#ifdef extraterrestrial_
  assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output2.txt", "w", stdout));
#else
#define TASK ""
  //assert(freopen(TASK".in", "r", stdin));
  //assert(freopen(TASK".out", "w", stdout));
  //assert(freopenpen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
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