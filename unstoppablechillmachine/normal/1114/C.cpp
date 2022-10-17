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
const int MOD = 1e9 + 7;

const int BINF = 1e18 + 10;

void source() {
  int n, b;
  cin >> n >> b;
  unordered_map<int, int> cnt;
  for (int i = 2; i * i <= b; i++) {
    while (b % i == 0) {
      cnt[i]++;
      b /= i;
    }
  }
  if (b > 1) {
    cnt[b]++;
  }
  int ans = BINF;
  for (auto it : cnt) {
    int vh = 0, cur = it.F;
    while (cur <= n) {
      vh += n / cur;
      if (n / cur == 0) {
        break;
      }
      if (n / cur < it.F) {
        break;
      }
      cur *= it.F;
    }
    ans = min(ans, vh / it.S);
  }
  cout << ans;
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