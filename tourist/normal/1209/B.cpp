/**
 *    author:  tourist
 *    created: 14.09.2019 16:06:57       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int MAX = 100000;
  vector<int> cnt(MAX);
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    int c = (int) (s[i] - '0');
    for (int j = 0; j < MAX; j++) {
      cnt[j] += c;
      if (j == b) {
        c ^= 1;
        b += a;
      }
    }
  }
  cout << *max_element(cnt.begin(), cnt.end()) << '\n';
  return 0;
}