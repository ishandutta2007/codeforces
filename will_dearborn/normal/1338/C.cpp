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

ll f(ll n) {
  --n;
  ll r = n % 3, r1 = 0;
  n /= 3;
  ll res = 0;
  vl c(60), s(62);
  for (int b = 0; b < c.size(); b += 2) {
    c[b] = 1LL << b;
    s[b + 2] = s[b] + c[b];
  }
  for (int b = 60; b >= 0; b -= 2) {
//    cerr << "nr " << n << ' ' << r << ' ' << r1 << endl;
    if (n >= s[b]) {
      n -= s[b] + 1;
      if (r == 0) res += 1LL << b;
      if (r == 1) res += 1LL << (b + 1);
      if (r == 2) res += (1LL << b) * 3;
      if (n == -1) break;
      for (int b1 = 0; b1 < b; b1 += 2) if (n < 3 * s[b1 + 2]) {
        int t = (n - 3 * s[b1]) / c[b1];
        r = (r + t - r1 + 3) % 3;
        n = (n - 3 * s[b1]) % c[b1] + s[b1];
        r1 = t;
        break;
      }
//      r = (r + n / s[b]) % 3;
//      n %= s[b];
    }
  }
  return res;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int N = 10000;
  vi was(N);
  vl q;
  for (int i = 1; i < N / 4; ++i) if (!was[i]) {
    was[i] = 1;
    for (int j = i + 1; j < N; ++j) if (!was[j] && !was[i^j]) {
      was[j] = 1;
      was[i ^ j] = 1;
      q.push_back(i);
      q.push_back(j);
      q.push_back(i^j);
//      if (i < 256) cerr << bitset<8>(i) << ' ' << bitset<8>(j) << ' ' << bitset<8>(i^j) << endl;
      break;
    }
  }
  for (int i = 0; i < q.size(); ++i) {
    ll q1 = f(i + 1);
//    cerr << i << ' ' << q[i] << ' ' << q1 << endl;
    assert(q[i] == q1);
  }
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    ll n;
    cin >> n;
    cout << f(n) << '\n';
  }
  return 0;
}