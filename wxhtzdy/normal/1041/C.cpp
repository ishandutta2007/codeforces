#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, d;
  cin >> n >> m >> d;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> p(n);
  iota(p.begin(), p.end(), 0);
  sort(p.begin(), p.end(), [&](int i, int j) {
    return a[i] < a[j];
  });
  auto Can = [&](int x) {
    deque<int> dq;
    for (int i = 0; i < n; i++) {
      if (dq.size() < x) {
        dq.push_back(a[p[i]]);
      } else {
        if (a[p[i]] - dq[0] <= d) {
          return false;
        }
        dq.pop_front();
        dq.push_back(a[p[i]]);
      }
    }
    return true;
  };
  int low = 1, high = 1e9, ans;
  while (low <= high) {
    int mid = low + high >> 1;
    if (Can(mid)) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  cout << ans << "\n";
  vector<int> when(n);
  for (int i = 0; i < n; i++) {
    when[p[i]] = i % ans;
  }
  for (int i = 0; i < n; i++) {
    cout << when[i] + 1 << " ";
  }
  return 0;
}