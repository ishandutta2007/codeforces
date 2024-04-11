#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;
const int MAX = 2e6;

int n, x, y, A[N], S[N], who;
long long Sum[N];

int Cnt(int l, int r) {
  return S[r] - S[l - 1];
}

long long ALL(int l, int r) {
  return Sum[r] - Sum[l - 1];
}

long long Mul(long long x, long long y) {
  if(!x || !y) return x * y;
  if(x > ((long long)1e18 / y)) return 1e18;
  return x * y;
}

long long calc(int l, int r) {
  int Len = r - l + 1;
  int mid = max(l - 1, r - who - 1);
  return 1LL * Cnt(l, mid) * x +
    Mul(y, (1LL * r * Cnt(mid + 1, r) - ALL(mid + 1, r)));
}

int main() {
  cin >> n >> x >> y;
  who = x / y;
  for(int i = 1; i <= n; ++ i) {
    scanf("%d", &A[i]); ++ S[A[i]];
  }
  for(int i = 1; i <= MAX; ++ i) {
    Sum[i] = Sum[i - 1] + 1LL * i * S[i];
    S[i] += S[i - 1];
  }
  const int M = 1e6;
  long long ans = 1e18;
  for(int i = 2; i <= M; ++ i) {
    long long res = 0;
    for(int j = i; j <= M + i; j += i) {
      res += calc(j - i + 1, j);
      res = min(res, (long long)1e18);
    }
    ans = min(ans, res);
  }
  cout << ans << endl;
}