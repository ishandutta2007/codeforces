#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector <int> a(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  long long ans = abs(a[0]);
  for (int i = 1; i < n; i++) {
    ans += abs(a[i] - a[i - 1]);
  }
  cout << ans << endl;
  return 0;
}