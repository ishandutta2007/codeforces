#include <bits/stdc++.h>
using namespace std;

long long get(int a, int k) {
  long long big = (long long) a % k * (a / k + 1) * (a / k + 1);
  long long small = (long long) (k - a % k) * (a / k) * (a / k);
  return big + small;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, t;
  cin >> n >> t;

  long long ans = 0;
  priority_queue<array<long long, 3>> que;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    ans += get(a, 1);
    que.push({get(a, 1) - get(a, 2), a, 2});
  }

  for (int i = n; i < t; ++i) {
    auto [d, a, l] = que.top();
    que.pop();
    ans -= d;
    que.push({get(a, l) - get(a, l + 1), a, l + 1});
  }

  cout << ans << "\n";
}