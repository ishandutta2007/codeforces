#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
#define F first
#define S second
 
signed main() {
  ios_base::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &it : a) {
    cin >> it;
  }  
  sort(all(a));
  a.pb(2e9 + 10);
  int ptr = n / 2, curcnt = 1;
  for (;;) {
    if ((a[ptr + 1] - a[ptr]) * curcnt < k) {
      k -= curcnt * (a[ptr + 1] - a[ptr]);
      ptr++;
      curcnt++;
    }
    else {
      cout << a[ptr] + k / curcnt << '\n';
      exit(0);
    }
  }
}