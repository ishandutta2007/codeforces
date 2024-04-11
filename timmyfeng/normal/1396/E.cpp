#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

vector<int> adj[N];
int val[N];
int sub[N];

void dfs_sub(int u, int p) {
  sub[u] = 1;
  for (auto c : adj[u]) {
    if (c != p) {
      dfs_sub(c, u);
      sub[u] += sub[c];
    }
  }
}

list<int> dfs_print(int u, int p) {
  list<int> all = {u};
  for (auto c : adj[u]) {
    if (c != p) {
      all.splice(all.end(), dfs_print(c, u));
    }
  }

  int cnt = (int(all.size()) - val[u]) / 2;
  assert(cnt >= 0);

  vector<array<int, 2>> pairs(cnt);
  for (int i = 0; i < cnt; ++i) {
    pairs[i][0] = all.front();
    pairs[cnt - 1 - i][1] = all.back();
    all.pop_front();
    all.pop_back();
  }

  for (auto [a, b] : pairs) {
    cout << a << " " << b << "\n";
  }
  assert(int(all.size()) == val[u]);
  return all;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  int64_t k;
  cin >> n >> k;

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs_sub(1, 0);

  int64_t mn = 0;
  int64_t mx = 0;
  for (int i = 2; i <= n; ++i) {
    val[i] = min(sub[i], n - sub[i]);
    mn += val[i] % 2;
    mx += val[i];
  }

  if (k < mn || k > mx || k % 2 != mn % 2) {
    cout << "NO\n";
    exit(0);
  }
  cout << "YES\n";

  int lo = 0;
  int hi = n / 2;
  int64_t cost = -1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;

    int64_t res = 0;
    for (int i = 2; i <= n; ++i) {
      if (val[i] <= mid) {
        res += val[i];
      } else {
        res += mid - (val[i] % 2 != mid % 2);
      }
    }

    if (res >= k) {
      hi = mid - 1;
      cost = res;
    } else {
      lo = mid + 1;
    }
  }
  assert(cost >= k);

  for (int i = 2; i <= n; ++i) {
    if (val[i] > lo) {
      val[i] = lo - (val[i] % 2 != lo % 2);
    }
    if (val[i] == lo && cost > k) {
      val[i] -= 2;
      cost -= 2;
    }
  }
  assert(cost == k);
  dfs_print(1, 0);
}