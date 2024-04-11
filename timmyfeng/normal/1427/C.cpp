#include <bits/stdc++.h>
using namespace std;

const int N = 100'000 + 1;

int prefix[N];
int best[N];
int t[N];
int x[N];
int y[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int r, n;
  cin >> r >> n;

  x[0] = 1;
  y[0] = 1;
  for (int i = 1; i <= n; ++i) {
    cin >> t[i] >> x[i] >> y[i];
  }

  for (int i = 1; i <= n; ++i) {
    best[i] = INT_MIN;
    for (int j = i - 1; j >= 0; --j) {
      if (t[i] - t[j] > 2 * r) {
        best[i] = max(best[i], prefix[j]);
        break;
      } else if (abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[i] - t[j]) {
        best[i] = max(best[i], best[j]);
      }
    }
    prefix[i] = max(++best[i], prefix[i - 1]);
  }

  cout << prefix[n] << "\n";
}