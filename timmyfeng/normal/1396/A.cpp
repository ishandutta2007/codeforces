#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  cout << 1 << " " << n << "\n";
  for (int i = 0; i < n - 1; ++i) {
    cout << -1LL * a[i] * n << " ";
  }
  cout << 0 << "\n";

  if (n == 1) {
    cout << 1 << " " << 1 << "\n";
    cout << 0 << "\n";
  } else {
    cout << 1 << " " << n - 1 << "\n";
    for (int i = 0; i < n - 1; ++i) {
      cout << 1LL * a[i] * (n - 1) << " ";
    }
    cout << "\n";
  }

  cout << n << " " << n << "\n";
  cout << -a[n - 1] << "\n";
}