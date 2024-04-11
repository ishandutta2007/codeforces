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
  set<int> add, rem;
  vi pos(n), res(n), ind(2 * n);
  for (int i = 0; i < 2 * n; ++i) {
    string s;
    cin >> s;
    int x;
    if (s == "+") {
      ind[i] = add.size();
      add.insert(i);
    } else {
      cin >> x;
      --x;
      pos[x] = i;
      rem.insert(i);
    }
  }
  bool fail = 0;
  for (int i = 0; i < n; ++i) {
    auto it = add.lower_bound(pos[i]);
    if (it == add.begin()) {
      fail = 1; break;
    }
    --it;
    res[ind[*it]] = i;
    auto it1 = rem.lower_bound(*it);
    if (*it1 != pos[i]) {
      fail = 1; break;
    }
    add.erase(it);
    rem.erase(pos[i]);
  }
  if (fail) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    for (int x : res) cout << x + 1 << ' ';
    cout << endl;
  }
  return 0;
}