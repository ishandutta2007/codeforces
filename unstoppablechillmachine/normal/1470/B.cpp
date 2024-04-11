#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back  
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

const int N = 1e6 + 10;
int p[N], calc[N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  calc[1] = 1;
  for (int i = 2; i <= 1e6; i++) {
    if (!p[i]) {
      calc[i] = i;
      for (int j = i * i; j <= 1e6; j += i) {
        p[j] = i;
      }
    }
    else {
      int cur = i, cc = 0;
      while (cur % p[i] == 0) {
        cur /= p[i];
        cc++;
      }
      calc[i] = calc[cur];
      if (cc & 1) {
        calc[i] *= p[i];
      }
    }
  }
  int T;
  cin >> T;
  while (T--) {
    map<int, int> cnt, cnt2;
    int n;
    cin >> n;
    int mx = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      mx = max(mx, ++cnt[calc[x]]);
    }
    for (auto it : cnt) {
      if (it.S % 2 == 0) {
        cnt2[1] += it.S;
      }
      else {
        cnt2[it.F] += it.S;
      }
    }
    int mx2 = 0;
    for (auto it : cnt2) {
      mx2 = max(mx2, it.S);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
      int w;
      cin >> w;
      if (w == 0) {
        cout << mx << '\n';
      }
      else {
        cout << mx2 << '\n';
      }
    }
  }
}