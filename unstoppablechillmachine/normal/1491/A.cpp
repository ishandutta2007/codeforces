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
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  int cnt_ones = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt_ones += (a[i] == 1);
  } 
  for (int i = 0; i < m; i++) {
    int type, x;
    cin >> type >> x;
    if (type == 1) {
      a[x] ^= 1;
      if (a[x]) {
        cnt_ones++;
      }
      else {
        cnt_ones--;
      }
    }
    else {
      cout << (cnt_ones >= x ? 1 : 0) << '\n';
    }
  }
}