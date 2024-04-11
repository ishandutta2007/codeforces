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

const int MOD = 998244353;
const int N = 3e5 + 10;
int f[N], rf[N];

void add(int &a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}

int mult(int a, int b) {
  return (a * 1ll * b) % MOD;
}

int C(int n, int k) {
  if (n < 0 || k < 0 || k > n) {
    return 0;
  }
  return mult(f[n], mult(rf[k], rf[n - k]));
}

int b_pow(int a, int b) {
  if (!b) {
    return 1;
  }
  if (b & 1) {
    return mult(a, b_pow(a, b - 1));
  }
  return b_pow(mult(a, a), b >> 1);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n;
  cin >> n;
  f[0] = rf[0] = 1;
  for (int i = 1; i <= 2 * n; i++) {
    f[i] = mult(f[i - 1], i);
    rf[i] = b_pow(f[i], MOD - 2);
  }
  int ways = C(2 * n, n);
  vector<int> a(2 * n);
  for (int i = 0; i < 2 * n; i++) {
    cin >> a[i];
  }
  sort(all(a));
  for (int i = 0; i < 2 * n; i++) {
    a[i] %= MOD;
    //cout << a[i] << ' ';
  }
  //cout << '\n';
  int ans = 0;
  for (int i = 0; i < 2 * n; i++) {
    if (i < n) {
      add(ans, mult(ways, MOD - a[i]));
    }
    else {
      add(ans, mult(ways, a[i]));
    }
  }
  cout << ans << '\n';
}