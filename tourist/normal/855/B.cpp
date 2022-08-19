/**
 *    author:  tourist
 *    created: 24.09.2017 17:36:20       
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int a[N];
long long L[N], R[N];

int main() {
  long long p, q, r;
  int n;
  cin >> n >> p >> q >> r;
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  L[0] = p * a[0];
  for (int i = 1; i < n; i++) {
    L[i] = max(L[i - 1], p * a[i]);
  }
  R[n - 1] = r * a[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    R[i] = max(R[i + 1], r * a[i]);
  }
  long long ans = (long long) (-9e18);
  for (int i = 0; i < n; i++) {
    ans = max(ans, L[i] + q * a[i] + R[i]);
  }
  cout << ans << endl;
  return 0;
}