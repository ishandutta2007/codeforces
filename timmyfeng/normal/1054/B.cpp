#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int maxi = -1;
  for (int i = 1; i <= n; ++i) {
    int a;
    cin >> a;
    if (maxi + 1 < a) {
      cout << i << "\n";
      exit(0);
    }
    maxi = max(maxi, a);
  }

  cout << -1 << "\n";
}