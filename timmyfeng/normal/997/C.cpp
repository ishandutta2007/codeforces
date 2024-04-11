#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;
const int M = (119 << 23) + 1;

int fact[N];
int fact_inv[N];

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

int mod_pow(int a, long long b) {
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

void init_fact() {
  fact_inv[1] = 1;
  for (int i = 2; i < N; ++i) {
    fact_inv[i] = M - mul(M / i, fact_inv[M % i]);
  }

  fact[0] = 1;
  fact_inv[0] = 1;
  for (int i = 1; i < N; ++i) {
    fact[i] = mul(fact[i - 1], i);
    fact_inv[i] = mul(fact_inv[i - 1], fact_inv[i]);
  }
}

int cnk(int n, int k) {
  if (k < 0 || k > n)
    return 0;
  return mul(fact[n], mul(fact_inv[k], fact_inv[n - k]));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  init_fact();

  int n;
  cin >> n;

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int val = mul(3, mul(cnk(n, i), sub(mod_pow(sub(1, mod_pow(3, i)), n), mod_pow(sub(0, mod_pow(3, i)), n))));
    if (i % 2 == 1) {
      ans = add(ans, val);
    } else {
      ans = sub(ans, val);
    }
  }

  for (int i = 1; i <= n; ++i) {
    int val = mul(2, mul(cnk(n, i), mul(mod_pow(3, i), mod_pow(3, 1LL * n * (n - i)))));
    if (i % 2 == 1) {
      ans = add(ans, val);
    } else {
      ans = sub(ans, val);
    }
  }

  cout << ans << "\n";
}