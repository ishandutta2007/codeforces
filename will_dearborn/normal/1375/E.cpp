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

void solve(vi a) {
  vii res;
  vii ts;
  int n = a.size();
  for (int i = 0; i < n; ++i) {
    ts.emplace_back(a[i], -i);
  }
  sort(ts.begin(), ts.end());
  for (pii p : ts) {
    int pos = -p.second;
    for (int i = n - 1; i > pos; --i) {
      if (p.first > a[i]) {
        res.emplace_back(pos, i);
        swap(a[pos], a[i]);
      }
    }
  }
  for (int i = 0; i + 1 < a.size(); ++i) assert(a[i] <= a[i + 1]);
  cout << res.size() << '\n';
  for (pii p : res) {
    cout << p.first + 1 << ' ' << p.second + 1 << '\n';
  }
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  if (0) for (int n = 1; n < 10; ++n) for (int t = 0; t < 10000; ++t) {
    vi a(n);
    for (int i = 0; i < n; ++i) a[i] = rand() % n;
    solve(a);
  }
  int n;
  cin >> n;
  vi a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  solve(a);
/*  vi v;
  while (!a.empty()) {
    pii ma(0, 0);
    for (int i = 0; i < a.size(); ++i) ma = max(ma, pii(a[i], i));
    if (ma.second != a.size() - 1) {
      v.clear();
      for (int i = a.size() - 1; i > ma.second; --i) {
        if (v.empty() || a[i] >= a[v.back()]) v.push_back(i);
      }
      assert(!v.empty());
      int cur = ma.second;
      for (int i = 0; i < v.size();) {
        int j = i;
        while (j < v.size() && a[v[j]] == a[v[i]]) ++j;
        swap(a[cur], a[v[j - 1]]);
        for (int t = j - 1; t >= i; --t) res.emplace_back(cur, v[t]);
        i = j;
      }
    }
    assert(a.back() == ma.first);
    a.pop_back();
  }*/
  return 0;
}