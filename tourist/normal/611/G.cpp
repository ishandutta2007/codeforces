#include <bits/stdc++.h>

using namespace std;

const int md = 1000000007;

inline void add(int &a, int b) {
  a += b;
  if (a >= md) a -= md;
}

inline void sub(int &a, int b) {
  add(a, md - b);
}

inline int mul(int a, int b) {
  return (long long) (a % md) * (b % md) % md;
}

const int N = 1234567;

int x[N], y[N];
long long addd[N], pref[N];
int prefmod[N], xmod[N], ymod[N];
int weighted[N], sumx[N], sumy[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", x + i, y + i);
  }
  for (int i = 0; i <= n; i++) {
    x[i + n] = x[i];
    y[i + n] = y[i];
  }
  for (int i = 0; i < n + n; i++) {
    addd[i] = y[i] * 1LL * x[i + 1] - x[i] * 1LL * y[i + 1];
  }
  pref[0] = 0;
  prefmod[0] = 0;
  for (int i = 0; i < n + n; i++) {
    pref[i + 1] = pref[i] + addd[i];
    prefmod[i + 1] = prefmod[i];
    add(prefmod[i + 1], (addd[i] % md + md) % md);
  }
  for (int i = 0; i <= n + n; i++) {
    xmod[i] = (x[i] % md + md) % md;
    ymod[i] = (y[i] % md + md) % md;
  }
  weighted[0] = 0;
  for (int i = 0; i < n + n; i++) {
    weighted[i + 1] = weighted[i];
    add(weighted[i + 1], prefmod[i + 1]);
  }
  sumx[0] = 0; sumy[0] = 0;
  for (int i = 0; i < n + n; i++) {
    sumx[i + 1] = sumx[i];
    add(sumx[i + 1], xmod[i]);
    sumy[i + 1] = sumy[i];
    add(sumy[i + 1], ymod[i]);
  }
  long long total = pref[n];
  long long half = total / 2;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int low = i + 1, high = i + n - 1;
    while (low < high) {
      int mid = (low + high + 1) >> 1;
      long long z = pref[mid] - pref[i];
      z += y[mid] * 1LL * x[i] - x[mid] * 1LL * y[i];
      if (z <= half) {
        low = mid;
      } else {
        high = mid - 1;
      }
    }
    {
      int mid = low;
      long long z = pref[mid] - pref[i];
      z += y[mid] * 1LL * x[i] - x[mid] * 1LL * y[i];
      if (z == half && 2 * half == total) {
        int j = mid % n;
        if (i > j) {
          low--;
        }
      }
    }
    int k = low - i;
    add(ans, weighted[i + k]);
    sub(ans, weighted[i]);
    sub(ans, mul(prefmod[i], k));
    int sy = sumy[i + k + 1];
    sub(sy, sumy[i + 1]);
    add(ans, mul(sy, xmod[i]));
    int sx = sumx[i + k + 1];
    sub(sx, sumx[i + 1]);
    sub(ans, mul(sx, ymod[i]));
  }
  int res = mul(total % md, (n * 1LL * (n - 3) / 2) % md);
  sub(res, mul(2, ans));
  printf("%d\n", res);
  return 0;
}