#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s, t;
  cin >> n >> s;

  for (int i = 0, j = 0; i < n; i = j + 1) {
    for (j = i; j < n && s[j] == s[i]; ++j);
    if (j < n) {
      t += s[i];
      t += s[j];
    }
  }

  cout << n - (int) t.size() << "\n";
  cout << t << "\n";
}