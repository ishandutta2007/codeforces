#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  bool going = false;
  for (auto &i : s) {
    if (i == 'a') {
      if (going) {
        break;
      }
    } else {
      going = true;
      --i;
    }
  }

  if (!going) {
    s.back() = 'z';
  }

  cout << s << "\n";
}