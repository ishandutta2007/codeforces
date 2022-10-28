#include <bits/stdc++.h>
using namespace std;

#include <bits/extc++.h>

template <class T, class Comp = less<T>>
using ordered_set = __gnu_pbds::tree<
  T, __gnu_pbds::null_type, Comp,
  __gnu_pbds::rb_tree_tag,
  __gnu_pbds::tree_order_statistics_node_update
>;

template <int M>
struct modint {

  int val = 0;

  modint() {}

  modint(int a) : val(a) {
    while (val < 0) {
      val += M;
    }
    while (val >= M) {
      val -= M;
    }
  }

  modint(long long a) : val(a % M) {
    if (val < 0) {
      val += M;
    }
  }

  modint operator+=(modint oth) {
    val += oth.val;
    if (val >= M) {
      val -= M;
    }
    return *this;
  }

  modint operator-=(modint oth) {
    val -= oth.val;
    if (val < 0) {
      val += M;
    }
    return *this;
  }

  modint operator*=(modint oth) {
    val = 1LL * val * oth.val % M;
    return *this;
  }

  void operator++() {
    ++val;
    if (val == M) {
      val = 0;
    }
  }

  void operator--() {
    --val;
    if (val == -1) {
      val = M - 1;
    }
  }

  modint operator-() {
    modint res;
    res.val = (val == 0) ? 0 : M - val;
    return res;
  }

  int mod() {
    return M;
  }

  modint pow(int e) {
    modint base = val;
    modint res = 1;
    while (e > 0) {
      if (e % 2 == 1) {
        res *= base;
      }
      base *= base;
      e /= 2;
    }
    return res;
  }

  modint inv() {
    return pow(M - 2);
  }

  friend modint operator+(modint a, modint b) {
    return modint(a) += b;
  }

  friend modint operator-(modint a, modint b) {
    return modint(a) -= b;
  }

  friend modint operator*(modint a, modint b) {
    return modint(a) *= b;
  }

  friend bool operator==(modint a, modint b) {
    return a.val == b.val;
  }

  friend bool operator!=(modint a, modint b) {
    return a.val != b.val;
  }

};

using mint = modint<1'000'000'007>;

struct node {

  node* right = nullptr;
  node* left = nullptr;

  mint matrix[4][4];

  node() {
    for (int i = 0; i < 4; ++i) {
      matrix[i][i] = 1;
    }
  }

  void apply(int to1, int to2, int to3) {
    matrix[1][0] = to1;
    matrix[2][1] = to2;
    matrix[3][2] = to3;
  }

  void pull() {
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        matrix[i][j] = 0;
      }
    }

    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        for (int k = 0; k < 4; ++k) {
          matrix[i][k] += right->matrix[i][j] * left->matrix[j][k];
        }
      }
    }
  }

  void push() {
    if (left == nullptr) {
      right = new node();
      left = new node();
    }
  }

};

struct segtree {

  node* root;
  int n;

  segtree() : root(nullptr) {}

  segtree(int n) : n(n) {
    root = new node();
    build(root, 0, n - 1);
  }

  void build(node* u, int l, int r) {
    if (l == r) {
      return;
    } else {
      u->push();
      int m = (l + r) / 2;
      build(u->left, l, m);
      build(u->right, m + 1, r);
      u->pull();
    }
  }

  void update(node* u, int l, int r, int a, int to1, int to2, int to3) {
    if (l == r) {
      u->apply(to1, to2, to3);
    } else {
      u->push();
      int m = (l + r) / 2;
      if (a <= m) {
        update(u->left, l, m, a, to1, to2, to3);
      } else {
        update(u->right, m + 1, r, a, to1, to2, to3);
      }
      u->pull();
    }
  }

  void update(int a, int to1, int to2, int to3) {
    update(root, 0, n - 1, a, to1, to2, to3);
  }

};

const int N = 100'000;

int count_l[N];
int count_r[N];
int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  map<int, vector<int>> indices;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    indices[a[i]].push_back(i);
  }

  for (int k = 0; k < 2; ++k) {
    ordered_set<array<int, 2>> prv;
    for (int i = 0; i < n; ++i) {
      count_l[i] = prv.order_of_key({a[i], i});
      prv.insert({a[i], i});
    }
    swap(count_l, count_r);
    reverse(a, a + n);
  }
  reverse(count_r, count_r + n);

  mint ans = 0;
  map<int, segtree> st;
  for (auto &[x, y] : indices) {
    st.emplace(x, y.size());
    for (int i = 0; i < (int) y.size(); ++i) {
      st[x].update(i, count_l[y[i]], 1, count_r[y[i]]);
    }
    ans += st[x].root->matrix[3][0];
  }

  int m;
  cin >> m;

  while (m--) {
    int t, x;
    cin >> t >> x;
    --x;

    int i = lower_bound(indices[a[x]].begin(), indices[a[x]].end(), x) - indices[a[x]].begin();

    ans -= st[a[x]].root->matrix[3][0];
    if (t == 1) {
      st[a[x]].update(i, 0, 0, 0);
    } else {
      st[a[x]].update(i, count_l[x], 1, count_r[x]);
    }
    ans += st[a[x]].root->matrix[3][0];

    cout << ans.val << "\n";
  }
}