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
const int MOD = 1e9 + 7;

void source() {
  int k;
  cin >> k;
  for (int len1 = 1; len1 <= 2000; len1++) {
    for (int len2 = len1 + 1; len2 <= 2000; len2++) {
      if ((k + len1) % (len2 - len1) == 0) {
        int sum = (k + len1) / (len2 - len1);
        if (sum + 1 <= len1 * 1e6) {
          cout << len2 << '\n';
          for (int i = 0; i < len2 - len1 - 1; i++) {
            cout << 0 << ' ';
          }
          cout << -1 << ' ';
          k = sum + 1;
          for (int j = 0; j < len1; j++) {
            if (k >= 1e6) {
              cout << 1000000 << ' ';
              k -= 1e6;
            }
            else {
              cout << k << ' ';
              k = 0;
            }
          }
          exit(0);
        }
      } 
    }
  }
  cout << -1;
}

signed main() {
#ifdef extraterrestrial_
  assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
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
  return 0;
}