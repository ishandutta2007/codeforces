#include <bits/stdc++.h>
using namespace std;

const int N = 22;

int value[2][1 << N];

void set_max(int &a, int b) {
  if (b > a) {
    a = b;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, x, y;
  cin >> n >> x >> y;
  int k = 1 << max(x, y);

  fill(value[0] + 1, value[0] + k, INT_MIN);
  for (int i = 0; i < x + y; ++i) {
    fill(value[1 - i % 2], value[1 - i % 2] + k, INT_MIN);
    int f = n / (x + y) + (i < n % (x + y));
    for (int j = 0; j < k; ++j) {
      if (!(j & (1 << (x - 1)) || j & (1 << (y - 1)))) {
        set_max(value[1 - i % 2][((j * 2) & (k - 1)) | 1], value[i % 2][j] + f);
      }
      set_max(value[1 - i % 2][(j * 2) & (k - 1)], value[i % 2][j]);
    }
  }

  cout << *max_element(value[(x + y) % 2], value[(x + y) % 2] + k) << "\n";
}