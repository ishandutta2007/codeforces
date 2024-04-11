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

const int DEBUG = 0;

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n = 3e5;
  if (!DEBUG) cin >> n;
  vi a(n);
  for (int i = 0; i < n; ++i) {
    if (!DEBUG) cin >> a[i];
    else a[i] = rand() % (1 << 30);
  }
  ll res = 0, x = 0;
  unordered_map<int, array<int, 2>> c;
  c.reserve(n);
  for (int b = 30; b >= 0; --b) {
    int B = 1 << b;
    vl s(2);
    c.clear();
    for (int i = 0; i < n; ++i) {
      int t = a[i] >> b;
      if (t % 2 == 0) s[0] += c[t / 2][1];
      else s[1] += c[t / 2][0];
      c[t / 2][t % 2]++;
    }
    res += min(s[0], s[1]);
    if (s[0] > s[1]) x += B;
  }
  cout << res << ' ' << x << endl;
  return 0;
}