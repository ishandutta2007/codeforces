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
 
const int M = 5e6 + 10;
vector<pair<int, int>> cur[M];
int cnt[M];

mt19937 rnd(time(0));

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> kek;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (cnt[x] < 4) {
      cnt[x]++;
      kek.pb({x, i + 1});
    }
  }
  shuffle(all(kek), rnd);
  for (int i = 0; i < SZ(kek); i++) {
    for (int j = i + 1; j < SZ(kek); j++) {
      int vl = kek[i].F + kek[j].F;
      for (auto it : cur[vl]) {
        if (it.F != kek[i].S && it.F != kek[j].S && it.S != kek[i].S && it.S != kek[j].S) {
          cout << "YES\n";
          cout << it.F << ' ' << it.S << ' ' << kek[i].S << ' ' << kek[j].S << '\n';
          exit(0);
        }
      }
      cur[vl].pb({kek[i].S, kek[j].S});
    }
  }
  cout << "NO\n";
}