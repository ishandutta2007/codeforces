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
/*  if (s[0] == '1' || s[n-1] == '1') {
    cout << -1 << endl;
    return 0;
  }*/
  vvi res;
  vvi last(2);
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') {
      if (!last[1].empty()) {
        int j = last[1].back();
        res[j].push_back(i);
        last[1].pop_back();
        last[0].push_back(j);
      } else {
        last[0].push_back(res.size());
        res.push_back(vi(1, i));
      }
    } else {
      if (last[0].empty()) {
        cout << -1 << endl; return 0;
      }
      int j = last[0].back();
      res[j].push_back(i);
      last[0].pop_back();
      last[1].push_back(j);
    }
  }
  if (!last[1].empty()) {
    cout << -1 << endl; return 0;
  }
  cout << res.size() << endl;
  for (int i = 0; i < res.size(); ++i) {
    cout << res[i].size();
    for (int x : res[i]) cout << ' ' << x+1;
    cout << endl;
  }
  return 0;
}