//author: extraterrestrial_
#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,avx,tune=native")
using namespace std;
#define int ll
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define _ inline
#define pb push_back
#define F first
#define S second
#define MP make_pair
#define SZ(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pw(x) (1 << (x))
#ifdef extraterrestrial_
#define debug(x) cerr << #x << ": " << x << '\n';
#else
#define debug(x)
#endif
const int INF = 1e9 + 10;
const ll BINF = 1e18 + 10;

void source() {
  int n, sum;
  cin >> n >> sum;
  if (n * (n + 1) / 2 < sum) {
    cout << "No";
    return;
  }
  if (n * (n + 1) / 2 == sum) {
    cout << "Yes\n";
    for (int i = 2; i <= n; i++) {
      cout << i - 1 << ' ';
    }
    return;
  }
  if (n * 2 - 1 > sum) {
    cout << "No";
    return;
  }
  int l = 1, r = n;
  vector<int> lp(n + 1);
  while (r - l > 1) {
    int mid = (l + r) / 2;
    vector<int> f(n + 1);
    vector<vector<pii>> have(n + 1);
    int cur = 2, ost = mid - 1;
    for (int i = 1; i <= n; i++) {
      if (ost == 0) {
        cur++;
        ost = 1;
        for (int j = 1; j < cur; j++) {
          ost *= mid;
        }
        ost--;
      }
      f[i] = f[i - 1] + cur;
      ost--;
    }
    int blya = n - 1, fuck = 1;
    cur = 1;
    while (blya > 0) {
      cur++;
      fuck *= mid;
      blya -= fuck;
    }
    if (cur > n || cur * (cur + 1) / 2 + f[n - cur] > sum) {
      l = mid;
      continue;
    }
    for (int i = 1; i <= cur; i++) {
      have[i].pb(MP(i, mid));
    }
    vector<int> p(n + 1);
    for (int i = 2; i <= cur; i++) {
      p[i] = have[i - 1].back().F;
      if (--have[i - 1].back().S == 0) {
        have[i - 1].pop_back();
      }
    }
    while (cur < n && (cur + 1) * (cur + 2) / 2 + f[n - cur - 1] <= sum) {
      cur++;
      p[cur] = have[cur - 1].back().F;
      if (--have[cur - 1].back().S == 0) {
        have[cur - 1].pop_back();
      }
      have[cur].pb(MP(cur, mid));
    }
    assert(cur < n);
    int curh = sum - cur * (cur + 1) / 2 - f[n - cur - 1];
    assert(curh >= 2);
    assert(curh <= cur);
    p[cur + 1] = have[curh - 1].back().F;
    if (--have[curh - 1].back().S == 0) {
      have[curh - 1].pop_back();
    }
    have[curh].pb(MP(cur + 1, mid));
    int cc = cur * (cur + 1) / 2 + curh;
    int kek = 2;
    ost = mid - 1;
    for (int i = cur + 2; i <= n; i++) {
      if (ost == 0) {
        kek++;
        ost = 1;
        for (int j = 1; j < kek; j++) {
          ost *= mid;
        }
        ost--;
      }
      ost--;
      p[i] = have[kek - 1].back().F;
      if (--have[kek - 1].back().S == 0) {
        have[kek - 1].pop_back();
      }
      have[kek].pb(MP(i, mid));
      cc += kek;
    }
    if (cc == sum) {
      r = mid;
      lp = p;
    }
    else {
      l = mid;
    }
  }
  cout << "Yes\n";
  for (int i = 2; i <= n; i++) {
    cout << lp[i] << ' ';
  }
}

signed main() {
#ifdef extraterrestrial_
  assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#else
#define TASK ""
  //assert(freopen(TASK".in", "r", stdin));
  //assert(freopen(TASK".out", "w", stdout));
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  source();
#ifdef extraterrestrial_
  cerr << "\n\nTIME :: " << clock() * 1.0 / CLOCKS_PER_SEC;
#endif
  return 0;
}