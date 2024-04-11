#include <bits/stdc++.h>
using namespace std;

const int N = 50;

int ones[N][7][9][2 * N];

void set_min(int &a, int b) {
  if (b < a) {
    a = b;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string x;
  cin >> x;
  int n = x.size();
  for (auto &i : x) {
    i -= '0';
  }

  for (int i = 0; i < n; ++i) {
    for (int j = -3; j <= 3; ++j) {
      for (int k = 0; k < 9; ++k) {
        for (int l = -n; l < n; ++l) {
          ones[i][3 + j][k][n + l] = INT_MAX;
        }
      }
    }
  }

  ones[0][3 + 0][0][n + 0] = 0;
  ones[0][3 + 1][1][n + 0] = n + 1;

  for (int i = 0; i < n - 1; ++i) {
    for (int j = -3; j <= 3; ++j) {
      for (int k = 0; k < 9; ++k) {
        for (int l = -n; l < n; ++l) {
          int value = ones[i][3 + j][k][n + l];
          if (value < INT_MAX) {
            for (int m = -9; m <= 9; ++m) {
              int new_j = j, new_k = k + m, new_l = l;

              if (new_k < 0) {
                new_k += 9;
                --new_j;
                --new_l;
              }

              if (new_k >= 9) {
                new_k -= 9;
                ++new_j;
                ++new_l;
              }

              new_j = 10 * new_j + new_k - x[i];

              if (abs(new_j) <= 3) {
                set_min(ones[i + 1][3 + new_j][new_k][n + new_l], value + (n - i) * abs(m));
              }
            }
          }
        }
      }
    }
  }

  int ans = INT_MAX;
  for (int i = -3; i <= 3; ++i) {
    for (int j = 0; j < 9; ++j) {
      for (int k = -n; k < n; ++k) {
        int value = ones[n - 1][3 + i][j][n + k];
        if (value < INT_MAX) {
          set_min(ans, abs(-(10 * i + j) + k + x[n - 1]) + value);
        }
      }
    }
  }

  cout << ans << "\n";
}