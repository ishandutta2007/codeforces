#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

long long n, m, s, capx, capy, ans;

long long getnum(const long long a, const long long b, const long long c) {
  //cal xy = c x, y > 0 && x <= a && y <= b;
  long long k = (long long)sqrt((long double)c + 1) + 1, cnt = 0, t;
  for (long long i = 1; i <= k; ++i) {
    if (c % i == 0) {
      t = c / i;
      if (i > t) continue;
      if (i <= a && t <= b) ++cnt;
      if (i != t && t <= a && i <= b) ++cnt;
      //printf("%I64d %I64d %I64d %I64d %I64d %I64d\n", a, b, c, i, t, cnt);
    }
  }
  return cnt;
}

void op1(const long long a, const long long b) {
  //a > c && b >= d
  //c > a && b <= d
  if ((2 * a + 1) * (2 * b + 1) != s) return;
  ans += 2 * (n - 2 * a) * (m - 2 * b) * a * (b + 1);
}

void op2(const long long a, const long long d) {
  //a > c && d > b
  //c > a && b > d
  long long delta = (2 * a + 1) * (2 * d + 1) - s;
  if (delta <= 0 || delta % 4 != 0) return;
  delta /= 4;
  ans += 2 * getnum(a, d, delta) * (n - 2 * a) * (m - 2 * d);
}

void op3(const long long a, const long long d) {
  //a == c
  if ((2 * a + 1) * (2 * d + 1) != s) return;
  ans += (n - 2 * a) * (m - 2 * d) * (2 * d + 1);
}

int main() {
  scanf("%I64d %I64d %I64d", &n, &m, &s);
  capx = (n - 1) / 2;
  capy = (m - 1) / 2;
  ans = 0;
  for (long long i = 0; i <= capx; ++i) {
    for (long long j = 0; j <= capy; ++j) {
      //printf("%I64d %I64d\n", i, j);
      op1(i, j);
      //printf("%I64d\n", ans);      
      op2(i, j);
      //printf("%I64d\n", ans);
      op3(i, j);
      //printf("%I64d\n", ans);
    }
  }
  printf("%I64d\n", ans);
  //scanf("%I64d", &n);
  return 0;
}