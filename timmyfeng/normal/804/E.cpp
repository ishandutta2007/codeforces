#include <bits/stdc++.h>
using namespace std;

const array<int, 2> S4[] = {
  {1, 3}, {0, 2}, {1, 2}, {0, 3}, {0, 1}, {2, 3}
};

const array<int, 2> S5[] = {
  {1, 4}, {2, 4}, {3, 4}, {0, 3}, {0, 1},
  {1, 3}, {0, 4}, {1, 2}, {0, 2}, {2, 3}
};

const array<int, 2> S8[] = {
  {1, 1}, {3, 1}, {2, 2}, {3, 2},
  {1, 3}, {2, 1}, {0, 0}, {0, 3},
  {1, 0}, {2, 3}, {3, 0}, {1, 2},
  {0, 1}, {0, 2}, {2, 0}, {3, 3}
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  if (n % 4 >= 2) {
    cout << "NO\n";
    exit(0);
  }
  cout << "YES\n";

  for (int i = 0; i + 4 <= n; i += 4) {
    if (n % 4 == 1) {
      for (auto [a, b] : S5) {
        cout << (i + a + 1) << " " << (b == 4 ? n : i + b + 1) << "\n";
      }
    } else {
      for (auto [a, b] : S4) {
        cout << (i + a + 1) << " " << (i + b + 1) << "\n";
      }
    }
  }

  for (int i = 0; i + 4 <= n; i += 4) {
    for (int j = i + 4; j + 4 <= n; j += 4) {
      for (auto [a, b] : S8) {
        cout << (i + a + 1) << " " << (j + b + 1) << "\n";
      }
    }
  }
}