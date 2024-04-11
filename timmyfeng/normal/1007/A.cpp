#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a, a + n);

  int lo = 1;
  int hi = n;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    bool ok = true;
    for (int i = 0; i + mid < n; ++i) {
      ok &= (a[i] < a[i + mid]);
    }
    if (ok) {
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  cout << n - lo << "\n";
}