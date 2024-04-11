#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//const int mod = ;

ll f(ll n) {
  if (n < 10) return n;
  ll res = 1;
  while (n) {
    int r = n % 10;
    n /= 10;
    if (r) res *= r;
  }
  return f(res);
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T;
  cin >> T;
  vi v(1000005);
  for (int i = 1; i < v.size(); ++i) {
    v[i] = f(i);
  }
  vector<array<int, 10>> s(v.size() + 1);
  for (int i = 0; i < v.size(); ++i) {
    s[i+1] = s[i];
    s[i+1][v[i]]++;
  }
  for (int test = 1; test <= T; ++test) {
    int l, r, k;
    cin >> l >> r >> k;
    cout << s[r + 1][k] - s[l][k] << endl;
  }
  return 0;
}