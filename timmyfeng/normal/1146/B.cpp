#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string t;
  cin >> t;

  string ss;
  int last = 0;
  for (auto i : t) {
    if (i != 'a') {
      ss += i;
    } else {
      last = ss.size();
    }
  }

  if (ss.size() % 2 == 1 || last > (int) ss.size() / 2) {
    cout << ":(\n";
    exit(0);
  }

  for (int i = 0; i < (int) ss.size() / 2; ++i) {
    if (ss[i] != ss[i + (int) ss.size() / 2]) {
      cout << ":(\n";
      exit(0);
    }
  }

  cout << t.substr(0, t.size() - ss.size() / 2) << "\n";
}