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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) {
      cin >> x;
    }
    if (k == 1) {
       cout << (a[0] == a.back() ? 1 : -1) << '\n';
       continue;
    }
    int answer = 0;
    while (a.back() != 0) {
      answer++;
      int curv = a[0], cnt_unique = 1;
      a[0] = 0;
      for (int i = 1; i < n; i++) {
        if (a[i] == curv) {
          a[i] = 0;
        }
        else {
          if (cnt_unique < k) {
            cnt_unique++;
            curv = a[i];
          }
          a[i] -= curv;
        }
      } 
    }
    cout << max(1ll, answer) << '\n';
  }   
}