#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  pair<int, int> best;
  int n;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    int vl = (i - 1) * (n / i - 1);
    if ((n % i) > 1) {
      vl += n % i - 1;
    }
    best = max(best, make_pair(vl, i));
  }
  int cur = 0;
  vector<bool> on(n + 1);
  for (;;) {
    if (cur >= best.F) {
      cout << 0 << endl;
      exit(0);
    }
    else {
      vector<int> kek;
      for (int i = 1; i <= n; i++) {
        if (i % best.S == 0) {
          continue;
        } 
        if (!on[i] && SZ(kek) < best.S) {
          kek.pb(i);
          on[i] = true;
        }
      }
      cout << SZ(kek);
      for (int id : kek) {
        cout << ' ' << id;
        cur++;
      }
      cout << endl;
      int pos;
      cin >> pos;
      for (int i = 0; i < SZ(kek); i++) {
        if (on[pos]) {
          cur--;
          on[pos] = false;
        }
        if (pos == n) {
          pos = 1;
        }
        else {
          pos++;
        }
      }
    }
  }
}