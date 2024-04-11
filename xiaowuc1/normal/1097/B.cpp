#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int l[20];

void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> l[i];
  }
  bool good = false;
  for(int mask = 0; mask < (1<<n); mask++) {
    int curr = 0;
    for(int i = 0; i < n; i++) {
      if(mask&(1<<i)) curr += l[i];
      else curr -= l[i];
    }
    curr %= 360;
    good |= curr == 0;
  }
  if(good) cout << "YES\n";
  else cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}