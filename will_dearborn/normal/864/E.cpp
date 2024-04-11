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

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  vector<array<int, 4>> v(n);
  vi t(n + 1);
  for (int i = 0; i < n; ++i) {
    cin >> v[i][1] >> v[i][0] >> v[i][2];
    v[i][3] = i + 1;
    t[i+1] = v[i][1];
  }
  sort(v.begin(), v.end());
  vi d(2005, 0);
  vvi p(d.size());
  for (int i = 0; i < n; ++i) {
    for (int j = v[i][0]-1; j >= v[i][1]; --j) {
      int nd = d[j - v[i][1]] + v[i][2];
      if (d[j] < nd) {
        d[j] = nd;
        p[j] = p[j - v[i][1]];
        p[j].push_back(v[i][3]);
      }
    }
  }
  int ma = 0, cur = 0;
  for (int i = 0; i < d.size(); ++i) if (d[i] > ma) {
    ma = d[i];
    cur = i;
  }
  cout << ma << endl;
  cout << p[cur].size() << endl;
  for (int i : p[cur]) cout << i << ' ';
  return 0;
}