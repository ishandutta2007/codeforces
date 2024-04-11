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

const int N = 200'000;
const int A = 26;

int index_final[N];
int ptr[A];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  cin >> n >> s;

  string t = s;
  reverse(t.begin(), t.end());

  for (int i = 0; i < n; ++i) {
    while (s[ptr[t[i] - 'a']] != t[i]) {
      ++ptr[t[i] - 'a'];
    }
    index_final[ptr[t[i] - 'a']++] = i;
  }

  long long ans = 0;
  fenwick<int> inversions(n);
  for (int i = 0; i < n; ++i) {
    ans += inversions.query(n) - inversions.query(index_final[i]);
    inversions.update(index_final[i] + 1, 1);
  }

  cout << ans << "\n";
}