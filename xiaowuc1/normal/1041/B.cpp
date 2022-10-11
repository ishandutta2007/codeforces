#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  ll a, b, x, y;
  cin >> a >> b >> x >> y;
  ll g = __gcd(x, y);
  x /= g;
  y /= g;
  cout << min(a/x, b/y) << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL);
  solve();
}