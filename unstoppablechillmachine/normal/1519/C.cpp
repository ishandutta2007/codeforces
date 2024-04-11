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
 
const int N = 2e5 + 10;
int id[N], vl[N];
vector<int> have[N], pref[N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> id[i];
    }
    for (int i = 1; i <= n; i++) {
      have[i] = {};
      pref[i] = {};
    }
    for (int i = 0; i < n; i++) {
      cin >> vl[i];
      have[id[i]].pb(vl[i]);
    }
    for (int i = 1; i <= n; i++) {
      if (have[i].empty()) {
        continue;
      }
      sort(have[i].rbegin(), have[i].rend());
      pref[i].resize(SZ(have[i]));
      pref[i][0] = have[i][0];
      for (int j = 1; j < SZ(have[i]); j++) {
        pref[i][j] = pref[i][j - 1] + have[i][j]; 
      }
    }
    set<int> interesting;
    for (int i = 1; i <= n; i++) {
      if (SZ(have[i]) > 0) {
        interesting.insert(i);
      }
    }
    for (int k = 1; k <= n; k++) {
      vector<int> to_del;
      int sum = 0;
      for (auto i : interesting) {
        if (SZ(have[i]) < k) {
          to_del.pb(i);
        }
        else {
          int kk = SZ(have[i]) - SZ(have[i]) % k;
          sum += pref[i][kk - 1];
        }
      }
      cout << sum << ' ';
      for (auto it : to_del) {
        interesting.erase(it);
      }
    }
    cout << '\n';
  }
}