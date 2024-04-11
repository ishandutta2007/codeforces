#include <bits/stdc++.h>
using namespace std;

const int L = 10;

int color[L];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  fill(color, color + L, -1);
  for (int i = 0; i < n; ++i) {
    int x;
    char c;
    cin >> c >> x;
    for (int j = 0; j < L; ++j) {
      if ((x & (1 << j)) > 0) {
        if (c == '^') {
          color[j] ^= 1;
        } else if (c == '|') {
          color[j] = 1;
        }
      } else if (c == '&') {
        color[j] = 0;
      }
    }
  }

  int x_and = (1 << L) - 1;
  int x_xor = 0;
  int x_or = 0;
  for (int i = 0; i < L; ++i) {
    if (color[i] == 0) {
      x_and ^= 1 << i;
    } else if (color[i] == 1) {
      x_or ^= 1 << i;
    } else if (color[i] == -2) {
      x_xor ^= 1 << i;
    }
  }

  cout << 3 << "\n";
  cout << "& " << x_and << "\n";
  cout << "^ " << x_xor << "\n";
  cout << "| " << x_or << "\n";
}