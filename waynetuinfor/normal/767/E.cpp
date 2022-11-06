#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;
int n, m, c[maxn], w[maxn], rem;
long long ans;
bool pay[maxn];
priority_queue<pair<int, int>> pq;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> c[i];
  for (int i = 0; i < n; ++i) cin >> w[i];
  rem = m;
  for (int i = 0; i < n; ++i) {
    rem -= c[i] % 100;
    if (c[i] % 100) pq.push(make_pair(-w[i] * (100 - c[i] % 100), i));
    if (rem < 0) {
      pair<int, int> p = pq.top(); pq.pop();
      ans -= p.first;
      pay[p.second] = true;
      rem += 100;
    }
  }
  cout << ans << '\n';
  for (int i = 0; i < n; ++i) {
    if (pay[i]) cout << (c[i] / 100) + 1 << ' ' << 0 << '\n';
    else cout << c[i] / 100 << ' ' << c[i] % 100 << '\n';
  }
  return 0;
}