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
  int n;
  cin >> n;
  auto ask = [](int l, int r) {
    cout << "? " << l << ' ' << r << endl;
    int res;
    cin >> res;
    return res;
  };
  auto guess = [](int pos) {
    cout << "! " << pos << endl;
  };
  int pos = ask(1, n);
  if (pos < n && ask(pos, n) == pos) {
    int l = pos, r = n;
    while (r - l > 1) {
      int mid = (l + r) / 2;
      if (ask(pos, mid) == pos) {
        r = mid;
      }
      else {
        l = mid;
      }
    }
    guess(r);
  }
  else {
    int l = 1, r = pos;
    while (r - l > 1) {
      int mid = (l + r) / 2;
      if (ask(mid, pos) == pos) {
        l = mid;
      }
      else {
        r = mid;
      }
    }
    guess(l);
  }
}