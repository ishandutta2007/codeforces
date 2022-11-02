#include<cstdio>
#include<algorithm>
using namespace std;

long long n, l, r, k, m, anst;
long long tmp[3][3];
long long ma[3][3];

void renew(long long now) {
  long long res = r / now - (l - 1) / now;
  if (res >= k) anst = max(anst, now);
}

long long next_event(long long a, long long b, long long now) {
  if (b == 0) return 1ll << 60;
  if (b == 1) return a + 1;
  if (a / (b - 1) != now) return a / (b - 1); else return a / (a / (now + 1));
}

long long getans(long long l, long long r, long long k) {
  if (k == 1) return r;
  long long left = max(1ll, (r - l + 1) / (k + 1)), right = (r - l + 1) / (k - 1);
  long long now = left;
  long long t1 = 0, t2 = 0;
  anst = 1;
  while (now <= right) {
    //printf("%I64d\n", now);
    renew(now);
    t1 = r / now; t2 = l / now;
    now = min(next_event(r, t1, now), next_event(l, t2, now));
  }
  return anst;
}

void mul2() {
  tmp[1][1] = 0; tmp[2][1] = 0;
  tmp[1][2] = 0; tmp[2][2] = 0;
  for (int i = 1; i <= 2; ++i) {
    for (int j = 1; j <= 2; ++j) {
      for (int k = 1; k <= 2; ++k) {
        tmp[i][j] += ma[i][k] * ma[k][j] % m;
        tmp[i][j] %= m;
      }
    }
  }
  for (int i = 1; i <= 2; ++i) {
    for (int j = 1; j <= 2; ++j) {
      ma[i][j] = tmp[i][j] % m;
    }
  }  
}

void mul() {
  tmp[1][1] = ma[1][2]; tmp[2][1] = ma[2][2];
  tmp[1][2] = ma[1][1] + ma[1][2]; tmp[2][2] = ma[2][1] + ma[2][2];
  for (int i = 1; i <= 2; ++i) {
    for (int j = 1; j <= 2; ++j) {
      ma[i][j] = tmp[i][j] % m;
    }
  }
}

long long getfib(long long n) {
  if (n == 0 || n == 1 || n == 2) return 1 % m;
  ma[1][1] = 0; ma[1][2] = 1 % m; ma[2][1] = 1 % m; ma[2][2] = 1 % m;
  --n;
  long long t1 = n, t2 = 0, bin[65];
  while (t1) {
    bin[++t2] = t1 % 2;
    t1 /= 2;
  }
  for (int i = t2 - 1; i > 0; --i) {
    mul2();
    if (bin[i]) mul();
  }
  return ma[2][2] % m;
}

int main() {
  scanf("%I64d %I64d %I64d %I64d", &m, &l, &r, &k);
  long long q = getans(l, r, k);
  //printf("%I64d\n", q);
  long long ans = getfib(q);
  printf("%I64d\n", ans);
  //scanf("%I64d", &n);
  return 0;
}