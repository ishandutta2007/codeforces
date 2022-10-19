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
 
const int N = 1e5 + 10;
const int L = 18;
const int INF = 1e9 + 10;
int up[N][L], a[N], nxt[N], lst[N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= 1e5; i++) {
    lst[i] = n + 1;
  }
  vector<pair<int, int>> segs;
  for (int i = n; i >= 1; i--) {
    nxt[i] = n + 1;
    for (int p = 2; p * p <= a[i]; p++) {
      if (a[i] % p == 0) {
        nxt[i] = min(nxt[i], lst[p]);
        lst[p] = i;
        do {
          a[i] /= p;
        } while (a[i] % p == 0);
      }
    }
    if (a[i] > 1) {
      nxt[i] = min(nxt[i], lst[a[i]]);
      lst[a[i]] = i;
    }
    if (nxt[i] != n + 1) {
      segs.pb({i, nxt[i]});
    }
  }
  auto compress = [&](vector<pair<int, int>> &segs) {
    sort(segs.rbegin(), segs.rend());
    vector<pair<int, int>> result;
    int mn = 1e9;
    for (auto it : segs) {
      //cout << it.F << ' ' << it.S << ' ' << mn << '\n';
      if (it.S < mn) {
        result.pb(it);
        mn = it.S;
      }
    }
    segs = result;
  };
  compress(segs);
  sort(all(segs));
  /*for (auto it : segs) {
    cout << it.F << ' ' << it.S << '\n';
  }
  cout << '\n';*/
  int sz = SZ(segs);
  segs.pb({INF, INF});
  up[sz][0] = sz;
  for (int i = 0; i < sz; i++) {
     int nxt_pos = lower_bound(all(segs), make_pair(segs[i].S, segs[i].S)) - segs.begin();
     up[i][0] = nxt_pos;
  }
  for (int i = 1; i < L; i++) {
    for (int j = 0; j <= sz; j++) {
      up[j][i] = up[up[j][i - 1]][i - 1];
    }
  }
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    int fpos = lower_bound(all(segs), make_pair(l, l)) - segs.begin();
    if (fpos == sz || segs[fpos].S > r) {
      cout << 1 << '\n';
      continue;
    }
    int ans = 2;
    for (int j = L - 1; j >= 0; j--) {
      if (segs[up[fpos][j]].S <= r) {
        ans += 1 << j;
        fpos = up[fpos][j];
      }
    }
    cout << ans << '\n';
  }
}