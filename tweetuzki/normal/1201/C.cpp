#include <bits/stdc++.h>
using namespace std;

const int MaxN = 200000 + 5;

int N, K;
int A[MaxN];

inline bool check(long long mid) {
  long long res = 0;
  for (int i = N / 2 + 1; i <= N; ++i) {
    if (A[i] >= mid) break;
    res += mid - A[i];
    if (res > K) return false;
  }
  return res <= K;
}

int main() {
  cin >> N >> K;
  for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
  sort(A + 1, A + 1 + N);
  long long lbound = 1, rbound = 2000000000, ans = -1;
  while (lbound <= rbound) {
    long long mid = (lbound + rbound) >> 1;
    if (check(mid) == true) {
      ans = mid;
      lbound = mid + 1;
    } else rbound = mid - 1;
  }
  cout << ans << endl;
  return 0;
}