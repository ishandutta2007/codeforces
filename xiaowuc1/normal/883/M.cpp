#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  int xa, ya, xb, yb;
  cin >> xa >> ya >> xb >> yb;
  cout << 2 * (max(abs(xa-xb) + 1, 2) + max(abs(ya - yb) + 1, 2)) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}