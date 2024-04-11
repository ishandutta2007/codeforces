#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int Sqrt(int x) {
  int ans = sqrt(x);
  while(1LL * (ans + 1) * (ans + 1) <= x) ++ ans;
  return ans;
}

long long n, m, x, y, A[N];

int main() {
  cin >> n;
  int last = 0;
  for(int i = 2; i <= n; i += 2) {
    scanf("%lld", &A[i]);
    long long K = 2e9, who = -1;
    for(long long j = 1; j <= 700; ++ j) {
      long long now = A[i] - j * j;
      if(now % 2 || now < 0) continue;
      now /= 2;
      if(now % j != 0) continue;
      now /= j;
      if(last >= now) {
	continue;
      }
      K = min(K, now + j);
      who = now;
    }
    if(K > 1e9) {
      puts("No");
      return 0;
    }
    A[i - 1] = (1LL * who * who - 1LL * last * last);
    last = K;
  }
  puts("Yes");
  for(int i = 1; i <= n; ++ i) printf("%lld ", A[i]);
}