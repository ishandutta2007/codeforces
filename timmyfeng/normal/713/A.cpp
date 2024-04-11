#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  map<int, int> count;
  while (n--) {
    char t;
    string s;
    cin >> t >> s;

    int x = 0;
    for (auto i : s) {
      x = 2 * x + (i - '0') % 2;
    }

    if (t == '+') {
      ++count[x];
    } else if (t == '-') {
      --count[x];
    } else {
      cout << count[x] << "\n";
    }
  }
}