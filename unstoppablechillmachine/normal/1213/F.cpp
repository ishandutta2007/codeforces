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
 
const int N = 2e5 + 10;
int a[N], b[N], pos1[N], pos2[N], ans[N];

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pos1[a[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    pos2[b[i]] = i;
  }  
  int cur = 0, cnt = 0;
  while (cur < n && cnt + 1 < k) {
    int pr1 = cur, pr2 = cur, mx1 = cur + 1, mx2 = cur;
    for (int i = 1; mx1 != mx2; i++) {
      if (i & 1) {
        int nmx2 = mx2;
        for (int j = pr1 + 1; j <= mx1; j++) {
          nmx2 = max(nmx2, pos2[a[j]]);
        }
        pr2 = mx2;
        mx2 = nmx2;
      }
      else {
        int nmx1 = mx1;
        for (int j = pr2 + 1; j <= mx2; j++) {
          nmx1 = max(nmx1, pos1[b[j]]);
        }
        pr1 = mx1;
        mx1 = nmx1;
      }
    }
    for (int i = cur + 1; i <= mx1; i++) {
      ans[a[i]] = cnt;
    }
    cnt++;
    cur = mx1;
  }
  if (cnt + 1 == k && cur < n) {
    for (int i = cur + 1; i <= n; i++) {
      ans[a[i]] = k - 1;
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
      cout << char('a' + ans[i]);
    }
    cout << '\n';
  }
  else {
    cout << "NO\n";
  }
}