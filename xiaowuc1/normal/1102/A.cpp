#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n;
  cin >> n;
  ll ret = n*(n+1LL) / 2;
  printf("%lld\n", ret%2);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}