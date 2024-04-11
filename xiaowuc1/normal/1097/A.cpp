#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  string s;
  cin >> s;
  bool good = false;
  for(int i = 0; i < 5; i++) {
    string t;
    cin >> t;
    good |= s[1] == t[1];
    good |= s[0] == t[0];
  }
  if(good) cout << "YES\n";
  else cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}