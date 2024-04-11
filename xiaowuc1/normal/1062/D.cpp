#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  int n;
  cin >> n;
  ll ret = 0;
  for(int x = 2; x <= n; x++) {
    for(int y = 2*x; y <= n; y += x) {
      ret += 4*(y/x);
    }
  }
  cout << ret << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}