#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  int n, a, b, k;
  cin >> n >> a >> b >> k >> s;

  vector<int> spots;
  a = -a + 1;

  for (int i = 0, j = 0; i < n; i = j) {
    while (j < n && s[i] == s[j]) {
      ++j;
    }

    if (s[i] == '0') {
      for (int x = i + b - 1; x < j; x += b) {
        spots.push_back(x);
        ++a;
      }
    }
  }

  cout << a << "\n";
  for (int i = 0; i < a; ++i) {
    cout << spots[i] + 1 << " ";
  }
  cout << "\n";
}