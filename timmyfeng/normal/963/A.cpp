#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 9;

int add(int a, int b) {
  a += b;
  if (a >= M) {
    a -= M;
  }
  return a;
}

int sub(int a, int b) {
  a -= b;
  if (a < 0) {
    a += M;
  }
  return a;
}

int mul(int a, int b) {
  return 1LL * a * b % M;
}

int mod_pow(int a, int b) {
  int res = 1;
  while (b) {
    if (b % 2) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return res;
}

int mod_inv(int a) {
  return mod_pow(a, M - 2);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  int n, a, b, k;
  cin >> n >> a >> b >> k >> s;

  int ratio = mul(b, mod_inv(a));
  int interval = mod_pow(ratio, k);
  int sum = mul(mod_pow(a, n), mul(sub(mod_pow(interval, (n + 1) / k), 1), mod_inv(sub(interval, 1))));
  if (interval == 1) {
    sum = mul(mod_pow(a, n), (n + 1) / k);
  }

  int ans = 0;
  for (int i = 0; i < k; ++i) {
    int val = mul(sum, mod_pow(ratio, i));
    if (s[i] == '+') {
      ans = add(ans, val);
    } else {
      ans = sub(ans, val);
    }
  }
  cout << ans << "\n";
}