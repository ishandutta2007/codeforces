#include <bits/stdc++.h>

using namespace std;

const int kd[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
  int x;
  string foo, s;
  cin >> x >> foo >> s;
  if (s == "month") {
    int ans = 0;
    for (int i = 0; i < 12; i++) {
      if (kd[i] >= x) {
        ans++;
      }
    }
    cout << ans << endl;
  } else {
    if (x == 5 || x == 6) {
      cout << 53 << endl;
    } else {
      cout << 52 << endl;
    }
  }
  return 0;
}