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
 
const int N = 3e5 + 10;
const int MOD = 1e9 + 7;
int f[N];

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  if (n < m) {
  	swap(n, m);
  }
  f[0] = f[1] = 1;
  for (int i = 2; i <= n; i++) {
  	f[i] = (f[i - 2] + f[i - 1]) % MOD;
  }
  int ans = f[n] + f[m] - 1;
  if (ans < 0) {
  	ans += MOD;
  }
  cout << (ans * 2) % MOD << '\n';
}