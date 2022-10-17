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

int gcd (int a, int b, int & x, int & y) {
  if (a == 0) {
    x = 0; y = 1;
    return b;
  }
  int x1, y1;
  int d = gcd (b%a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}


int solve(int r1, int m1, int r2, int m2) {
  int k, t1, t2;
  k = gcd(m1, m2, t1, t2);
  int rz = abs(r2 - r1);
  if (rz % k != 0) {
    return -1;
  }
  t1 *= (rz / k);
  t2 *= (rz / k);
  if (r2 >= r1) {
    t2 *= -1;
  }
  else {
    t1 *= -1;
  }
  int result = m1 * t1 + r1, mod = m1 * m2 / k;
  return (result % mod + mod) % mod;
}

const int N = 1e6 + 10;
int pos1[N], pos2[N], tmm[N];
 
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    pos1[x] = i;
  }
  for (int i = 1; i <= m; i++) {
    int x;
    cin >> x;
    pos2[x] = i;
  }
  int len = n * m / __gcd(n, m);
  int bad = len;
  for (int i = 1; i <= 2 * max(n, m); i++) {
    if (pos1[i] && pos2[i]) {
      tmm[i] = solve(pos1[i] - 1, n, pos2[i] - 1, m);
    }
    else {
      tmm[i] = -1;
    }
    if (tmm[i] != -1) {
      tmm[i]++;
      bad--;
    }
  }
  int ans;
  if (k % bad == 0) {
    ans = (k / bad - 1) * len;
    k = bad;
  }
  else {
    ans = k / bad * len;
    k %= bad;
  }
  int l = 0, r = len;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    int vl = mid;
    for (int i = 1; i <= 2 * max(n, m); i++) {
      if (tmm[i] != -1 && tmm[i] <= mid) {
        vl--;
      }
    }
    if (vl >= k) {
      r = mid;
    }
    else {
      l = mid;
    }
  }
  cout << ans + r << '\n';
}