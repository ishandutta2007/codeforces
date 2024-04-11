#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int prv = 3, ans = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;

    if (a == 1) {
      prv = 0;
    }

    if (prv <= 1) {
      ++ans;
    } else if (prv == 2) {
      --ans;
    }
    ++prv;
  }
  ans -= (prv == 2);

  cout << ans << "\n";
}