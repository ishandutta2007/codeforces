#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  const int N = 1e6 + 5;
  vector<int> ans(N);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int foo;
    cin >> foo;
    for (int j = sum + 1; j <= sum + foo; j++) ans[j] = i + 1;
    sum += foo;
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int foo;
    cin >> foo;
    cout << ans[foo] << '\n';
  }
  return 0;
}