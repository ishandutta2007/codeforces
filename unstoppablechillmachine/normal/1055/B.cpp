//author: extraterrestrial_
#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,avx,tune=native")
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define _ inline
#define pb push_back
#define int ll
#define F first
#define S second
#define MP make_pair
#define SZ(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pw(x) (1ll << (x))
#ifdef extraterrestrial_
  #define debug(x) cerr << #x << ": " << x << '\n';
#else
  #define debug(x)
#endif
const int INF = 1e9 + 10;
const ll BINF = 1e18 + 10;

void source() {
  int n, m, l;
  cin >> n >> m >> l;
  vector<int> arr(n);
  for (auto &it : arr) {
    cin >> it;
  }
  int cur = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] > l && (i == 0 || arr[i - 1] <= l)) {
      cur++;
    }
  }
  for (int i = 0; i < m; i++) {
    int type;
    cin >> type;
    if (!type) {
      cout << cur << '\n';
    }
    else {
      int num, add;
      cin >> num >> add;
      num--;
      if (arr[num] <= l && arr[num] + add > l) {
        cur++;
        if (num > 0 && arr[num - 1] > l) {
          cur--;
        }
        if (num + 1 < n && arr[num + 1] > l) {
          cur--;
        }
      }
      arr[num] += add;
    }
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