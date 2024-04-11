#include <bits/stdc++.h>
using namespace std;

const int MaxN = 100 + 5;

int T, N, M, K;
int A[MaxN];

inline bool solve() {
  for (int i = 1; i < N; ++i) {
    int mn = A[i + 1] - K;
    if (mn < 0) mn = 0;
    int need = mn - A[i];
    M -= need;
    if (M < 0) return false;
  }
  return true;
}

int main() {
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
    puts(solve() ? "Yes" : "No");
  }
  return 0;
}