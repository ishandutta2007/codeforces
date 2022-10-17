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
    vector<int> a(n), b(n), c(n);
    for (int &x : a) {
      cin >> x;
    }
    for (int &x : b) {
      cin >> x;
    }
    for (int &x : c) {
      cin >> x;
    }
    vector<int> rez(n, -1);
    for (int i = 0; i < n; i++) {
      int prv = (i - 1 + n) % n, nxt = (i + 1) % n;
      if (a[i] != rez[prv] && a[i] != rez[nxt]) {
        rez[i] = a[i];
      }
      else if (b[i] != rez[prv] && b[i] != rez[nxt]) {
        rez[i] = b[i];
      }
      else {
        rez[i] = c[i];
      }
    }
    for (int &x : rez) {
      cout << x << ' ';
    }
    cout << '\n';
  }   
}