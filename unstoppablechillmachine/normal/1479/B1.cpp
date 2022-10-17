#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back  
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
 
const int N = 1e5 + 10;
int a[N], nxt[N], lst[N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = n; i >= 1; i--) {
    if (!lst[a[i]]) {
      nxt[i] = n + 1;
    }
    else {
      nxt[i] = lst[a[i]];
    }
    lst[a[i]] = i;
  }
  nxt[0] = n + 1;
  int lst_pos1 = 0, lst_pos2 = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] != a[lst_pos1] && a[i] != a[lst_pos2]) {
      if (nxt[lst_pos1] < nxt[lst_pos2]) {
        lst_pos1 = i;
      }
      else {
        lst_pos2 = i;
      }
      ans++;
    }
    else if (a[i] != a[lst_pos1]) {
      lst_pos1 = i;
      ans++;
    }
    else if (a[i] != a[lst_pos2]) {
      lst_pos2 = i;
      ans++;
    }
    else {
      lst_pos1 = i;
    }
  }
  cout << ans << '\n';
}