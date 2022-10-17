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
    vector<int> srt, a(n), b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
      srt.pb(a[i]);
      srt.pb(b[i]);
    }
    sort(all(srt));
    srt.resize(unique(all(srt)) - srt.begin());
    for (int i = 0; i < n; i++) {
      a[i] = upper_bound(all(srt), a[i]) - srt.begin();
      b[i] = upper_bound(all(srt), b[i]) - srt.begin();
    }
    vector<pair<int, int>> ph(SZ(srt) + 1, make_pair(1e9, -1)), pw(SZ(srt) + 1, make_pair(1e9, -1));
    for (int i = 0; i < n; i++) {
      ph[a[i]] = min(ph[a[i]], {b[i], i});
      pw[b[i]] = min(pw[b[i]], {a[i], i});
    }
    for (int i = 1; i <= SZ(srt); i++) {
      ph[i] = min(ph[i], ph[i - 1]);
      pw[i] = min(pw[i], pw[i - 1]);
    }
    for (int i = 0; i < n; i++) {
      if (ph[a[i] - 1].F < b[i]) {
        cout << ph[a[i] - 1].S + 1 << ' ';
      }
      else if (pw[a[i] - 1].F < b[i]) {
        cout << pw[a[i] - 1].S + 1 << ' ';
      }
      else {
        cout << -1 << ' ';
      }
    }
    cout << '\n';
  }
}