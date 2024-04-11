#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

int par[N], sub[N];
double ans[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cout << fixed << setprecision(8);

  int n;
  cin >> n;

  for (int i = 1; i < n; ++i) {
    cin >> par[i];
    --par[i];
  }

  for (int i = n - 1; i >= 0; --i) {
    ++sub[i];
    if (i > 0) {
      sub[par[i]] += sub[i];
    }
  }

  ans[0] = 1.0;
  for (int i = 1; i < n; ++i) {
    ans[i] = ans[par[i]] + 0.5 * (sub[par[i]] - sub[i] - 1) + 1;
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}