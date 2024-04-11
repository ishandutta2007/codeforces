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

vi fen;
void add(int i, int val) {
  for (; i < fen.size(); i |= i + 1)
    fen[i] = max(fen[i], val);
}

int getm(int i) {
  int res = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1)
    res = max(res, fen[i]);
  return res;
}

vi f(const vi& v) {
  fen.assign(v.size() + 1, 0);
  vi res(v.size());
  for (int i = 0; i < v.size(); ++i) {
    res[i] = getm(v[i]) + 1;
    add(v[i], res[i]);
  }
  return res;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, m;
  cin >> n >> m;
  vi l(n), r(n);
  vii q;
  for (int i = 0; i < n; ++i) {
    cin >> l[i] >> r[i];
    q.emplace_back(l[i] - 1, 1);
    q.emplace_back(r[i], -1);
  }
  sort(q.begin(), q.end());
  int cur = 0, it = 0;
  vi v(m);
  for (int i = 0; i < m; ++i) {
    while (it < q.size() && q[it].first == i) {
      cur += q[it].second;
      ++it;
    }
    v[i] = cur;
  }
  vi a = f(v);
  reverse(v.begin(), v.end());
  vi b = f(v);
  int res = 0;
  for (int i = 0; i < m; ++i) {
    res = max(res, a[i] + b[m-i-1] - 1);
  }
  cout << res << endl;
  return 0;
}