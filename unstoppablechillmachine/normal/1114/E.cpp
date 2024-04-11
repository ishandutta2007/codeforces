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

mt19937 Random((int)time(0));

void source() {
  int n;
  cin >> n;
  int l = -1, r = 1e9;
  int cc = 60;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    cout << "> " << mid << endl;
    int x;
    cin >> x;
    if (x == 0) {
      r = mid;
    }
    else {
      l = mid;
    }
    cc--;
  }
  vector<int> arr;
  for (int i = 1; i < n; i++) {
    arr.pb(i);
  }
  vector<int> have;
  have.pb(r);
  shuffle(all(arr), Random);
  for (int i = 0; i < min(SZ(arr), cc); i++) {
    cout << "? " << arr[i] << endl;
    int val;
    cin >> val;
    have.pb(val);  
  }
  sort(all(have));
  int d = have[1] - have[0];
  for (int i = 1; i < SZ(have); i++) {
    d = __gcd(d, have[i] - have[i - 1]);
  }
  cout << "! " << r - (n - 1) * d << ' ' << d << endl;
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