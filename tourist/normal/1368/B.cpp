/**
 *    author:  tourist
 *    created: 18.06.2020 17:46:48       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long k;
  cin >> k;
  string s = "codeforces";
  int n = (int) s.size();
  vector<long long> a(n, 1);
  long long prod = 1;
  for (int it = 0; prod < k; it = (it + 1) % n) {
    prod = prod / a[it] * (a[it] + 1);
    ++a[it];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < a[i]; j++) {
      cout << s[i];
    }
  }
  cout << '\n';
  return 0;
}