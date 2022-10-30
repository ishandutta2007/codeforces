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
  vi c(100005);
  for (int i = 0; i < n; ++i) {
    int a; cin >> a;
    c[a]++;
  }
  vi x;
  for (int i = 0; i < c.size(); ++i) if (c[i]) x.push_back(c[i]);
  reverse(x.begin(), x.end());
  for (int t : x) {
    if (t % 2) {
      cout << "Conan\n";
      return 0;
    }
  }
  cout << "Agasa\n";
  return 0;
}