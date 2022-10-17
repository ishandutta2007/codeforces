#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
#define F first
#define S second

const int N = 2e5 + 10;
int a[N], lst[N], suf[N];

signed main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int m;
  cin >> m;
  for (int i = 1; i <= m; i++) {
    int type;
    cin >> type;
    if (type == 1) {
      int id, nw;
      cin >> id >> nw;
      a[id] = nw;
      lst[id] = i;
    }
    else {
      int x;
      cin >> x;
      suf[i] = x;
    }
  }
  for (int i = m - 1; i >= 1; i--) {
    suf[i] = max(suf[i], suf[i + 1]);
  }  
  for (int i = 1; i <= n; i++) {
    cout << max(a[i], suf[lst[i] + 1]) << ' ';
  }
  cout << '\n';
}