#include <iostream>
using namespace std;

char c[4][4];

bool win();

int main() {
  for (int i = 0; i < 4; ++i) for (int j = 0; j < 4; ++j) cin >> c[i][j];
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (c[i][j] == '.') {
        c[i][j] = 'x';
        if (win()) { cout << "YES\n"; return 0; }
        c[i][j] = '.';
      }
    }
  }
  if (win()) { cout << "YES\n"; return 0; }
  cout << "NO\n";
  return 0;
}

bool win() {
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (c[i][j] == 'x') {
        if (j + 1 < 4 && j + 2 < 4 && c[i][j + 1] == 'x' && c[i][j + 2] == 'x') return true;
        if (j - 1 >= 0 && j - 2 >= 0 && c[i][j - 1] == 'x' && c[i][j - 2] == 'x') return true;
        if (i + 1 < 4 && i + 2 < 4 && c[i + 1][j] == 'x' && c[i + 2][j] == 'x') return true;
        if (i - 1 >= 0 && i - 2 >= 0 && c[i - 1][j] == 'x' && c[i - 2][j] == 'x') return true;
        if (i + 1 < 4 && j + 1 < 4 && i + 2 < 4 && j + 2 < 4 && c[i + 1][j + 1] == 'x' && c[i + 2][j + 2] == 'x') return true;
        if (i - 1 >= 0 && j - 1 >= 0 && i - 2 >= 0 && j - 2 >= 0 && c[i - 1][j - 1] == 'x' && c[i - 2][j - 2] == 'x') return true;
        if (i + 1 < 4 && i + 2 < 4 && j - 1 >= 0 && j - 2 >= 0 && c[i + 1][j - 1] == 'x' && c[i + 2][j - 2] == 'x') return true;
        if (i - 1 >= 0 && i - 2 >= 0 && j + 1 < 4 && j + 2 < 4 && c[i - 1][j + 1] == 'x' && c[i - 2][j + 2] == 'x') return  true;
      }
    }
  }
  return false;
}