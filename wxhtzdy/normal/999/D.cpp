#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int n, m;
  cin >> n >> m;
  vector<ll> a(n);
  vector<vector<ll>> pos(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    pos[a[i] % m].push_back(i);
  }
  int k = n / m;
  ll ans = 0;
  deque<int> d;
  for (int rep = 0; rep < 2; rep++) {
    for (int i = 0; i < m; i++) {
      if (pos[i].size() == k) continue;
      if (pos[i].size() > k) {
        while (pos[i].size() > k) {
          d.push_back(pos[i].back());
          pos[i].pop_back();
        }
      } else {
        while (pos[i].size() < k && (int) d.size() > 0) {
          int x = d.back();
          d.pop_back();
          ans += (i - (a[x] % m) + m) % m;
          a[x] += (i - (a[x] % m) + m) % m;
          pos[i].push_back(x);
        }
      }
    }
  }
  cout << ans << '\n';
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << '\n';
}