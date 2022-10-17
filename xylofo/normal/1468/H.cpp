#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
  int n, k, m; cin >> n >> k >> m;
  int onEachSide = (k-1) / 2;
  vector<bool> keep(n);
  rep(i,0,m) {
    int temp; cin >> temp;
    keep[temp-1] = true;
  }
  if (onEachSide && (n-m) % (2*onEachSide)) {
    cout << "NO" << endl;
    return;
  }

  int left = 0;
  int right = n-m;
  rep(i,0,n) if (keep[i]) {
    if (left >= onEachSide && right >= onEachSide) {
      cout << "YES" << endl;
      return;
    }
  }
  else {
    left++;
    right--;
  }
  cout << "NO" << endl;
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);

  int t; cin >> t;
  while(t--) solve();
}