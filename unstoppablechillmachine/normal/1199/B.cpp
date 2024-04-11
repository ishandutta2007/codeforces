#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
#define F first
#define S second

signed main() {
  ios_base::sync_with_stdio(0);
  long double h, l;
  cin >> h >> l;
  cout << fixed << setprecision(10) << (l * l + h * h) / (2.0 * h) - h << '\n';
}