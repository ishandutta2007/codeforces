#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;
int n;
bool v[maxn];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n;
  int cur = 0, ans = 0, x;
  for (int i = 0; i < 2 * n; ++i) {
    cin >> x;
    if (v[x]) --cur;
    else v[x] = true, ++cur;
    ans = max(ans, cur);
  }
  cout << ans << '\n';
  return 0;
}