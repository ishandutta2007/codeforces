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
  vector<int> kek;
  for (int a = 3; a * a <= 2e9; a += 2) {
    kek.pb((a * a + 1) / 2);
  }
  while (T--) {
    int n;
    cin >> n;
    cout << upper_bound(all(kek), n) - kek.begin() << '\n';
  }
}