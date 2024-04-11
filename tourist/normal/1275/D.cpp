/**
 *    author:  tourist
 *    created: 17.12.2019 18:04:53       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    int sum = 0;
    bool any_even = false;
    bool any_zero = false;
    for (char c : s) {
      sum += (int) (c - '0');
      if (c == '0') {
        if (any_zero) {
          any_even = true;
        } else {
          any_zero = true;
        }
      } else {
        if (c % 2 == 0) {
          any_even = true;
        }
      }
    }
    cout << (any_even && any_zero && sum % 3 == 0 ? "red" : "cyan") << '\n';
  }
  return 0;
}