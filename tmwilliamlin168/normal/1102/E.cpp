#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

int main() {
  std::ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n + 1);
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    int v;
    cin >> v;
    if (mp.count(v)) {
      int l = mp[v];
      a[l]++, a[i]--;
    }
    mp[v] = i;
  }
  int cnt = 0;
  for (int i = 1; i < n; i++) {
    a[i] += a[i - 1];
    cnt += a[i] == 0;
  }
  long long ans = 1;
  for (int i = 0; i < cnt; i++) {
    ans = ans * 2 % mod;
  }
  cout << ans << endl;
  return 0;
}