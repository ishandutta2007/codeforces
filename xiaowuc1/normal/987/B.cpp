#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;

void solve() {
  long double x, y;
  cin >> x >> y;
  long double xx = x / log(x);
  long double yy = y / log(y);
  if(xx == yy) cout << "=\n";
  else if(xx > yy) cout << "<\n";
  else cout << ">\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}