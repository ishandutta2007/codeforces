#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
typedef long double ld;
//#define int ll
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define pii pair<int, int>
const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

int f(int a, int b) {
  int c = a / b - a % b, d = a % b, change = c / (b + 1);
  c -= (b + 1) * change;
  d += b * change;
  return c + d;
}

vector<int> get(int x) {
  int lim = (int)sqrt(x);
  vector<int> res;
  for (int i = 1; i <= lim; i++) {
    res.pb(i);
  }
  for (int i = lim; i >= 1; i--) {
    if (x % i == 0) {
      int xx = x / i;
      if (xx - 1 > lim) {
        res.pb(xx - 1);
      }
      if (xx > lim) {
        res.pb(xx);
      }
    }
    else {
      int xx = x / i;
      if (xx > lim) {
        res.pb(xx);
      }
    }
  }
  return res;
}

vector<int> intersect(vector<int> &a, vector<int> &b) {
  vector<int> res;
  int ptr = 0;
  for (auto it : a) {
    while (ptr < SZ(b) && b[ptr] < it) {
      ptr++;
    }
    if (ptr < SZ(b) && it == b[ptr]) {
      res.pb(it);
    }
  }
  return res;  
}

void source() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> cur;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    vector<int> cur2;
    if (i == 0) {
      cur = get(a[0]);
      continue;
    }
    cur2 = get(a[i]);
    cur = intersect(cur, cur2);
  }
  int mx = cur.back();
  ll ans = 0;
  for (auto it : a) {
    ans += f(it, mx);
  }
  cout << ans;
}

signed main() {
#ifdef extraterrestrial_
  assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#else
#define TASK ""
  //assert(freopen(TASK".in", "r", stdin));
  //assert(freopen(TASK".out", "w", stdout));
  //assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  source();
  return 0;
}