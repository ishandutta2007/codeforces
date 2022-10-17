#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
#define F first
#define S second

signed main() {
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  unordered_map<int, int> num;
  int ptr = 0;
  for (auto &it : a) {
    cin >> it;
    num[it] = ptr++;
  }
  sort(all(a));
  vector<int> pos(n);
  for (int i = 0 ; i < n; i++) {
    pos[num[a[i]]] = i;
  }
  for (int i = 0; i < m; i++) {
    int cur, len;
    cin >> cur >> len;
    cur--;
    cur = pos[cur];
    int prv = -1, prv2 = -1;
    for (;;) {
      int to = upper_bound(all(a), a[cur] + len) - a.begin() - 1;
      if (to == cur) {
        int to2 = lower_bound(all(a), a[cur] - len) - a.begin();
        if (to2 == cur) {
          break;
        }
        len -= a[cur] - a[to2];
        if (prv == to2 && prv2 == cur) {
          len %= 2ll * (a[cur] - a[to2]);
        }
        prv2 = prv;
        prv = cur;
        cur = to2;
      }
      else {
        len -= a[to] - a[cur];
        if (prv == to && prv2 == cur) {
          len %= 2ll * (a[to] - a[cur]);
        }
        prv2 = prv;
        prv = cur;
        cur = to;
      }
    }
    cout << num[a[cur]] + 1 << '\n';
  }
  //cerr << "TIME :: " << clock() * 1.0 / CLOCKS_PER_SEC << '\n';
}