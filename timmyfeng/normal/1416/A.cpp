#include <bits/stdc++.h>
using namespace std;

const int N = 300'000;

int prv[N];
int gap[N];
int ndx[N];
int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    fill(prv, prv + n, -1);
    fill(gap, gap + n, 0);

    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      --a[i];

      gap[a[i]] = max(gap[a[i]], i - prv[a[i]]);
      prv[a[i]] = i;
    }

    for (int i = 0; i < n; ++i) {
      gap[i] = max(gap[i], n - prv[i]);
    }

    iota(ndx, ndx + n, 0);
    sort(ndx, ndx + n, [&](int a, int b) {
      return gap[a] < gap[b];
    });

    int ptr = 0;
    int min_a = n;
    for (int i = 1; i <= n; ++i) {
      while (ptr < n && gap[ndx[ptr]] <= i) {
        min_a = min(min_a, ndx[ptr]);
        ++ptr;
      }

      if (min_a == n) {
        cout << -1 << " ";
      } else {
        cout << min_a + 1 << " ";
      }
    }
    cout << "\n";
  }
}