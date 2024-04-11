#include <bits/stdc++.h>

using namespace std;

int main() {
  string x, y;
  cin >> x >> y;
  cout << x << " " << y << endl;
  int n;
  cin >> n;
  while (n--) {
    string a, b;
    cin >> a >> b;
    if (x == a) {
      x = b;
    } else {
      y = b;
    }
    cout << x << " " << y << endl;
  }
  return 0;
}