#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int64_t n, p;
int64_t fact[10000];
int64_t fact_inv[10000];


int64_t comb(int a, int b) {
    return fact[a] * fact_inv[b] % p * fact_inv[a - b] % p;
}

int64_t pow(int64_t v, int64_t e) {
  int64_t ret = 1;
  while (e > 0) {
    if ((e & 1ll) != 0) {
      ret *= v;
      ret %= p;
    }
    v *= v;
    v %= p;
    e >>= 1;
  }
  return ret;
}

int64_t inv(int64_t v) {
  return pow(v, p - 2);
}

int main() {
    cin >> n >> p;
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = fact[i - 1] * i % p;
    }
    fact_inv[n] = inv(fact[n]);
    for (int i = n - 1; i >= 0; --i) {
        fact_inv[i] = fact_inv[i + 1] * (i + 1) % p;
    }
    int64_t ans = 0;
    if (n % 2 == 0) {
        ans += n * fact[n - 2] % p;
    }
    for (int i = 1; i * 2 < n; ++i) {
        int64_t cnt = 0;
        int oc = i + 1 - n % 2;
        for (int j = 0; j < i; ++j) {
            cnt += fact[n - i - 1 - 1 + j] * comb(i - 1, j);
            cnt %= p;
        }
        cnt *= oc;
        cnt %= p;
        ans += cnt * n;
        ans %= p;
    }
    cout << ans << endl;
}