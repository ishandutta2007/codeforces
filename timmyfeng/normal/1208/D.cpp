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

  int upper_bound(T k) {
    int res = 0;
    T cur = 0;
    for (int i = 31 - __builtin_clz(n); i >= 0; --i) {
      if (res + (1 << i) <= n && cur + tree[res + (1 << i)] <= k) {
        res += 1 << i;
        cur += tree[res];
      }
    }
    return res + 1;
  }

};

const int N = 200'000;

long long s[N];
int ans[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  fenwick<long long> sum(n);

  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    sum.update(i + 1, i + 1);
  }

  for (int i = n - 1; i >= 0; --i) {
    ans[i] = sum.upper_bound(s[i]);
    sum.update(ans[i], -ans[i]);
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}