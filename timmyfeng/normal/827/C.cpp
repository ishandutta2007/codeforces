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

const int A = 4;
const int K = 10;

fenwick<int> fenw[A][K][K];

int id(char c) {
  switch (c) {
    case 'A':
      return 0;
    case 'T':
      return 1;
    case 'G':
      return 2;
    default:
      return 3;
  }
}

void update(int i, int x, int k) {
  for (int j = 0; j < 10; ++j) {
    fenw[i][j][x % (j + 1)].update(x, k);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  int n = s.size();

  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 10; ++j) {
      for (int k = 0; k <= j; ++k) {
        fenw[i][j][k] = fenwick<int>(n);
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    update(id(s[i - 1]), i, 1);
  }

  int q;
  cin >> q;
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int x;
      cin >> x;
      update(id(s[x - 1]), x, -1);
      cin >> s[x - 1];
      update(id(s[x - 1]), x, 1);
    } else {
      int l, r;
      string t;
      cin >> l >> r >> t;
      int m = t.size();
      int ans = 0;
      for (int i = 1; i <= m; ++i) {
        fenwick<int> &f = fenw[id(t[i - 1])][m - 1][(l + i - 1) % m];
        ans += f.query(r) - f.query(l - 1);
      }
      cout << ans << "\n";
    }
  }
}