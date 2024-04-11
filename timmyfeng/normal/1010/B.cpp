#include <bits/stdc++.h>
using namespace std;

const int N = 30;

bool p[N];

bool query(int i) {
  cout << i << endl;
  int res;
  cin >> res;
  if (res == 0) {
    exit(0);
  }
  return res == -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int m, n;
  cin >> m >> n;

  for (int i = 0; i < n; ++i) {
    p[i] = query(1);
  }

  int lo = 1;
  int hi = m;
  int timer = 0;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (query(mid) ^ p[timer % n]) {
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
    ++timer;
  }
}