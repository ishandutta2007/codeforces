#include <bits/stdc++.h>
using namespace std;

const int N = 7'000;

bool moves[2][N][N];
int count_m[2][N];
int size_s[2];
int ans[2][N];
int s[2][N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < 2; ++i) {
    cin >> size_s[i];
    for (int j = 0; j < size_s[i]; ++j) {
      cin >> s[i][j];
    }
  }

  for (int i = 0; i < 2; ++i) {
    for (int j = 1; j < n; ++j) {
      ans[i][j] = -1;
      for (int k = 0; k < size_s[i]; ++k) {
        moves[i][j][(j + s[i][k]) % n] = true;
      }
      count_m[i][j] = size_s[i];
    }
  }

  queue<array<int, 3>> que;
  que.push({0, 0, 0});
  que.push({1, 0, 0});

  while (!que.empty()) {
    auto [r, c, x] = que.front();
    que.pop();

    for (int k = 0; k < size_s[r ^ 1]; ++k) {
      int c_new = (c + n - s[r ^ 1][k]) % n;
      if (x == 0) {
        if (count_m[r ^ 1][c_new] != 0) {
          ans[r ^ 1][c_new] = 1;
          count_m[r ^ 1][c_new] = 0;
          que.push({r ^ 1, c_new, 1});
        }
      } else {
        if (count_m[r ^ 1][c_new] != 0 && moves[r ^ 1][c_new][c]) {
          moves[r ^ 1][c_new][c] = false;
          if (--count_m[r ^ 1][c_new] == 0) {
            ans[r ^ 1][c_new] = 0;
            que.push({r ^ 1, c_new, 0});
          }
        }
      }
    }
  }

  for (int i = 0; i < 2; ++i) {
    for (int j = 1; j < n; ++j) {
      if (ans[i][j] == 0) {
        cout << "Lose ";
      } else if (ans[i][j] == 1) {
        cout << "Win ";
      } else {
        cout << "Loop ";
      }
    }
    cout << "\n";
  }
}