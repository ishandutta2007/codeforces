#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> b(n);
  map<int, int64_t> p;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &b[i]);
    p[b[i] - i] += b[i];
  }
  int64_t ans = 0;
  for (auto it : p) ans = max(ans, it.second);
  cout << ans << "\n";
}