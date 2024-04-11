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

int ask(vi a) {
  cout << "?";
  for (int x : a) cout << ' ' << x;
  cout << endl;
  int k;
  cin >> k;
  return k;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  vi p(n);
  vi a(n);
  vi pos(n + 1);
  for (int i = 2; i <= n; ++i) {
    a.assign(n, 1);
    a[n - 1] = i;
    pos[i] = ask(a);
    if (pos[i] == 0) {
      p[n - 1] = n - i + 2;
      break;
    } else if (i == n) {
      p[n - 1] = 1;
    }
  }
  for (int i = 2; i <= n; ++i) if (pos[i]) p[pos[i] - 1] = p[n - 1] + i - 1;
  for (int j = p[n - 1] - 1; j >= 1; --j) {
    a.assign(n, 1 + p[n - 1] - j);
    a[n - 1] = 1;
    int k = ask(a);
    p[k - 1] = j;
  }
  cout << "! ";
  for (int x : p) cout << x << ' ';
  cout << endl;
  return 0;
}