#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (auto& i : a) {
    cin >> i;
  }

  int64_t ans = 0;
  int64_t sum = 0;
  vector<int> time(n);
  priority_queue<array<int, 2>> cur;
  for (int i = 0; i < n + k; ++i) {
    if (i < n) {
      cur.push({a[i], i});
      sum += a[i];
    }
    if (i >= k) {
      sum -= cur.top()[0];
      time[cur.top()[1]] = i;
      cur.pop();
    }
    ans += sum;
  }
  cout << ans << "\n";
  for (auto i : time) {
    cout << i + 1 << " ";
  }
  cout << "\n";
}