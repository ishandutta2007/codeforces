#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  cout << 2 << "\n";
  for (int a = 2; a <= n; ++a) {
    cout << (long long) a * a * a + (long long) 2 * a * a + 1 << "\n";
  }
}