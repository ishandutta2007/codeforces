#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll need(ll a, ll b) {
  return (a+b-1)/b;
}

void solve() {
  ll n, k;
  cin >> n >> k;
  cout << need(2*n, k) + need(5*n, k) + need(8*n, k) << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL);
  solve();
}