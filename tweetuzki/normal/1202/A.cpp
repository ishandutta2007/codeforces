#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.length(), m = s2.length();
    int l = m;
    for (int i = m - 1; i >= 0; --i)
      if (s2[i] == '1') {
        l = i;
        break;
      }
    for (int k = 0; k < n; ++k) {
      if (s1[n - (m - l) - k] == '1') {
        printf("%d\n", k);
        break;
      }
    }
  }
  return 0;
}