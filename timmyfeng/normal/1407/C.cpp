#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  auto query = [](int a, int b) {
    cout << "? " << a << " " << b << endl;
    int res;
    cin >> res;
    return res;
  };

  int mx = 1;
  vector<int> ans(n + 1);
  for (int i = 2; i <= n; ++i) {
    int a = query(mx, i);
    int b = query(i, mx);
    if (a > b) {
      ans[mx] = a;
      mx = i;
    } else {
      ans[i] = b;
    }
  }
  ans[mx] = n;

  cout << "! ";
  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}