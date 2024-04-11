#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  int q;
  cin >> q;
  int last = 2e9;
  while(q--) {
    int x, y;
    cin >> x >> y;
    if(x > y) swap(x, y);
    if(y <= last) last = y;
    else if(x <= last) last = x;
    else {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}