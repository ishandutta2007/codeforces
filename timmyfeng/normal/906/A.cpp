#include <bits/stdc++.h>
using namespace std;

const int A = 26;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int ans = -1;
  int possible = (1 << A) - 1;

  while (n--) {
    string w;
    char type;
    cin >> type >> w;

    int mask = 0;
    for (auto i : w) {
      mask |= (1 << (i - 'a'));
    }

    ans += (type != '.' && __builtin_popcount(possible) == 1);

    if (type == '!') {
      possible &= mask;
    } else {
      possible &= ~mask;
    }
  }
  cout << max(0, ans) << "\n";
}