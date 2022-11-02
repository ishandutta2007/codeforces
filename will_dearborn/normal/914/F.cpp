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

bitset<100000> w[26];
bitset<100000> tmp;

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  string s;
  int q;
  cin >> s >> q;
  for (int i = 0; i < s.size(); ++i) w[s[i]-'a'].set(i);
  for (int test = 0; test < q; ++test) {
    int type;
    cin >> type;
    if (type == 1) {
      int i;
      string c;
      cin >> i >> c;
      --i;
      w[s[i]-'a'].reset(i);
      s[i] = c[0];
      w[s[i]-'a'].set(i);
    } else {
      int l, r;
      string y;
      cin >> l >> r >> y;
      --l; r -= y.size();
//      cerr << l << ' ' << r << endl;
      if (l > r) {
        cout << 0 << endl;
        continue;
      }
      tmp.set();
      for (int i = 0; i < y.size(); ++i) {
//        for (int j = 0; j < s.size(); ++j) cout << (int)tmp.test(j); cout << endl;
        tmp &= w[y[i]-'a']>>i;
      }
      tmp >>= l;
      tmp <<= l + 100000 - r - 1;
      int res = tmp.count();
      //for (int i = l; i <= r; ++i) res += tmp.test(i);
      cout << res << endl;
    }
  }
  return 0;
}