#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree <pair<ll, int>, null_type, less<pair<ll, int>>, rb_tree_tag, tree_order_statistics_node_update>
typedef long long ll;
typedef long double ld;
#define f first
#define s second
const int MX = 3e5 + 5;


int main() {
  int t; cin >> t;
  while(t--) {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    pair<int, int> pLo[n+1], pHi[n+2];
    int p[n+1];
    p[0] = 0;
    pLo[0] = {0, 0};
    int curr = 0;
    for(int i=0;i<n;i++) {
      if(s[i]=='-') --curr;
      else ++curr;
      p[i+1] = curr;
      pLo[i+1] = pLo[i];
      pLo[i+1].f = min(pLo[i+1].f, curr);
      pLo[i+1].s = max(pLo[i+1].s, curr);
    }
    pHi[n] = {curr, curr};
    for(int i=n-1;i>=1;i--) {
      if(s[i]=='-') ++curr;
      else --curr;
      pHi[i] = pHi[i+1];
      pHi[i].f = min(pHi[i].f, curr);
      pHi[i].s = max(pHi[i].s, curr);
    }
    while(m--) {
      int l, r; cin >> l >> r;
      //[0, l-1] and [r+1, n]
      int ch = p[r] - p[l-1];
      int x = pLo[l-1].s - pLo[l-1].f + 1;
      int a = pHi[r].s - ch, b = pHi[r].f - ch;
      int y = a - b + 1;
      int overCount = max(min(pLo[l-1].s, a) - max(pLo[l-1].f, b) + 1,0);
      cout << x+y-overCount << "\n";
    }
  }
}