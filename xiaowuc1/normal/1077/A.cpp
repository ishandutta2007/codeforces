#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void realsolve() {
  ll a, b, k;
  cin >> a >> b >> k;
  cout << a * ((k+1)/2) - b * (k / 2) << "\n";
}

void solve() {
  int n;
  cin >> n;
  while(n--) realsolve();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}