//author: extraterrestrial_
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
typedef long double ld;
#define int ll
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define pii pair<int, int>
const int INF = 1e9 + 10;
const ll BINF = 1e18 + 10;

void source() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (auto &it : a) {
    cin >> it;
  }
  int l = -1, r = m;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    int cr = 0;
    for (auto it : a) {
      if (m - it + cr <= mid) {
        continue;
      }
      if (it >= cr) {
        cr = it;
      }
      else {
        if (cr - it > mid) {
          cr = INF;
          break;
        }
      }
    }
    if (cr == INF) {
      l = mid;
    }
    else {
      r = mid;
    }
  }
  cout << r;
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