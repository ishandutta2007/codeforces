#include <bits/stdc++.h>

using namespace std;

template <typename T>
class fenwick {
  public:
  vector<T> fenw;
  int n;
  fenwick(int _n) : n(_n) {
    fenw.resize(n);
  }
  void modify(int x, T v) {
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  }
  T get(int x) {
    T v{};
    while (x >= 0) {
      v += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};

struct segtree {
  vector<int> st;
  segtree(int _n) { 
    st.resize(4 * _n);
    fill(st.begin(), st.end(), 1e9);
  }
  void modify(int node, int l, int r, int ll, int x) {
    if (l == r) {
      st[node] = min(st[node], x);
      return;
    }
    int mid = l + r >> 1;
    if (ll <= mid) {
      modify(node * 2, l, mid, ll, x);
    } else {
      modify(node * 2 + 1, mid + 1, r, ll, x);
    }
    st[node] = min(st[node * 2], st[node * 2 + 1]);
  }
  int get(int node, int l, int r, int ll, int rr) {
    if (l > r || l > rr || r < ll) {
      return 1e9;
    }
    if (ll <= l && r <= rr) {
      return st[node];
    }
    int mid = l + r >> 1;
    return min(get(node * 2, l, mid, ll, rr), get(node * 2 + 1, mid + 1, r, ll, rr));
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n, q;
  cin >> n >> q;
  set<int> ids;
  for (int i = 0; i < n; i++) {
    ids.insert(i);
  }
  fenwick<int> fenw(n);
  segtree st(n);
  while (q--) {
    int op;
    cin >> op;
    if (op == 0) {
      int l, r, x;
      cin >> l >> r >> x;
      --l; --r;
      if (x == 0) {  
        auto it = ids.lower_bound(l);
        while (it != ids.end() && *it <= r) {
          fenw.modify(*it, 1);
          it = ids.erase(it);
        }
      } else {
        st.modify(1, 0, n - 1, l, r);      
      }
    } else {
      int j;
      cin >> j;
      --j;
      if (fenw.get(j) != fenw.get(j - 1)) {
        cout << "NO" << '\n';
        continue;
      }                           
      int L = j, R = j;
      {
        int low = 0, high = j - 1;
        while (low <= high) {
          int mid = low + high >> 1;
          if (fenw.get(j - 1) - fenw.get(mid - 1) == j - mid) {
            L = mid;
            high = mid - 1;
          } else {
            low = mid + 1;
          }
        }
      }
      {
        int low = j + 1, high = n - 1;
        while (low <= high) {
          int mid = low + high >> 1;
          if (fenw.get(mid) - fenw.get(j) == mid - j) {
            R = mid;
            low = mid + 1;
          } else {
            high = mid - 1; 
          }
        }
      }
      cout << (st.get(1, 0, n - 1, L, j) <= R ? "YES" : "N/A") << '\n';
    }
  }                                                                     
  return 0;
}