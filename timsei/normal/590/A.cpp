#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;

int A[N], n, m, x, y, B[N], tot = 0, ans = 0;

void solve(int l, int r) {
  if(l > r) return;
  int All = r - l + 1; ans = max(ans, (All + 1) / 2); All /= 2;
  for(int i = l; i <= l + All - 1; ++ i) A[i] = A[l - 1];
  for(int i = l + All; i <= r; ++ i) A[i] = A[r + 1];
}

int main() {
  cin >> n;
  for(int i = 1; i <= n; ++ i) scanf("%d", &A[i]);
  int L = 2;
  for(int i = 2; i <= n; ++ i) {
    if(A[i] == A[i - 1]) {
      solve(L, i - 2); L = i + 1;
    }
  }
  solve(L, n - 1);
  cout << ans << endl;
  for(int i = 1; i <= n; ++ i) printf("%d ", A[i]);
  return 0;
}