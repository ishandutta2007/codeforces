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
 
const int N = 110; 
int a[N];

vector<int> solve(int l, int r, int h = 0) {
  if (l == r) {
    return {h};
  }
  pair<int, int> mx = {0, 0};
  for (int i = l; i <= r; i++) {
    mx = max(mx, make_pair(a[i], i));  
  }
  vector<int> rez;
  if (l < mx.S) {
    rez = solve(l, mx.S - 1, h + 1);
  }
  rez.pb(h);
  vector<int> rezR;
  if (mx.S < r) {
    rezR = solve(mx.S + 1, r, h + 1);
  }
  for (auto it : rezR) {
    rez.pb(it);
  }
  return rez;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> rez = solve(0, n - 1);
    for (auto it : rez) {
      cout << it << ' ';
    }
    cout << '\n';
  }
}