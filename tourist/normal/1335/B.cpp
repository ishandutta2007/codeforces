/**
 *    author:  tourist
 *    created: 13.04.2020 17:35:54       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, a, b;
    cin >> n >> a >> b;
    string s(a, ' ');
    for (int i = 0; i < a; i++) s[i] = (char) ('a' + i % b);
    for (int i = 0; i < n; i++) cout << s[i % a];
    cout << '\n';
  }
  return 0;
}