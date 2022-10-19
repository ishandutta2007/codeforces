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

void source() {
  int n, k;
  cin >> n >> k;
  if (n > k * (k - 1)) {
    cout << "NO";
    exit(0);
  }
  cout << "YES\n";
  for (int i = 1; i <= k; i++) {
    for (int j = i + 1; j <= k; j++) {
      cout << i << ' ' << j << '\n';
      n--;
      if (n == 0) {
        exit(0);
      }
      cout << j << ' ' << i << '\n';
      n--;
      if (n == 0) {
        exit(0);
      }
    } 
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