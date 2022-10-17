#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
	string s;
  cin >> s;
  vector<int> x, y;
  for (int i = 0; i < SZ(s); i++) {
    if (s[i] == '(') {
      x.pb(i);
    }
    else {
      y.pb(i);
    }
  } 
  reverse(all(y));
  vector<int> ax, ay;
  for (int i = 0; i < min(SZ(x), SZ(y)); i++) {
    if (x[i] > y[i]) {
      break;
    }
    ax.pb(x[i]);
    ay.pb(y[i]);
  }
  reverse(all(ay));
  if (ax.empty()) {
    cout << 0 << '\n';
  }
  else {
    cout << 1 << '\n';
    cout << SZ(ax) * 2 << '\n';
    for (auto it : ax) {
      cout << it + 1 << ' ';
    }
    for (auto it : ay) {
      cout << it + 1 << ' ';
    }
    cout << '\n';
  }
}