#include <bits/stdc++.h>
using namespace std;

bool query(int x, int y) {
  cout << 1 << " " << x << " " << y << endl;
  string res;
  cin >> res;
  return res == "TAK";
}

int solve(int lo, int hi) {
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (query(mid, mid + 1)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  return hi;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  int x = solve(1, n);
  int y = solve(1, x - 1);

  if (y == 0 || !query(y, x)) {
    y = solve(x + 1, n);
  }

  cout << 2 << " " << x << " " << y << endl;
}