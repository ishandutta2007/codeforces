//author: extraterrestrial_
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define int ll
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define pii pair<int, int>
const int INF = 1e9 + 10;
const ll BINF = 1e18 + 10;

struct T {
  int L, R, id;
  T() {};
  T(int l, int r, int i) : L(l), R(r), id(i) {};
};

bool cmp(T a, T b) {
  return a.R > b.R;
}

vector<int> solve(vector<pair<int, int>> arr) {
  vector<T> kek;
  for (int i = 0; i < SZ(arr); i++) {
    if (arr[i].S > arr[i].F) kek.pb(T(arr[i].F, arr[i].S, i + 1));
  }
  sort(all(kek), cmp);
  int curr = 2 * SZ(arr) + 1;
  vector<int> res;
  for (auto it : kek) {
    if (it.L < curr) {
      res.pb(it.id);
      curr = it.R;
    }
  }
  return res;
}

void source() {
  int n;
  cin >> n;
  vector<pair<int, int>> arr(n);
  for (auto &it : arr) {
    cin >> it.F >> it.S;
  }
  vector<int> ans1 = solve(arr);
  for (auto &it : arr) {
    it.F = 2 * n - it.F + 1;
    it.S = 2 * n - it.S + 1;
  }
  vector<int> ans2 = solve(arr);
  if (SZ(ans1) > SZ(ans2)) {
    cout << SZ(ans1) << '\n';
    for (auto it : ans1) {
      cout << it << ' ';
    }
  }
  else {
    cout << SZ(ans2) << '\n';
    for (auto it : ans2) {
      cout << it << ' ';
    }
  }
}

signed main() {
#ifdef extraterrestrial_
  assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output2.txt", "w", stdout));
#else
#define TASK ""
  //assert(freopen(TASK".in", "r", stdin));
  //assert(freopen(TASK".out", "w", stdout));
  //assert(freopenpen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
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