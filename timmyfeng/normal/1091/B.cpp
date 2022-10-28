#include <bits/stdc++.h>
using namespace std;

const int N = 1'000;

array<int, 2> obelisk[N], clue[N], vec[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 2; ++j) {
      cin >> obelisk[i][j];
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 2; ++j) {
      cin >> clue[i][j];
    }
  }
  sort(clue, clue + n);

  for (int i = 0; i < n; ++i) {
    int x = clue[i][0] + obelisk[0][0];
    int y = clue[i][1] + obelisk[0][1];
    for (int j = 0; j < n; ++j) {
      vec[j][0] = x - obelisk[j][0];
      vec[j][1] = y - obelisk[j][1];
    }

    sort(vec, vec + n);
    if (equal(vec, vec + n, clue)) {
      cout << x << " " << y << "\n";
      exit(0);
    }
  }

  cout << -1 << "\n";
}