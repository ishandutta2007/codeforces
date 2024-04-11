/**
 *    author:  milos
 *    created: 05.10.2021 18:25:03       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        cnt += 1;
      }
    }
    cout << (cnt % 2 == 0 || cnt == 1 ? "BOB" : "ALICE") << '\n';
  }
  return 0;
}