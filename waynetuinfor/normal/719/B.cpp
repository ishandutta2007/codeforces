#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;
string s, aa, bb;
int n, chr, chb, ans;

int main() {
  ans = INT_MAX;
  cin >> n >> s;
  for (int i = 0; i < n; ++i) {
    if (i & 1) aa += 'r', bb += 'b';
    else aa += 'b', bb += 'r';
  }
  for (int i = 0; i < n; ++i) {
    if (s[i] != aa[i]) {
      if (s[i] == 'r') chr++;
      else chb++;
    }
  }
  int tot = chr + chb - min(chr, chb);
  ans = min(ans, tot);
  chr = 0; chb = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] != bb[i]) {
      if (s[i] == 'r') chr++;
      else chb++;
    }
  }
  tot = chr + chb - min(chr, chb);
  ans = min(ans, tot);
  cout << ans << '\n';
  return 0;
}