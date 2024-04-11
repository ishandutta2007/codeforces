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

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int a, b;
    string s;
    cin >> a >> b >> s;
    bool win2 = false;
    int cur = 0;
    vector<int> arr;
    for (int i = 0; i < SZ(s); i++) {
      if (s[i] == 'X') {
        if (cur >= b) {
          if (cur < a) {
            win2 = true;
            break;
          }
          arr.pb(cur);
        }
        cur = 0;
      }
      else {
        cur++;
      }
    }
    if (cur >= b) {
      if (cur < a) {
        win2 = true;
      }
      else {
        arr.pb(cur);
      }
    }
    if (win2 || arr.empty()) {
      cout << "NO\n";
      continue;
    }
    sort(arr.rbegin(), arr.rend());
    if (SZ(arr) > 1 && arr[1] >= 2 * b) {
      cout << "NO\n";
      continue;
    }
    if (arr[0] < 2 * b) {
      cout << (SZ(arr) & 1 ? "YES\n" : "NO\n");
      continue;
    }
    bool ok = false;
    for (int x = 0; x + a <= arr[0]; x++) {
      int cnt = SZ(arr) - 1;
      int y = arr[0] - x - a;
      if (x >= 2 * b || y >= 2 * b || (x >= b && x < a) || (y >= b && y < a)) {
        continue;
      }
      if (x >= b) {
        assert(x >= a);
        assert(x < 2 * b);
        cnt++;
      }
      if (y >= b) {
        assert(y >= a);
        assert(y < 2 * b);
        cnt++;
      }
      if (cnt % 2 == 0) {
        ok = true;
        break;
      }
    }
    if (ok) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
  }  
}