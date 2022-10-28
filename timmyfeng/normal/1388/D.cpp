#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;

int b[N];
long long a[N];
bool visited[N];
vector<int> ops;
vector<int> order;
vector<int> todo[N];

long long ans;

void dfs_sort(int u) {
  if (u == -1 || visited[u])
    return;
  visited[u] = true;
  dfs_sort(b[u]);
  order.push_back(u);
}

void process(int u) {
  ops.push_back(u);
  for (int i : todo[u]) {
    process(i);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
  }

  for (int i = 1; i <= n; ++i) {
    dfs_sort(i);
  }

  memset(visited, false, sizeof visited);
  while (!order.empty()) {
    int u = order.back();
    order.pop_back();
    ans += a[u];
    if (b[u] != -1) {
      if (a[u] < 0) {
        todo[b[u]].push_back(u);
      } else {
        a[b[u]] += a[u];
        process(u);
      }
    } else {
      process(u);
    }
  }

  cout << ans << "\n";
  for (auto i : ops) {
    cout << i << " ";
  }
}