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

int cnt0[1010][1010], cnt1[1010][1010], al[1010];

int b_pow(int a, int b, int mod) {
  if (b == 0) {
    return 1 % mod;
  }
  if (b & 1) {
    return (a * b_pow(a, b - 1, mod)) % mod;
  }
  return b_pow((a * a) % mod, b >> 1, mod);
}

mt19937 rnd(time(0));

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n = 10, m = 239;
  cin >> n >> m;
  vector<int> arr;
  for (int  i= 0; i < n; i++) {
    int x;
    cin >> x;
    arr.pb(x);
  }
  sort(all(arr));
  for (auto it : arr) {
    int vl = it % m;
    cnt1[vl][vl] += al[vl];
    for (int i = 0; i < vl; i++) {
      cnt1[i][vl] += al[i];
    }
    for (int i = vl + 1; i < m; i++) {
      cnt0[vl][i] += al[i];
    }
    al[vl]++;
  }
  int ans = 1;
  for (int i = 0; i < m; i++) {
    for (int j = i; j < m; j++) {
      ans *= b_pow(j - i, cnt1[i][j], m);
      ans %= m;
      ans *= b_pow(i - j + m, cnt0[i][j], m);
      ans %= m;
    }
  }
  cout << ans % m << '\n';
}