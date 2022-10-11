#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  ll n;
  cin >> n;
  n++;
  if(n == 1) cout << "0\n";
  else if(n%2 == 0) cout << n/2 << "\n";
  else cout << n << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL);
  solve();
}