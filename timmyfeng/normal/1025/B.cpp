#include <bits/stdc++.h>
using namespace std;

const int N = 150000;

int a[N][2], n;

void process(int x) {
  if (x == 1) {
    return;
  }

  for (int i = 0; i < n; ++i) {
    if (min(a[i][0] % x, a[i][1] % x) > 0) {
      return;
    }
  }

  cout << x << "\n";
  exit(0);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 2; ++j) {
      cin >> a[i][j];
    }
  }

  for (int k = 0; k < 2; ++k) {
    int x = a[0][k];
    for (int i = 2; i * i <= x; ++i) {
      if (x % i == 0) {
        process(i);
        while (x % i == 0) {
          x /= i;
        }
      }
    }
    process(x);
  }

  cout << -1 << "\n";
}