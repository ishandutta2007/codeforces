#include <bits/stdc++.h>
using namespace std;

const int N = 15;

int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i < (1 << n); ++i) {
    int sum = 0;
    for (int j = 0; j < n; ++j) {
      if ((i & (1 << j)) > 0) {
        sum += a[j];
      } else {
        sum -= a[j];
      }
    }

    if (sum % 360 == 0) {
      cout << "YES\n";
      exit(0);
    }
  }
  cout << "NO\n";
}