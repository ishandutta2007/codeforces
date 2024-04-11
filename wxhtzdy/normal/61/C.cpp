/**
 *    author:  milos
 *    created: 23.03.2021 09:00:55
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long a;
  cin >> a;
  string b, c;
  cin >> b >> c;
  long long pw = 0;
  for (auto& ch : c) {
    pw *= a;
    if (ch >= '0' && ch <= '9') {
      pw += (int) (ch - '0');
    } else {
      pw += ((int) (ch - 'A') + 10);
    }
  }
  vector<string> r;
  r.push_back("I");
  r.push_back("V");
  r.push_back("X");
  r.push_back("L");
  r.push_back("C");
  r.push_back("D");
  r.push_back("M");
  if (b == "R") {
    string ans;
    for (int i = 0; i < 4; i++) {
      int d = pw % 10;
      string t;
      if (d == 1) {
        t = r[i * 2];
      } else if (d == 2) {
        t = r[i * 2] + r[i * 2];
      } else if (d == 3) {
        t = r[i * 2] + r[i * 2] + r[i * 2];
      } else if (d == 4) {
        t = r[i * 2] + r[i * 2 + 1];
      } else if (d == 5) {
        t = r[i * 2 + 1];
      } else if (d == 6) {
        t = r[i * 2 + 1] + r[i * 2];
      } else if (d == 7) {
        t = r[i * 2 + 1] + r[i * 2] + r[i * 2];
      } else if (d == 8) {
        t = r[i * 2 + 1] + r[i * 2] + r[i * 2] + r[i * 2];
      } else if (d == 9) {
        t = r[i * 2] + r[(i + 1) * 2];
      }
      t += ans;
      swap(ans, t);
      pw /= 10;
    }
    cout << ans << '\n';
  } else {
      //cout << pw << endl;
    string ans = "";
    long long bb = 0;
    for (int i = 0; i < (int) b.size(); i++) {
        bb = bb * 10 + (int) (b[i] - '0');
    }
    while (pw > 0) {
      int d = pw % bb;
      char tt;
      if (d >= 0 && d < 10) {
        tt = (char) ('0' + d);
      } else {
            tt = (char) ('A' + d - 10);
        }
    pw /= bb;
      ans += tt;
    }
    reverse(ans.begin(), ans.end());
    if (ans == "") {
      ans = "0";
    }
    cout << ans << '\n';
  }
  return 0;
}