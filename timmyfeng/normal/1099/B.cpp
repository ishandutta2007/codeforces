#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int ans = 0;
  while ((ans / 2) * ((ans + 1) / 2) < n) {
    ++ans;
  }
  cout << ans << "\n";
}