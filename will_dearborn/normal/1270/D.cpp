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

pii ask(vi x) {
  cout << "?";
  for (int t : x) cout << ' ' << t + 1;
  cout << endl;
  int a, b;
  cin >> a >> b;
  return pii(a - 1, b);
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, k;
  cin >> n >> k;
  if (k == 1) {
    cout << "! 1" << endl;
    return 0;
  }
  n = min(n, k + 1);
  map<int, int> c;
  for (int i = 0; i < n; ++i) {
    vi x;
    for (int j = 0; j < n; ++j) if (j != i) x.push_back(j);
    pii a = ask(x);
    c[a.second] += 1;
  }
  vi v;
  for (pii p : c) {
    v.push_back(p.second);
  }
  assert(v.size() == 2);
  cout << "! " << (v[1] - v[0] + k + 1) / 2 << endl;
/*  vi x0(k);
  for (int i = 0; i < k; ++i) x0[i] = i;
  pii a0 = ask(x0);
  auto x1 = x0;
  x1.erase(x1.begin() + a0.first);
  x1.push_back(k);
  pii a1 = ask(x1);
  int mi = min(a0.second, a1.second);
  auto all = x0;
  all.push_back(k);
  for (int i = 0; i <= k; ++i) if (i != a0.first && i != a1.first) {
    auto x = all;
    x.erase(x.begin() + i);
    pii a = ask(x);
  }*/
  return 0;
}