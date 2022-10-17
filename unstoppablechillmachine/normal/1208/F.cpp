#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
#define F first
#define S second
 
void update(pair<int, int> &a, int b) {
  if (b > a.F) {
    a.S = a.F;
    a.F = b;
  }
  else if (b > a.S) {
    a.S = b;
  }
}

const int N = 2e6 + 10;
const int MX = 20;
int a[N], used[N];

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> kek(2e6 + 1, make_pair(-1, -1));
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    kek[a[i]].S = kek[a[i]].F;
    kek[a[i]].F = i;
  }
  int timer = 0;
  for (int i = 2e6; i >= 0; i--) {
    timer++;
    if (kek[i].F != -1) {
      used[kek[i].F] = timer;
    }
    if (kek[i].S != -1) {
      used[kek[i].S] = timer;
    }
    for (int j = 0; j <= MX; j++) {
      if ((i >> j) & 1) {
        continue;
      }
      int to = i | (1 << j);
      if (to > 2e6) {
        continue;
      }
      if (kek[to].F != -1 && used[kek[to].F] < timer) {
        used[kek[to].F] = timer;
        update(kek[i], kek[to].F);
      }
      if (kek[to].S != -1 && used[kek[to].S] < timer) {
        used[kek[to].S] = timer;
        update(kek[i], kek[to].S);
      }
    }
  }
  int ans = 0;
  for (int i = 1; i + 2 <= n; i++) {
    int cur_mask = 0;
    for (int j = MX; j >= 0; j--) {
      if ((a[i] >> j) & 1) {
        continue;
      }
      if (kek[cur_mask | (1 << j)].S > i) {
        cur_mask |= 1 << j;
      }
    }
    ans = max(ans, a[i] | cur_mask);
  }
  cout << ans << '\n';
}