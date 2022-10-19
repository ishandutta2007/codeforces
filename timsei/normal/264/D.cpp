#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

typedef long long LL;

LL ans;
char s[N], t[N];
int n, m, cnt[4][4];

int chg[213];

void add(int x, int v) {
  cnt[t[x - 1]][t[x]] += v;
}

int main() {
  chg['R'] = 1, chg['B'] = 2, chg['G'] = 3;
  scanf("%s", s + 1);
  scanf("%s", t + 1);
  s[0] = t[0] = 0;
  n = strlen(s + 1);
  m = strlen(t + 1);
  for(int i = 1; i <= n; ++ i) s[i] = chg[s[i]];
  for(int i = 1; i <= m; ++ i) t[i] = chg[t[i]];
  int l = 1, r = 0;
  for(int i = 1; i <= n; ++ i) {
    if(t[l] == s[i - 1] && l <= m) add(l ++, -1);
    if(t[r] == s[i - 1] && r < m) add(++ r, 1);
    while(t[r] != s[i] && r < m) add(++ r, 1);
    //cerr << l <<" " << r << endl;
    if(l > r) break;
    ans += (r - l + 1);
    //add(l, -1);
    if(s[i] != s[i - 1]) ans -= cnt[s[i]][s[i - 1]];
    //add(l, 1);
  }
  cout << ans << endl;
}