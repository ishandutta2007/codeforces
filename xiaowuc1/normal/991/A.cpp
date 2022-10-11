#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  int a, b, c, n;
  cin >> a >> b >> c >> n;
  int aO = a-c;
  int bO = b-c;
  int both = c;
  int fail = n-aO-bO-both;
  if(aO < 0 || bO < 0 || both < 0 || fail <= 0) cout << "-1\n";
  else cout << fail << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}