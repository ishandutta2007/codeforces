#include <bits/stdc++.h>
using namespace std;

const int N = 22;

array<int, 2> vals[N];
int ans[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> vals[i][0];
    vals[i][1] = i;
  }
  sort(vals, vals + n);

  bool ok = true;
  for (int i = 1; i < n; ++i) {
    ok &= (vals[i][0] != vals[i - 1][0]);
  }

  if (ok) {
    for (int i = 0; i < n; ++i) {
      ans[vals[i][1]] = vals[(i + 1) % n][0];
    }
    for (int i = 0; i < n; ++i) {
      cout << ans[i] << " ";
    }
    cout << "\n";
  } else {
    cout << -1 << "\n";
  }
}