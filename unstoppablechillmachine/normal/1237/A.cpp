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
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &it : a) {
    cin >> it;
  }
  vector<bool> can(n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (abs(a[i]) & 1) {
      can[i] = true;
      a[i] = (a[i] - 1) / 2;
    }
    else {
      a[i] /= 2;
    }
    sum += a[i];
  }
  for (int i = 0; i < n; i++) {
    if (can[i] && sum < 0) {
      sum++;
      a[i]++;
    }
  }
  assert(sum == 0);
  for (int i =0 ; i < n; i++) {
    cout << a[i] << '\n';
  }
}