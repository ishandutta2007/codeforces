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
const int mod = 998244353;

ll mpow(ll x, ll n) {
  ll res = 1;
  while (n) {
    if (n & 1) res = res * x % mod; 
    x = x * x % mod;
    n /= 2;
  }
  return res;
}

ll inv(ll x) {
  return mpow(x, mod - 2);
}

void add(int& a, ll b) {
  a = (a + b) % mod;
}

const int M = 50;
int d[2][M + 1][M + 1][M + 1];

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, m;
  cin >> n >> m;
  vi a(n), w(n);
  ll W1 = 0, W2 = 0, W = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] == 0) a[i] = -1;
  }
  for (int i = 0; i < n; ++i) {
    cin >> w[i];
    W += w[i];
    if (a[i] == 1) {
      W1 += w[i];
    } else {
      W2 += w[i];
    }
  }
  for (int i = 0; i < n; ++i) {
    memset(d, 0, sizeof(d));
    d[0][0][0][0] = 1;
    for (int t = 0; t < m; ++t) {
      int tt = t % 2;
      memset(d[1-tt], 0, sizeof(d[1-tt]));
      for (int j1 = 0; j1 <= M; ++j1) for (int j2 = 0; j2 <= M; ++j2) {
        ll w1 = W1 + j1;
        ll w2 = W2 - j2;
        ll den = inv(w1 + w2);
        for (int k = 0; k <= M; ++k) if (d[tt][j1][j2][k]) {
          if (w1 + w2 == 0) {
            add(d[1-tt][j1][j2][k], d[tt][j1][j2][k]);
            continue;
          }
          ll curw = w[i] + a[i] * k;
//          cerr << j1 << ' ' << j2 << ' ' << k << ' ' << w1 << ' ' << w2 << ' ' << curw << " d: " << d[tt][j1][j2][k] << endl;
//          cerr << 12 * den % mod << endl;
          if (curw > 0) {
            add(d[1-tt][j1 + (a[i] == 1)][j2 + (a[i] == -1)][k + 1], d[tt][j1][j2][k] * curw % mod * den % mod);
          }
          if (w1 > 0) {
            add(d[1-tt][j1 + 1][j2][k], d[tt][j1][j2][k] * (w1 - (a[i] == 1 ? curw : 0)) % mod * den % mod);
          }
          if (w2 > 0) {
            add(d[1-tt][j1][j2 + 1][k], d[tt][j1][j2][k] * (w2 - (a[i] == -1 ? curw : 0)) % mod * den % mod);
          }
        }
      }
    }
    ll s = 0;
    int tt = m % 2;
    for (int j1 = 0; j1 <= M; ++j1) for (int j2 = 0; j2 <= M; ++j2) {
      for (int k = 0; k <= M; ++k) if (d[tt][j1][j2][k]) {
//        cerr << j1 << ' ' << j2 << ' ' << k << ' ' << d[tt][j1][j2][k] * (ll)12 % mod << endl;
        s = (s + d[tt][j1][j2][k] * (ll)(w[i] + a[i] * k)) % mod;
      }
    }
//    cerr << (s + mod) * 12 % mod << endl;
    cout << (s + mod) % mod << '\n';
  }
  return 0;
}