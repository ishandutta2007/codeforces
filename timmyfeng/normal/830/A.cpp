#include <bits/stdc++.h>
using namespace std;

const int N = 2'000;

int a[N];
int b[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k, p;
  cin >> n >> k >> p;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a, a + n);

  for (int i = 0; i < k; ++i) {
    cin >> b[i];
  }
  sort(b, b + k);

  int lo = 0;
  int hi = INT_MAX;
  while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;

    int ptr = 0;
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      bool found = false;
      while (ptr < k && !found) {
        int dist = abs(a[i] - b[ptr]) + abs(b[ptr] - p);
        found |= (dist <= mid);
        ++ptr;
      }
      ok &= found;
    }

    if (ok) {
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }

  cout << lo << "\n";
}