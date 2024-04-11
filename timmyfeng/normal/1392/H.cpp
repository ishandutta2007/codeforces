#include <bits/stdc++.h>
using namespace std;

const int M = (119 << 23) + 1;

int add(int a, int b) {
  a += b;
  if (a >= M) {
    a -= M;
  }
  return a;
}

int mul(int a, int b) {
  return 1LL * a * b % M;
}

int mod_inv(int a) {
  int b = M - 2;
  int res = 1;
  while (b > 0) {
    if (b % 2 == 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  int cnt = 1;
  for (int i = 1; i <= n; ++i) {
    cnt = add(cnt, mul(m, mod_inv(i)));
  }

  cout << mul(add(mul(n, mod_inv(m + 1)), 1), cnt) << "\n";
}