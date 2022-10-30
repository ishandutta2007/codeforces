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

vi p, c;

int getp(int v) {
//  assert(v >= 0 && v < p.size());
  if (v == p[v]) return v;
  return p[v] = getp(p[v]);
}

bool join(int a, int b) {
  a = getp(a); b = getp(b);
  if (a == b) {
    if (c[a]) return false;
    c[a] = 1;
  } else {
    if (c[a] && c[b]) return false;
    if (rand() % 2) swap(a, b);
    p[a] = b;
    c[b] |= c[a];
  }
  return true;
}

int main() {
  srand(131);
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, m;
  cin >> n >> m;
//  cerr << n << ' ' << m << endl;
  c.assign(n, 0);
  p.resize(n);
  for (int i = 0; i < n; ++i) p[i] = i;
  vector<array<int, 3>> e(m);
  for (int i = 0; i < m; ++i) {
    cin >> e[i][1] >> e[i][2] >> e[i][0];
    --e[i][1];
    --e[i][2];
  }
  sort(e.rbegin(), e.rend());
  ll res = 0;
  for (auto v : e) {
    if (join(v[1], v[2])) {
      res += v[0];
    }
  }
  cout << res << endl;
  return 0;
}