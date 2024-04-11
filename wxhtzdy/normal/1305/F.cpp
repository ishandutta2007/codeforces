#include <bits/stdc++.h>

using namespace std;

const int N = 2000010;

int n;
long long a[N];

long long Calc(long long x) {
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] < x) {
      sum += x - a[i];
    } else {
      sum += min(x - (a[i] % x), a[i] % x);
    }
  }
  return sum;
}

long long Solve(long long x) {
  vector<long long> b;
  for (int i = 2; i * 1LL * i <= x; i++) {
    if (x % i == 0) {
      b.push_back(i);
      while (x > 1 && x % i == 0) {
        x /= i;
      }
    }
  }
  if (x > 1) {
    b.push_back(x);
  }
  long long ret = N;
  for (auto& j : b) {
    if (j == 1) {
      continue;
    }
    ret = min(ret, Calc(j));
  }
  return ret;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld", a + i);
  }
  mt19937 rng(time(0));
  long long ans = n;
  for (int j = 0; j < 20; j++) {
    int i = rng() % n;
    ans = min(ans, Solve(a[i]));
    ans = min(ans, Solve(a[i] + 1));
    ans = min(ans, Solve(a[i] - 1));
  }
  printf("%lld", ans);
  return 0;
}