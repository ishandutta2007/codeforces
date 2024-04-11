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
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, p;
  cin >> n >> p;
  for (int i = 1; i <= 100; i++) {
    int cur = n - p * i;
    if (cur < i) {
      break;
    }
    if (__builtin_popcountll(cur) <= i) {
      cout << i << '\n';
      exit(0);
    }
  }
  cout << -1 << '\n';
}