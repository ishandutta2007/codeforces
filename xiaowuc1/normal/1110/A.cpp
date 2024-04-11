#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  ll b, k;
  cin >> b >> k;
  ll curr = 0;
  for(int i = 0; i < k; i++) {
    curr *= b;
    ll t;
    cin >> t;
    curr += t;
    curr %= 2;
  }
  if(curr%2) cout << "odd\n";
  else cout << "even\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}