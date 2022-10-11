#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;

void solve() {
  ll n, k;
  cin >> n >> k;
  int a, b;
  cin >> a >> b;
  ll start = 1+a;
  ll lhs = 1e18;
  ll rhs = 1;
  for(int i = 0; i < n; i++) {
    {
      ll curr = (1+k*(ll)i)+b;
      ll diff = abs(start - curr);
      ll at = __gcd(diff, n*k);
      at = n*k / at;
      lhs = min(lhs, at);
      rhs = max(rhs, at);
    }
    {
      ll curr = (1+k*(ll)(i+1))-b;
      ll diff = abs(start - curr);
      ll at = __gcd(diff, n*k);
      at = n*k / at;
      lhs = min(lhs, at);
      rhs = max(rhs, at);
    }
  }
  cout << lhs << " " << rhs << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}