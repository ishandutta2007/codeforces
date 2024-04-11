#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int n;
  cin >> n;
  vector<int> a(n);
  for (int& i : a) cin >> i;
  ll ans = 0, cnt = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] == 1) ans += cnt;
    else cnt++;
  }
  cout << ans << '\n';
}