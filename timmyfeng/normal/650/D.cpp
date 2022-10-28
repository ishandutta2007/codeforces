#include <bits/stdc++.h>
using namespace std;

#include <bits/extc++.h>

template <class T, class Comp = less<T>>
using ordered_set = __gnu_pbds::tree<
  T, __gnu_pbds::null_type, Comp,
  __gnu_pbds::rb_tree_tag,
  __gnu_pbds::tree_order_statistics_node_update
>;

const int N = 400000;

vector<int> queries[N];
int a[N], b[N], h[N];

int before[N], after[N], freq[N], ans[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    cin >> h[i];
  }

  fill(ans, ans + m, 1);
  for (int i = 0; i < m; ++i) {
    cin >> a[i] >> b[i];
    queries[--a[i]].push_back(i);
  }

  ordered_set<int> lis;
  for (int i = 0; i < n; ++i) {
    for (auto j : queries[i]) {
      ans[j] += lis.order_of_key(b[j]);
    }

    auto it = lis.lower_bound(h[i]);
    if (it != lis.end()) {
      lis.erase(it);
    }
    before[i] = lis.order_of_key(h[i]);
    lis.insert(h[i]);
  }

  lis.clear();
  for (int i = n - 1; i >= 0; --i) {
    for (auto j : queries[i]) {
      ans[j] += lis.order_of_key(-b[j]);
    }

    auto it = lis.lower_bound(-h[i]);
    if (it != lis.end()) {
      lis.erase(it);
    }
    after[i] = lis.order_of_key(-h[i]);
    lis.insert(-h[i]);
  }

  int l = lis.size();
  for (int i = 0; i < n; ++i) {
    if (before[i] + 1 + after[i] == l) {
      ++freq[before[i]];
    }
  }

  for (int i = 0; i < m; ++i) {
    if (before[a[i]] + 1 + after[a[i]] == l) {
      ans[i] = max(ans[i], l - (freq[before[a[i]]] == 1));
    } else {
      ans[i] = max(ans[i], l);
    }
    cout << ans[i] << "\n";
  }
}