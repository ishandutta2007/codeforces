#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
#define F first
#define S second

const int INF = 1e9 + 10;
const int MOD = 998244353;

signed main() {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  int ans = 1;
  for (int i = 1; i <= n + m; i++) {
    ans = (ans * 2) % MOD;
  }
  cout << ans;
}