// 913D
// problemi che danno un punto se e solo se sono stati risolti al massimo a[i] problemi
// idee:

#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, tt, n, m, res, a[200010], t[200010], bsl, bsu, bsm, s;
vector<long long> g;
vector<pair<long long, long long>> r;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> n >> tt;
  for (i = 0; i < n; i++) {
    cin >> a[i] >> t[i];
  }

  bsl = 1;
  bsu = n + 1;

  while (bsl != bsu) {
    // cout << bsl << ' ' << bsu << endl;
    bsm = (bsl + bsu) / 2;
    g.clear();
    for (i = 0; i < n; i++) {
      if (a[i] >= bsm) {
        g.push_back(t[i]);
      }
    }
    if (g.empty()) {
      bsu = bsm;
    } else if (g.size() < bsm) {
      bsu = bsm;
    } else {
      sort(g.begin(), g.end());
      s = 0;
      for (i = 0; i < bsm; i++) {
        s += g[i];
      }
      if (s > tt) {
        bsu = bsm;
      } else {
        bsl = bsm + 1;
      }
    }
    // cout << s << endl;
  }

  cout << bsl - 1 << endl << bsl - 1 << endl;
  for (i = 0; i < n; i++) {
    if (a[i] >= bsl - 1) {
      r.push_back({t[i], i});
    }
  }
  sort(r.begin(), r.end());
  for (i = 0; i < bsl - 1; i++) {
    cout << r[i].second + 1 << ' ';
  }

  return 0;
}