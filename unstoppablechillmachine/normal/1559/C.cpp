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
    vector<int> a(n);
    for (auto &x : a) {
      cin >> x;
    }
    if (a[0] == 1) {
      cout << n + 1 << ' ';
      for (int i = 1; i <= n; i++) {
        cout << i << ' ';
      }
      cout << '\n';
      continue;
    } 
    if (a.back() == 0) {
      for (int i = 1; i <= n; i++) {
        cout << i << ' ';
      }
      cout << n + 1 << '\n';
      continue;
    }
    int id = -1;
    for (int i = 0; i + 1 < n; i++) {
      if (a[i] == 0 && a[i + 1] == 1) {
        id = i + 1;
        break;
      }
    }
    assert(id != -1);
    for (int i = 1; i <= id; i++) {
      cout << i << ' ';
    }
    cout << n + 1 << ' ';
    for (int i = id + 1; i <= n; i++) {
      cout << i << ' ';
    }
    cout << '\n';
  }
}