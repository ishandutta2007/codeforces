#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int a[N], b[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    b[i] = a[i];
  }
  sort(a, a + n);
  sort(b, b + n);
  reverse(b, b + n);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += a[i] * 1LL * b[i];
  }
  cout << ans % 10007 << endl;
  return 0;
}