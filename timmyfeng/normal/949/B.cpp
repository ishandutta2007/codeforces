#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int q;
  long long n;
  cin >> n >> q;

  while (q--) {
    long long x;
    cin >> x;
    long long ans = 0;
    long long n_new = n;
    while (x % 2 == 0) {
      x /= 2;
      if (n_new % 2 == 1) {
        x = (x + 1) % n_new;
      }
      ans += n_new / 2;
      n_new = (n_new + 1) / 2;
    }
    ans += (x + 1) / 2;
    cout << ans << "\n";
  }
}