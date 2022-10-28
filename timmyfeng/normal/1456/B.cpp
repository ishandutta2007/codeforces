#include <bits/stdc++.h>
using namespace std;

const int N = 200000;
const int B = 64;

int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  if (n >= B) {
    cout << 1 << "\n";
    exit(0);
  }

  int ans = INT_MAX;
  for (int i = 1; i < n; ++i) {
    for (int j = i - 1; j >= 0; --j) {
      for (int k = i; k < n; ++k) {
        int left = 0, right = 0;
        for (int l = j; l < i; ++l) {
          left ^= a[l];
        }
        for (int l = i; l <= k; ++l) {
          right ^= a[l];
        }
        if (left > right) {
          ans = min(ans, k - j - 1);
        }
      }
    }
  }

  cout << (ans == INT_MAX ? -1 : ans) << "\n";
}