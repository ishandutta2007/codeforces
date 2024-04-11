#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int ans = 0;
  int valid = 0;
  map<int, int> open;
  map<int, int> closed;

  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;

    int min_bal = 0;
    int bal = 0;

    for (auto j : s) {
      if (j == '(') {
        ++bal;
      } else {
        --bal;
      }
      min_bal = min(min_bal, bal);
    }

    if (bal > 0) {
      if (min_bal == 0) {
        if (closed[bal] > 0) {
          --closed[bal];
          ++ans;
        } else {
          ++open[bal];
        }
      }
    } else if (bal < 0) {
      if (min_bal == bal) {
        if (open[-bal] > 0) {
          --open[-bal];
          ++ans;
        } else {
          ++closed[-bal];
        }
      }
    } else {
      if (min_bal == 0) {
        ans += valid;
        valid ^= 1;
      }
    }
  }

  cout << ans << "\n";
}