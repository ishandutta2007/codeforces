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

const int N = 2e5 + 10;
int n, a[N];
int check(int x) {
  if (x < 1 || x >= n) {
    return 0;
  }
  if (x & 1) {
    return (a[x] < a[x + 1] ? 0 : 1);
  }
  else {
    return (a[x] > a[x + 1] ? 0 : 1);
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> bad;
  int sum = 0;
  for (int i = 1; i < n; i++) {
    if (i & 1) {
      if (a[i] >= a[i + 1]) {
        sum++;
        bad.pb(i);
        bad.pb(i + 1);
      }
    }
    else {
      if (a[i] <= a[i + 1]) {
        sum++;
        bad.pb(i);
        bad.pb(i + 1);
      }
    }
  }
  bad.resize(unique(all(bad)) - bad.begin());
  if (SZ(bad) > 6) {
    cout << 0 << '\n';
    exit(0);
  }
  int ans = 0;
  for (int i : bad) {
    for (int j = 1; j <= n; j++) {
      if (j <= i && find(all(bad), j) != bad.end()) {
        continue;
      }
      int sm = i, bg = j;
      if (i > j) {
        swap(sm, bg);  
      }
      int sum2 = sum;
      sum2 -= check(sm - 1);
      sum2 -= check(sm);
      if (bg - 1 != sm) {
        sum2 -= check(bg - 1);
      }
      sum2 -= check(bg);
      swap(a[i], a[j]);
      sum2 += check(sm - 1);
      sum2 += check(sm);
      if (bg - 1 != sm) {
        sum2 += check(bg - 1);
      }
      sum2 += check(bg);
      swap(a[i], a[j]);
      if (sum2 == 0) {
        ans++;
      }
    }  
  }
  cout << ans << '\n';
}