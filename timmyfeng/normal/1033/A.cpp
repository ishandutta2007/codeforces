#include <bits/stdc++.h>
using namespace std;

int x[3], y[3];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < 3; ++i) {
    cin >> x[i] >> y[i];
  }

  if (min(x[1], x[2]) <= x[0] && x[0] <= max(x[1], x[2])) {
    cout << "NO\n";
  } else if (min(y[1], y[2]) <= y[0] && y[0] <= max(y[1], y[2])) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
  }
}