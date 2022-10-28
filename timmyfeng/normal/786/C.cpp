#include <bits/stdc++.h>
using namespace std;

template <class T>
struct fenwick {

  vector<T> tree;
  int n;

  fenwick() {}

  fenwick(int n) : n(n) {
    tree.resize(n + 1);
  }

  void update(int a, T val) {
    for ( ; a <= n; a += a & -a) {
      tree[a] += val;
    }
  }

  T query(int a) {
    T res = 0;
    for ( ; a > 0; a -= a & -a) {
      res += tree[a];
    }
    return res;
  }

  int lower_bound(T k) {
    int res = 0;
    T cur = 0;
    for (int i = 31 - __builtin_clz(n); i >= 0; --i) {
      if (res + (1 << i) <= n && cur + tree[res + (1 << i)] < k) {
        res += 1 << i;
        cur += tree[res];
      }
    }
    return res + 1;
  }

};

const int N = 100'000 + 1;

vector<int> indices[N];
vector<int> todo[N];
int ans[N];
int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  fenwick<int> unique(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    --a[i];

    if (indices[a[i]].empty()) {
      unique.update(i + 1, 1);
    }
    indices[a[i]].push_back(i);

    todo[0].push_back(i + 1);
  }

  for (int i = 0; i < n; ++i) {
    reverse(indices[i].begin(), indices[i].end());
  }

  for (int i = 0; i < n; ++i) {
    for (auto k : todo[i]) {
      int reach = unique.lower_bound(k + 1) - 1;
      ++ans[k];
      if (reach < n) {
        todo[reach].push_back(k);
      }
    }
    todo[i].clear();

    unique.update(i + 1, -1);
    indices[a[i]].pop_back();
    if (!indices[a[i]].empty()) {
      unique.update(indices[a[i]].back() + 1, 1);
    }
  }

  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}