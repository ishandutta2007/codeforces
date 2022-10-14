#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int n = (int) s.length(), cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        cnt0++;
      } else {
        cnt1++;
      }
    }
    if (min(cnt0, cnt1) % 2 == 1) {
      cout << "DA" << '\n';
    } else {
      cout << "NET" << '\n';
    }
  }
  return 0;
}