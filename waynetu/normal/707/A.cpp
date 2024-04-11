#include <iostream>
using namespace std;

int main() {
  int n, m;
  char c;
  cin >> n >> m;
  bool color = false;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> c;
      if (c == 'C' || c == 'M' || c == 'Y') {
        color = true;
      }
    }
  }
  if (color) cout << "#Color" << endl;
  else cout << "#Black&White" << endl;
  return 0;
}