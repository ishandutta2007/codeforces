#include <bits/stdc++.h>
using namespace std;

long long N, M;
int Q;

inline long long gcd(long long a, long long b) {
  return b == 0 ? a : gcd(b, a % b);
}

int main() {
  scanf("%lld %lld %d", &N, &M, &Q);
  long long g = gcd(N, M);
  for (int i = 1; i <= Q; ++i) {
    long long sx, sy, ex, ey;
    scanf("%lld %lld %lld %lld", &sx, &sy, &ex, &ey);
    long long p1 = 0, p2 = 0;
    if (sx == 1) {
      p1 = (sy - 1) / (N / g) + 1;
    } else {
      p1 = (sy - 1) / (M / g) + 1;
    }
    if (ex == 1) {
      p2 = (ey - 1) / (N / g) + 1;
    } else {
      p2 = (ey - 1) / (M / g) + 1;
    }
    puts(p1 == p2 ? "Yes" : "No");
  }
  return 0;
}