#include <bits/stdc++.h>
using namespace std;

const int maxn = 200000 + 5;
map<int, int> mx, my;
map<pair<int, int>, int> m;
int N, x, y;
long long ans;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> x >> y;
    m[make_pair(x, y)]++;
    mx[x]++, my[y]++;
  }
  for (auto i : mx) ans += (long long)i.second * (long long)(i.second - 1) / 2;
  for (auto i : my) ans += (long long)i.second * (long long)(i.second - 1) / 2;
  for (auto i : m) ans -= (long long)i.second * (long long)(i.second - 1) / 2;
  cout << ans << '\n';
  return 0;
}