#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int m, n;
  cin >> m >> n;
  vector<int> p(n);
  auto ask = [&](int x) {
    cout << x << endl;
    int y;
    cin >> y;
    if (y == 0) {
      exit(0);
    }
    return y;
  };
  for (int i = 0; i < n; i++) {
    p[i] = ask(1);
  }
  int bot = 1, top = m, nxt = 0;
  while (bot <= top) {
    int mid = bot + top >> 1;
    int x = ask(mid);
    x *= p[nxt];
    nxt = (nxt + 1) % n;
    if (x == 1) {
      bot = mid + 1;
    } else {
      top = mid - 1;
    }
  }
  return 0;
}