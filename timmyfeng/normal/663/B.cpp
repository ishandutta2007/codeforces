#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  while (n--) {
    string s;
    cin >> s;
    s = s.substr(4);
    reverse(s.begin(), s.end());

    long long y = 1988, p = 1;
    for (int i = 0; i < (int) s.size(); ++i) {
      do {
        y += p;
      } while (y % (10 * p) / p != s[i] - '0');
      p *= 10;
    }

    cout << y << "\n";
  }
}