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

const int N = 1e5 + 10;
int a[N], suf[N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
	int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
  }		
  for (int i = m; i >= 1; i--) {
    suf[i] = suf[i + 1] + a[i];
  }
  int cur_gr = 0;
  if (suf[1] < n) {
    cout << -1 << '\n';
    exit(0);
  }
  vector<int> rez;
  for (int i = 1; i <= m; i++) {
    cur_gr = max(cur_gr + 1, n - suf[i + 1] - a[i] + 1);
    if (cur_gr > n - a[i] + 1) {
      cout << -1 << '\n';
      exit(0);
    }
    rez.pb(cur_gr);
  }
  for (auto it : rez) {
    cout << it << ' ';
  }
  cout << '\n';
}