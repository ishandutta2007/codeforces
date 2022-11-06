#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
int n, a[maxn];

int main() {
  cin >> n;
  int Max = 0;
  long long ans = 0;
  for (int i = 0; i < n; ++i) cin >> a[i], Max = max(Max, a[i]);
  for (int i = 0; i < n; ++i) ans += Max - a[i];
  cout << ans << '\n';
}