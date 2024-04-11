#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  const int N = (int) 2e5 + 1;
  auto Can = [&](int x) {
    vector<int> cnt(N, 0);
    for (int i = 0; i < n; i++) {
      cnt[a[i]] += 1;
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
      ans += cnt[i] / x;
    }
    return ans >= k;
  };
  int bot = 1, top = n, ans = 1;
  while (bot <= top) {
    int mid = bot + top >> 1;
    if (Can(mid)) {
      ans = mid, bot = mid + 1;
    } else {
      top = mid - 1;
    }
  }
  vector<int> cnt(N, 0);
  for (int i = 0; i < n; i++) {
    cnt[a[i]] += 1;
  }
  vector<int> b;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < cnt[i] / ans; j++) {
      b.push_back(i);
    }
  }
  for (int i = 0; i < k; i++) {
    cout << b[i] << " ";
  }
  return 0;
}