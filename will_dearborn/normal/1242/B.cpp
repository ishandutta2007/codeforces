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

vi p;

int getp(int v) {
  if (p[v] == v) return v;
  return p[v] = getp(p[v]);
}

void join(int a, int b) {
  a = getp(a);
  b = getp(b);
  p[a] = b;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, m;
  cin >> n >> m;
  vii e(m);
  vvi g(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    e[i] = pii(a, b);
    g[a].push_back(b);
    g[b].push_back(a);
  }
  p.resize(n);
  for (int i = 0; i < n; ++i) {
    p[i] = i;
    sort(g[i].begin(), g[i].end());
  }
  for (int v = 0; v < n; ++v) if ((int)g[v].size() >= n - 1 - 400) {
    int it = 0;
    for (int i : g[v]) {
      while (it < i) {
        join(v, it); ++it;
      }
      ++it;
    }
    while (it < n) {
      join(v, it); ++it;
    }
  }
  int c = 0;
  vi bad(n, 1);
  int was = 0;
  for (int i = 0; i < n; ++i) {
//    cerr << i+1 << ' ' << p[i]+1 << endl;
    if (p[i] != i) bad[i] = 0;
    if ((int)g[i].size() < n - 1 - 400) {
      bad[getp(i)] = 0;
      was = 1;
    }
  }
  for (int i = 0; i < n; ++i) c += bad[i];
  cout << max(0, c - 1 + was) << endl;
  return 0;
}