#include <bits/stdc++.h>
using namespace std;

const int N = 200000;
const int L = 50;

template <class T>
using min_queue = priority_queue<T, vector<T>, greater<T>>;

int l[N];

int check(int depth, int total, int k, min_queue<array<int, 2>> que) {
  while (!que.empty() && que.top()[0] == depth) {
    total += que.top()[1];
    que.pop();
  }

  while (!que.empty()) {
    int new_depth = que.top()[0];
    long long delta = (long long) total * (new_depth - depth);
    if (delta >= k) {
      return depth + (k - 1) / total;
    }
    depth = new_depth;
    k -= delta;

    while (!que.empty() && que.top()[0] == depth) {
      total += que.top()[1];
      que.pop();
    }
  }
  assert(false);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; ++i) {
    cin >> l[i];
  }

  sort(l, l + n, greater<int>());
  if (accumulate(l, l + n, 0LL) + 1 - 2 * n < k) {
    cout << -1 << "\n";
    exit(0);
  }

  long long white = 1;
  int total = 0, ans = INT_MAX;
  min_queue<array<int, 2>> que;

  for (int d = 0, i = 0; d < L && i < n; ++d) {
    while (!que.empty() && que.top()[0] == d) {
      total += que.top()[1];
      que.pop();
    }

    int j = -(d == 0);
    for ( ; i < n && j < total; ++i, ++j) {
      que.push({d + 2 + (l[i] - 1) / 2, -1});
      que.push({d + 2 + l[i] / 2, -1});
      que.push({d + 2, 2});
      white += l[i] - 2;
    }

    if (white >= k) {
      ans = min(ans, check(d + 1, total, k - total + j, que));
    }
  }

  cout << ans << "\n";
}