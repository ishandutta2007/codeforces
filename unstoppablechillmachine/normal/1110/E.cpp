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
  vector<int> a(n + 1), b(n + 1), arr1, arr2;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    arr1.pb(a[i] - a[i - 1]);
  }  
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    arr2.pb(b[i] - b[i - 1]);
  }
  sort(all(arr1));
  sort(all(arr2));
  cout << ((a[1] == b[1] && arr1 == arr2) ? "Yes" : "No");
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