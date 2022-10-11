#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>>> " << x << endl;
#define _ << " , " << 

using namespace std;
typedef long long ll;

int oi[300], cnt[300];
bool cant[300];

int main() {
  int n, m;
  cin >> n;
  string s, w;
  cin >> s;
  for (char ch : s) {
    cant[ch] = true;
  }
  cin >> m;
  int tot = 0;
  fr(aha, 0, m) {
    cin >> w;
    bool ok = true;
    fr(i, 0, n) {
      if (s[i] == '*') {
        if (cant[w[i]]) {
          ok = false;
        }
      } else {
        if (s[i] != w[i]) {
          ok = false;
        }
      }
    }
    if (!ok) {
      continue;
    }
    tot++;
    fr(i, 'a', 'z' + 1) {
      oi[i] = 0;
    }
    fr(i, 0, n) {
      if (s[i] == '*') {
        oi[w[i]] = 1;
      }
    }
    fr(i, 'a', 'z' + 1) {
      cnt[i] += oi[i];
    }
  }
  int ans = 0;
  fr(i, 'a', 'z' + 1) {
    ans += cnt[i] == tot;
  }
  if (tot == 0)
    ans = 0;
  cout << ans << endl;
}