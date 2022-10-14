#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <fstream>
 
#define pii pair<ll,ll>
#define mp make_pair
#define X first
#define Y second
 
typedef long long ll;
using namespace std;
 
ll n, t, k, x, y, m;
ll a[200500], b[200500];
ll c[200500];
vector<pii> ans;
 
ll l2(ll x) {
  ll ans = 1;
  while (ans * 2 <= x) {
    ans *= 2;
  }
  return ans;
}
ll get(ll x) {
  ll ans = 0;
  while (x != 1) {
    x /= 2;
    ans++;
  }
  return ans;
}
int main() {
  cin >> t;
  for (int ii = 0; ii < t; ii++){
    cin >> n;
    if (n == 2) {
      cout << -1 << "\n";
      continue;
    }
    ans.clear();
    for (int i = 0; i <= 100; i++) {
      b[i] = 0;
    }
    for (int i = 1; i <= 2 * n; i++) {
        a[i] = c[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
      a[i] = c[i] = 1;
    }
    
    for (int j = 0; j < 120; j++) {
    for (int i = n; i >= 1; i--) {
      ll p = l2(i);
      if (p != i && a[i] > 0 && a[p * 2 - i] > 0) {
        ll x = p * 2 - i;
          ll u = min(a[x], a[i]);
          a[x]-=u;
          a[i]-=u;
          c[x] -= u;
          c[i] -= u;
          for (int iii = 0; iii < u; iii++) {
            ans.push_back(mp(x, i));
          }
          c[i - x] += u;
          c[i + x] += u;
          //out << "HYU " << x << " " << i << " \n";
      }
    }
        for (int i = 1; i <= 2 * n; i++) {
            a[i] = c[i];
        }
    }
    for (int i = 1; i <= n * 2; i++) {
      if (a[i] > 0) {
          //cout << i << " " <<a[i] << "\n";
        b[get(i)] = a[i];
      }
    }
    ll mx = 0;
    ll zero = 0;
    for (int i = 0; i < 30; i++) {
      if (b[i] > 0) {
        mx = i;
      }
    }
    for (int i = 0; i <= mx - 2; i++) {
      if (b[i] % 2 == 1) {
        int j;
        for (j = mx - 1; j >= i; j--) {
          if (b[j] >= 2) {
            break;
          }
        }
        ans.push_back(mp(1<<j, 1<<j));
        ans.push_back(mp(0, (1<<i)));
        b[j] -= 2;
        b[j + 1]++;
        b[i]++;
      }
      for (int j = 0; j < b[i] / 2; j++) {
        ans.push_back(mp((1<<i), (1<<i)));
        if (zero == 0) {
          zero++;
          b[mx]--;
        } else {
          ans.push_back(mp(0, 1<<mx));
        }
      }
      b[mx] += b[i] / 2;
      b[i+1] += b[i] / 2;
 
      b[i] = 0;
 
//      cout << i << " " << "HYU" << " " << ans.size() << "\n";
    }
    for (int j = 0; j < b[mx-1] / 2; j++) {
      ans.push_back(mp(1<<(mx-1), 1<<(mx-1)));
      if (zero == 0) {
        zero = 1;
      } else {
        ans.push_back(mp(0, 1<<mx));
      }
    }
    b[mx-1] %= 2;
    if (b[mx-1] == 1) {
      if (zero == 1) {
        ans.push_back(mp(0, 1<<(mx-1)));
        ans.push_back(mp(1<<(mx-1), 1<<(mx-1)));
        ans.push_back(mp(1<<mx, 0));
      } else {
        cout << "HYU\n";
      }
    } else {
      if (zero == 1) {
        ans.push_back(mp(0, (1<<mx)));
      }
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i].X << " " << ans[i].Y << "\n";
    }
    for (int i = 0; i <= n * 4; i++) {
      a[i] = 0;
    }
  }
  return 0;
}