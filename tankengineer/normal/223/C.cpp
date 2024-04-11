#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const long long MOD = 1000000007;
const int N = 2005;

int n, k, t1, bin[50];
long long a[N], b[N], c[N];

void add() {
  for (int i = 2; i <= n; ++i) {
    b[i] += b[i - 1];
    b[i] %= MOD;
  }
}

void add2() {
  for (int i = 1; i <= n; ++i) c[i] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      c[i] += b[i - j + 1] * b[j];
      c[i] %= MOD;
    }
  }
  for (int i = 1; i <= n; ++i) b[i] = c[i];
}

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%I64d", &a[i]);
  t1 = 0;
  while (k) {
    bin[++t1] = k & 1;
    k /= 2;
  }
  b[1] = 1;
  for (int i = t1; i >= 1; --i) {
    add2();
    if (bin[i]) add();
  }
  for (int i = 1; i <= n; ++i) {
    c[i] = 0;
    for (int j = 1; j <= i; ++j) {
      c[i] += (a[j] * b[i - j + 1]) % MOD;
      c[i] %= MOD;
    }
  }
  for (int i = 1; i < n; ++i) printf("%I64d ", c[i]);
  printf("%d\n", c[n]);
  return 0;
}