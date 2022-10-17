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
const int MOD = 1e9 + 7;

const ll BINF = 1e18 + 10;

const int N = 1e5 + 10;
int n;
pair<int, int> pref[N];
pair<int, int> get(int x) {
  return {pref[n].F * (x / n) + pref[x % n].F, pref[n].S * (x / n) + pref[x % n].S};
}

void source() {
  int x, y, x2, y2;
  cin >> x >> y >> x2 >> y2;
  int dx = x2 - x, dy = y2 - y;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    char c;
    cin >> c;
    pref[i] = pref[i - 1];
    if (c == 'L') {
      pref[i].F--;
    }
    if (c == 'R') {
      pref[i].F++;
    }
    if (c == 'D') {
      pref[i].S--;
    }
    if (c == 'U') {
      pref[i].S++;
    }
  }
  int l = -1, r = BINF;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    pair<int, int> kek = get(mid);
    int cx = abs(dx - kek.F), cy = abs(dy - kek.S);
    //cout << cx << ' ' << cy << ' ' << mid << '\n';
    if (cx + cy <= mid) {
      r = mid;
    }
    else {
      l = mid;
    }
  }
  if (r == BINF) {
    cout << -1;
  }
  else {
    cout << r;
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
  //assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  source();
  return 0;
}