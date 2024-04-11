#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 1;

int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int lo = 0;
  int hi = m - 1;

  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    bool ok = true;
    int cur = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] > cur) {
        if (m - mid > a[i] - cur) {
          cur = a[i];
        }
      } else if (a[i] < cur) {
        if (cur - a[i] > mid) {
          ok = false;
          break;
        }
      }
    }

    if (ok) {
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  cout << lo << "\n";
}