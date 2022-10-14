#include <bits/stdc++.h>

using namespace std;

struct segtree {
  vector<int> a;
  segtree(int n) {
    a.resize(4 * n);
    fill(a.begin(), a.end(), 1e9);
  }
  int get(int node, int l, int r, int ll, int rr) {
    if (l > r || ll > rr || l > rr || r < ll) return 1e9;
    if (ll <= l && r <= rr) {
      return a[node];
    }
    int mid = l + r >> 1;
    return min(get(node * 2, l, mid, ll, rr),
               get(node * 2 + 1, mid + 1, r, ll, rr));
  }
  void modify(int node, int l, int r, int pos, int val) {
    if (l > r || l > pos || r < pos) return;
    if (l == r) {
      a[node] = val;
      return;
    }
    int mid = l + r >> 1;
    if (pos <= mid) {
      modify(node * 2, l, mid, pos, val);
    } else {
      modify(node * 2 + 1, mid + 1, r, pos, val);
    }
    a[node] = min(a[node * 2], a[node * 2 + 1]);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, s, l;
  cin >> n >> s >> l;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  const int LOG = 20;
  vector<vector<int>> mn(n, vector<int>(LOG));
  vector<vector<int>> mx(n, vector<int>(LOG));
  for (int i = 0; i < n; i++) {
    mn[i][0] = mx[i][0] = a[i];
  }
  for (int j = 1; j < LOG; j++) {
    for (int i = 0; i + (1 << j) <= n; i++) {
      mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
      mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
    }
  }
  vector<int> logs(n + 1);
  for (int i = 2; i <= n; i++) {
    logs[i] = logs[i / 2] + 1;
  }
  auto Diff = [&](int l, int r) {
  int sz = r - l + 1, maxa = -1e9, mini = 1e9;
    for (int i = LOG - 1; i >= 0; i--) {
      if (sz & (1 << i)) {
        maxa = max(maxa, mx[l][i]);
        mini = min(mini, mn[l][i]);
        l += (1 << i);
      }
    }
    return maxa - mini;
  };
  const int inf = 1e9;
  vector<int> dp(n, inf), pos(n);
  for (int i = 0; i < n; i++) {
    int bot = 0, top = i;
    while (bot <= top) {
      int mid = bot + top >> 1;
      if (Diff(mid, i) <= s) {
        pos[i] = mid;
        top = mid - 1;
      } else {
        bot = mid + 1;
      }
    }
  }
  segtree st(n);
  for (int i = 0; i < n; i++) {
    if (pos[i] == 0 && i >= l - 1) {
      dp[i] = 1;
    } else {
      if (pos[i] - 1 <= i - l) {
        dp[i] = st.get(1, 0, n - 1, max(0, pos[i] - 1), i - l) + 1;
      }
    }
    st.modify(1, 0, n - 1, i, dp[i]);
  }
  cout << (dp[n - 1] >= inf ? -1 : dp[n - 1]) << '\n';
  return 0;
}