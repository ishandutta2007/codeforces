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

const int INF = 1e9 + 10;

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
    for (auto &it : a) {
      cin >> it;
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      b[(i + a[i] + n * INF) % n]++;
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (b[i] != 1) {
        ok = false;
      }
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}