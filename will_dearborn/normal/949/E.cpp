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

void filter(vi & v) {
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
}

void out(const vi & v) {
  for (int x : v) cerr << x << ' ';
  cerr << endl;
}

const int DEBUG = 0;

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n = 100000;
  if (!DEBUG) cin >> n;
  vi a;
  for (int i = 0; i < n; ++i) {
    int x; 
    if (!DEBUG) cin >> x;
    else x = rand() % 200001 - 100000;
    if (x) a.push_back(x);
  }
  n = a.size();
  if (n == 0) {
    cout << 0 << endl;
    return 0;
  }
  vvi d(1, a);
  vii c(1, pii(0, 0));
  pii best;
  int mi = 50;
  vi tmp;
  tmp.reserve(200000);
  for (int i = 0; i <= 18; ++i) {
    vvi nd;
    vii nc;
    for (int j = 0; j < (int)d.size(); ++j) {
      if (__builtin_popcount(c[j].first) >= mi - 1) continue;
      bool has = 0;
      for (int x : d[j]) if (x & 1) {has = 1; break;}
//      out(d[j]); cerr << c[j].first << ' ' << c[j].second << ' ' << has << ' ' << mi << endl;
      if (!has) {
        nd.push_back(d[j]);
        for (auto& x : nd.back()) x /= 2;
        nc.push_back(c[j]);
      } else {
        for (int add = -1; add <= 1; add += 2) {
          pii mm = c[j];
          mm.first += 1 << i;
          if (add == -1) mm.second += 1 << i;
          tmp.clear();
          for (int x : d[j]) {
            if (x & 1) {
              int y = x - add;
              if (y) tmp.push_back(y / 2);
            } else tmp.push_back(x / 2);
          }
          filter(tmp);
          if (tmp.empty()) {
            int sz = __builtin_popcount(mm.first);
            if (sz < mi) {
              mi = sz;
              best = mm;
            }
          } else {
            nd.push_back(tmp);
            nc.push_back(mm);
          }
        }
      }
    }
    d.swap(nd);
    c.swap(nc);
  }
  cout << __builtin_popcount(best.first) << endl;
  for (int i = 0; i <= 20; ++i) if (best.first & (1 << i)) {
    if (best.second & (1 << i)) cout << -(1 << i) << ' ';
    else cout << (1 << i) << ' ';
  }
  cout << endl;
  return 0;
}