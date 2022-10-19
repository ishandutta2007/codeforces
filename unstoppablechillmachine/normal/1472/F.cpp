#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back  
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
 
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> have(2);
    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;
      a--;
      have[a].pb(b);
    }
    sort(all(have[0]));
    sort(all(have[1]));
    if ((SZ(have[0]) + SZ(have[1])) % 2 == 1) {
      cout << "NO\n";
      continue;
    }
    int ptr0 = 0, ptr1 = 0;
    bool ok = true;
    for (int i = 0; i < (SZ(have[0]) + SZ(have[1])) / 2; i++) {
      if (ptr0 < SZ(have[0]) && (ptr1 >= SZ(have[1]) || have[0][ptr0] <= have[1][ptr1])) {
        ptr0++;
        if (ptr1 < SZ(have[1]) && (ptr0 >= SZ(have[0]) || have[1][ptr1] < have[0][ptr0])) {
          if ((have[1][ptr1] - have[0][ptr0 - 1]) % 2 == 1) {
            ok = false;
            break;
          }
          ptr1++;
        }
        else if (ptr0 < SZ(have[0]) && (ptr1 >= SZ(have[1]) || have[0][ptr0] < have[1][ptr1])) {
          if ((have[0][ptr0] - have[0][ptr0 - 1]) % 2 == 0) {
            ok = false;
            break;
          }
          ptr0++;
        }
        else {
          ok = false;
          break;
        }
      }
      else {
        ptr1++;
        if (ptr0 < SZ(have[0]) && (ptr1 >= SZ(have[1]) || have[0][ptr0] < have[1][ptr1])) {
          if ((have[0][ptr0] - have[1][ptr1 - 1]) % 2 == 1) {
            ok = false;
            break;
          }
          ptr0++;
        }
        else if (ptr1 < SZ(have[1]) && (ptr0 >= SZ(have[0]) || have[1][ptr1] < have[0][ptr0])) {
          if ((have[1][ptr1] - have[1][ptr1 - 1]) % 2 == 0) {
            ok = false;
            break;
          }
          ptr1++;
        }
        else {
          ok = false;
          break;
        }
      }
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}