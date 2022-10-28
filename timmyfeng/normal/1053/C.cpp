#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;
const int M = 1e9 + 7;

int a[N];
int w[N];

int add(int a, int b) {
  return (a += b) < M ? a : a - M;
}

int sub(int a, int b) {
  return (a -= b) < 0 ? a + M : a;
}

int mul(int a, int b) {
  return 1LL * a * b % M;
}

template <class T>
struct fenwick_tree {

  T tree[N];

  void update(int a, T val) {
    for ( ; a < N; a += a & -a) {
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

  T query(int a, int b) {
    return query(b) - query(a - 1);
  }

};

struct mint {
  int val;

  mint() {}
  mint(int _val) : val(_val) {}

  void operator+=(mint oth) {
    val = add(val, oth.val);
  }

  int operator-(mint oth) {
    return sub(val, oth.val);
  }
};

fenwick_tree<long long> ft_cnt;
fenwick_tree<mint> ft_sum;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] -= i;
  }

  for (int i = 1; i <= n; ++i) {
    cin >> w[i];
    ft_cnt.update(i, w[i]);
    ft_sum.update(i, mul(w[i], a[i]));
  }

  while (q--) {
    int x, y;
    cin >> x >> y;
    if (x < 0) {
      x = -x;
      ft_cnt.update(x, y - w[x]);
      ft_sum.update(x, mul(sub(y, w[x]), a[x]));
      w[x] = y;
    } else {
      long long target = (ft_cnt.query(x, y) + 1) / 2;

      int lo = x;
      int hi = y;
      while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (ft_cnt.query(x, mid) < target) {
          lo = mid + 1;
        } else {
          hi = mid - 1;
        }
      }

      cout << add(sub(mul(a[lo], ft_cnt.query(x, lo) % M), ft_sum.query(x, lo).val),
          sub(ft_sum.query(lo + 1, y).val, mul(a[lo], ft_cnt.query(lo + 1, y) % M))) << "\n";
    }
  }
}