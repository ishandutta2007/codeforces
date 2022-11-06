#include <iostream>
#include <string>
using namespace std;

int n, h, v, st, ans;
string s;

int main() {
  cin >> n >> s;
  while (st < n) {
    h = 0, v = 0; ++ans;
    for (; st < n; ++st) {
      if (s[st] == 'R' && (!h || h == 1)) h = 1;
      else if (s[st] == 'L' && (!h || h == 2)) h = 2;
      else if (s[st] == 'D' && (!v || v == 1)) v = 1;
      else if (s[st] == 'U' && (!v || v == 2)) v = 2;
      else break;
    }
  }
  cout << ans << '\n';
}