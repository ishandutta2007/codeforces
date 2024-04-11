#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<double, double> pdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
//const int mod = ;

struct T {
  int c;
  int nx[2];
};

int sz = 1;
T pool[30 * 400000];

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  vi a(n), b(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
    int cur = 1;
    for (int t = 29; t >= 0; --t) {
      int x = (bool)(b[i] & (1 << t));
      if (pool[cur].nx[x] == 0) {
        ++sz;
        pool[cur].nx[x] = sz;
      }
      cur = pool[cur].nx[x];
      ++pool[cur].c;
    }
  }
  vi res(n);
  for (int i = 0; i < n; ++i) {
    res[i] = a[i];
    int cur = 1;
    for (int t = 29; t >= 0; --t) {
      int x = (bool)(a[i] & (1 << t));
      if (!pool[pool[cur].nx[x]].c) {
        x = 1 - x;
      }
      res[i] ^= x << t;
      cur = pool[cur].nx[x];
      assert(pool[cur].c);
      --pool[cur].c;
    }
    cout << res[i] << ' ';
  }
  return 0;
}