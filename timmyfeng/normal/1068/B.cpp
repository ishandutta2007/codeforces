#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  long long b;
  cin >> b;
  int ans = 0;
  for (long long i = 1; i * i <= b; ++i) {
    if (b % i == 0) {
      ans += 1 + (i * i != b);
    }
  }
  cout << ans << "\n";
}