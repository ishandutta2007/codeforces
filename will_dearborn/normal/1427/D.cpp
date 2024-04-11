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

void out(vi v) {
  for (auto x : v) cerr << x << ' ';
  cerr << endl;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  vi a(n);
  vi id(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    id[i] = i + 1;
  }
  vvi v;
  while (a != id) {
    vi pos(n + 1);
    for (int i = 0; i < n; ++i) {
      pos[a[i]] = i;
    }
    for (int i = 1; i < n; ++i) if (pos[i] > pos[i + 1]) {
      vi x;
      int len = 1;
      while (a[pos[i + 1] + len] == i + 1 + len) ++len;
      if (pos[i + 1]) x.push_back(pos[i + 1]);
      x.push_back(len);
      x.push_back(pos[i] - pos[i + 1] - len + 1);
      if (pos[i] < n - 1) x.push_back(n - pos[i] - 1);
      v.push_back(x);
      vi b(n);
      int it = n;
      for (int l : x) {
        for (int j = 0; j < l; ++j) b[j + it - l] = a[n - it + j];
        it -= l;
      }
      a.swap(b);
      break;
    }
    out(a);
  }
/*  for (int i = 1; i <= n && a != id; ++i) {
    int need = i == n ? 1 : i;
    if (a[0] == need) continue;
    for (int j = 0; j < n; ++j) if (a[j] == need) {
      v.push_back({j, n - j});
      vi b;
      for (int t = j; t < n; ++t) b.push_back(a[t]);
      for (int t = 0; t < j; ++t) b.push_back(a[t]);
      a.swap(b);
      break;
    }
  }*/
  cout << v.size() << '\n';
  for (vi x : v) {
    cout << x.size();
    for (int i : x) cout << ' ' << i;
    cout << '\n';
  }
  return 0;
}