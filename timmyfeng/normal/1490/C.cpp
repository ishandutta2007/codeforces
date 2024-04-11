#include <bits/stdc++.h>
using namespace std;

void solve() {
  long long x;
  cin >> x;

  long long a = 1;
  while (a * a * a < x)
    ++a;

  long long b = 1;
  while (b <= a) {
    while (a > 1 && a * a * a + b * b * b > x)
      --a;
    if (a * a * a + b * b * b == x) {
      cout << "YES\n";
      return;
    }
    ++b;
  }

  cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--)
    solve();
}