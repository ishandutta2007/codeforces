#include <bits/stdc++.h>
using namespace std;

const int N = 100 + 3;

string field[3];
bool safe[N][3];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < 3; ++i) {
      cin >> field[i];
      field[i] += "...";
    }

    for (int i = 0; i < n + 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        safe[i][j] = (field[j][i] == 's');
      }
    }

    bool ans = false;
    for (int i = 0; i < n + 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        if (safe[i][j]) {
          if (i >= n) {
            ans = true;
          } else if (field[j][i + 1] == '.') {
            for (int k = j - 1; k <= j + 1; ++k) {
              if (k >= 0 && k < 3 && field[k][i + 1] == '.' && field[k][i + 2] == '.' && field[k][i + 3] == '.') {
                safe[i + 3][k] = true;
              }
            }
          }
        }
      }
    }

    cout << (ans ? "YES" : "NO") << "\n";
  }
}