#include <bits/stdc++.h>
using namespace std;

int n;

bool query(int a) {
  int u, v;
  cout << "? " << a << endl;
  cin >> u;
  cout << "? " << a + n / 2 << endl;
  cin >> v;

  if (u == v) {
    cout << "! " << a << endl;
    exit(0);
  }

  return u - v < 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  if (n % 4 != 0) {
    cout << "! " << -1 << endl;
    exit(0);
  }

  int lo = 1;
  int hi = n / 2;
  bool sign = query(lo);
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (query(mid) != sign) {
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }

  assert(0);
}