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
  string s;
  cin >> s;
  int n = s.size();
  char mi = 'z';
  for (int i = 0; i < n; ++i) {
    if (mi < s[i]) cout << "Ann\n";
    else {
      cout << "Mike\n";
      mi = s[i];
    }
  }
  return 0;
}