#include <bits/stdc++.h>
using namespace std;

const int N = 100'000;

long long diff[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  long long ans;
  cin >> ans;

  int prv = ans;
  for (int i = 1; i < n; ++i) {
    int a;
    cin >> a;
    diff[i] = a - prv;
    if (diff[i] > 0) {
      ans += diff[i];
    }
    prv = a;
  }

  int q;
  cin >> q;
  for (int i = 0; i < q + 1; ++i) {
    if (i > 0) {
      int l, r, x;
      cin >> l >> r >> x;

      if (l == 1) {
        ans += x;
      } else {
        if (diff[l - 1] > 0) {
          ans -= diff[l - 1];
        }
        diff[l - 1] += x;
        if (diff[l - 1] > 0) {
          ans += diff[l - 1];
        }
      }

      if (r < n) {
        if (diff[r] > 0) {
          ans -= diff[r];
        }
        diff[r] -= x;
        if (diff[r] > 0) {
          ans += diff[r];
        }
      }
    }

    if (ans > 0) {
      cout << (ans + 1) / 2 << "\n";
    } else {
      cout << ans / 2 << "\n";
    }
  }
}