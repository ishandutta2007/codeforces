#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  string x = "1";
  int y = 0;

  for (int i = 0; i < n; ++i) {
    string a;
    cin >> a;

    if (a == "0") {
      cout << 0 << "\n";
      exit(0);
    }

    while (a.back() == '0') {
      a.pop_back();
      ++y;
    }

    if (a != "1") {
      x = a;
    }
  }

  cout << x << string(y, '0') << "\n";
}