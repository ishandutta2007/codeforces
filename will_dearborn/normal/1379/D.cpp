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

vi ts;
int ind(int x) {
  return lower_bound(ts.begin(), ts.end(), x) - ts.begin();
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  ll n, h, m, k;
  cin >> n >> h >> m >> k;
  vi hh(n), v(n);
  ts.push_back(0);
  ts.push_back(m / 2);
  for (int i = 0; i < n; ++i) {
    cin >> hh[i] >> v[i];
    if (v[i] >= m / 2) v[i] -= m / 2;
    ts.push_back(v[i]);
    ts.push_back((v[i] + k) % (m / 2));
  }
  sort(ts.begin(), ts.end());
  ts.resize(unique(ts.begin(), ts.end()) - ts.begin());
  vi add(ts.size()), rem(ts.size());
  int cur = 0;
  for (int i = 0; i < n; ++i) {
    add[ind(v[i])]++;
    int r = v[i] + k;
    if (r > m / 2) {
      ++cur;
      rem[ind(r % (m / 2))]++;
    } else {
      rem[ind(r)]++;
    }
  }
//  cerr << cur << endl;
  pii best(cur, 0);
  for (int i = 0; i < ts.size(); ++i) {
    cur -= rem[i];
    best = min(best, pii(cur, i));
    cur += add[i];
  }
  int t = ts[best.second] % (m / 2);
  cout << best.first << ' ' << t << endl;
  vi bad;
  for (int i = 0; i < n; ++i) {
    if ((t > v[i] && t - v[i] < k) || (t + m / 2 > v[i] && t + m / 2 - v[i] < k)) bad.push_back(i + 1);
  }
  assert(bad.size() == best.first);
  for (int x : bad) cout << x << ' ';
  cout << endl;
  return 0;
}