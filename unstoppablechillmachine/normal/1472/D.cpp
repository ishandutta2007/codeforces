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
    int n;
    cin >> n;
    vector<vector<int>> have(2);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      have[x % 2].pb(x);
    }
    sort(all(have[0]));
    sort(all(have[1]));
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0) {
        if (!have[0].empty() && (have[1].empty() || have[0].back() > have[1].back())) {
          sum1 += have[0].back();
          have[0].pop_back();
        }
        else {
          have[1].pop_back();
        }
      }
      else {
        if (!have[1].empty() && (have[0].empty() || have[1].back() > have[0].back())) {
          sum2 += have[1].back();
          have[1].pop_back();
        }
        else {
          have[0].pop_back();
        }
      }
    }
    if (sum1 > sum2) {
      cout << "Alice\n";
    }
    else if (sum1 == sum2) {
      cout << "Tie\n";
    }
    else {
      cout << "Bob\n";
    }
  }
}