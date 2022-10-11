#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> matrix;

void solve() {
  int n;
  cin >> n;
  ll x = 0;
  ll y = 0;
  for(int i = 0; i < 2*n; i++) {
    ll xx, yy;
    cin >> xx >> yy;
    x += xx;
    y += yy;
  }
  cout << x/n << " " << y/n << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cerr.tie(NULL);
  solve();
}