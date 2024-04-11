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
  vi p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    --p[i];
  }
  cout << 1;
  set<int> w;
  for (int i = 0; i < n; ++i) w.insert(i);
  for (int i = 0; i + 1 < n; ++i) {
    w.erase(p[i]);
    auto it = w.end(); --it;
    int x = *it;
//    cerr << i << ' ' << x << endl;
    cout << ' ' << (int)(i + 2 - (n - x - 1));
  }
  cout << " 1\n";
  return 0;
}