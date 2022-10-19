#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
#define int ll
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define pii pair<int, int>
const int INF = 1e9 + 10;

void source() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto &it : arr) {
    cin >> it;
  }
  pii best = {INF, INF};
  for (int i = 1; i <= 100; i++) {
    int sum = 0;
    for (auto it : arr) {
      if (it == i) {
        continue;
      }
      if (it > i) {
        sum += it - i - 1;
      }
      else {
        sum += i - it - 1;
      }
    }
    best = min(best, make_pair(sum, i));
  }
  cout << best.S << ' ' << best.F;
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