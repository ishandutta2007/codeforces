#include <bits/stdc++.h>
using namespace std;

const int L = 40;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  long long s, x;
  cin >> s >> x;

  if (s % 2 != x % 2 || s < x) {
    cout << 0 << "\n";
    exit(0);
  }

  long long a = (s - x) / 2, ans = 1;
  for (int i = 0; i < L; ++i) {
    if ((a & (1LL << i)) == 0) {
      ans *= 1 + ((x & (1LL << i)) > 0);
    } else if ((x & (1LL << i)) > 0) {
      ans = 0;
    }
  }

  if (s == x) {
    ans -= 2;
  }

  cout << ans << "\n";
}