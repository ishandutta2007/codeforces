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

const int N = 2 << 19;
int a[2 * N];

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[N + i];
  }
  for (int i = N - 1; i > 0; --i) {
    a[i] = __gcd(a[2*i], a[2*i+1]);
  }
  int q;
  cin >> q;
  for (int test = 0; test < q; ++test) {
    int type;
    cin >> type;
    if (type == 1) {
      int l, r, x;
      cin >> l >> r >> x;
      l = N + l - 1;
      r = N + r - 1;
      int bad = 0;
      int pos = -1;
      while (l <= r) {
        if (l & 1) {
          if (a[l] % x) {
            ++bad;
            pos = l;
          }
          ++l;
        }
        if (!(r & 1)) {
          if (a[r] % x) {
            ++bad;
            pos = r;
          }
          --r;
        }
        if (l > r) break;
        l /= 2; r /= 2;
      }
//      cerr << bad << endl;
      if (bad > 1) {
        cout << "NO\n"; continue;
      }
      if (bad == 0) {
        cout << "YES\n"; continue;
      }
      while (pos < N && bad == 1) {
        bad = 0;
        int nx = 2 * pos;
        if (a[2*pos] % x) ++bad;
        if (a[2*pos+1] % x) {
          ++bad;
          ++nx;
        }
        pos = nx;
      }
      if (bad > 1) {
        cout << "NO\n"; continue;
      } else {
        cout << "YES\n"; continue;
      }
    } else {
      int i, y;
      cin >> i >> y;
      i = N + i - 1;
      a[i] = y;
      while (i > 1) {
        i /= 2;
        a[i] = __gcd(a[2*i], a[2*i+1]);
      }
    }
  }
  return 0;
}