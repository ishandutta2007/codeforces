#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  int n, p, l, r;
  cin >> n >> p >> l >> r;
  if(l == 1 && r == n) {
    cout << 0;
  }
  else if(l == 1) {
    cout << abs(p-r) + 1;
  }
  else if(r == n) {
    cout << abs(p-l) + 1;
  }
  else {
    cout << r - l + min(abs(p-l), abs(p-r)) + 2;
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL);
  solve();
}