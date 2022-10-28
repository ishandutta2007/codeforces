#include <bits/stdc++.h>
using namespace std;

struct segtree {

  segtree *right = nullptr;
  segtree *left = nullptr;

  array<int, 2> maxi;

  segtree(int l, int r) {
    if (l == r) {
      maxi = {0, -l};
    } else {
      int m = (l + r) / 2;
      left = new segtree(l, m);
      right = new segtree(m + 1, r);
      maxi = max(left->maxi, right->maxi);
    }
  }

  void update(int a, int x, int l, int r) {
    if (l == r) {
      maxi[0] += x;
    } else {
      int m = (l + r) / 2;
      if (a <= m) {
        left->update(a, x, l, m);
      } else {
        right->update(a, x, m + 1, r);
      }
      maxi = max(left->maxi, right->maxi);
    }
  }

  array<int, 2> query(int a, int b, int l, int r) {
    if (a <= l && r <= b) {
      return maxi;
    } else {
      int m = (l + r) / 2;
      if (a <= m && b > m) {
        return max(left->query(a, b, l, m), right->query(a, b, m + 1, r));
      } else if (a <= m) {
        return left->query(a, b, l, m);
      } else {
        return right->query(a, b, m + 1, r);
      }
    }
  }

};

const int A = 26;
const int B = 150;
const int N = 1000000;
const int L = __lg(N) + 1;

int lcp[L][N], suffix[N], where[N];
array<int, 2> key[N];

int query(int a, int b) {
  int l = __lg(b - a);
  return min(lcp[l][a], lcp[l][b - (1 << l)]);
}

int s[N], leaflet[N];

int matches[N], before[N];
array<int, 5> queries[N];
array<int, 2> ans[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n = 0;
  string t;
  cin >> t;

  for (auto i : t) {
    s[n++] = i - 'a';
  }

  int m;
  cin >> m;

  for (int i = 1; i <= m; ++i) {
    cin >> t;
    s[n++] = A + i;
    for (auto j : t) {
      leaflet[n] = i;
      s[n++] = j - 'a';
    }
  }

  iota(suffix, suffix + n, 0);
  for (int i = 0; i < n; ++i) {
    where[i] = s[i];
  }

  for (int i = 0; i <= __lg(n); ++i) {
    for (int j = 0; j < n; ++j) {
      key[j] = {where[j], (j + (1 << i) < n) ? where[j + (1 << i)] : -1};
    }

    sort(suffix, suffix + n, [&](int a, int b) {
      return key[a] < key[b];
    });

    for (int j = 0, k = 0; j < n; ++j) {
      if (j > 0 && key[suffix[j]] == key[suffix[j - 1]]) {
        where[suffix[j]] = k - 1;
      } else {
        where[suffix[j]] = k++;
      }
    }
  }

  for (int i = 0, h = 0; i < n; ++i) {
    if (where[i] == n - 1) {
      h = 0;
    } else {
      int j = suffix[where[i] + 1];
      for ( ; max(i, j) + h < n && s[i + h] == s[j + h]; ++h);
      lcp[0][where[i]] = h;
      h -= (h > 0);
    }
  }

  for (int i = 1; i <= __lg(n); ++i) {
    for (int j = 0; j + (1 << i) - 1 < n; ++j) {
      lcp[i][j] = min(lcp[i - 1][j], lcp[i - 1][j + (1 << (i - 1))]);
    }
  }

  int k = 0;
  for (int i = 0; i < n; ++i) {
    int x = leaflet[suffix[i]];
    before[i + 1] += before[i];
    if (x > 0) {
      matches[k++] = x;
      ++before[i + 1];
    }
  }

  int q;
  cin >> q;

  for (int i = 0; i < q; ++i) {
    int l, r, a, length;
    cin >> l >> r >> a >> length;
    length -= --a;
    a = where[a];

    int lo = 0, hi = a;
    while (lo < hi) {
      int mid = (lo + hi) / 2;
      if (query(mid, a) < length) {
        lo = mid + 1;
      } else {
        hi = mid;
      }
    }
    int x = before[lo];

    lo = a + 1, hi = n;
    while (lo < hi) {
      int mid = (lo + hi) / 2;
      if (query(a, mid) >= length) {
        lo = mid + 1;
      } else {
        hi = mid;
      }
    }
    int y = before[hi];

    queries[i] = {x, y, l, r, i};
  }

  sort(queries, queries + q, [&](array<int, 5> &a, array<int, 5> &b) {
    if (a[0] / B == b[0] / B) {
      if (a[0] / B % 2 == 0) {
        return a[1] < b[1];
      } else {
        return a[1] > b[1];
      }
    }
    return a[0] < b[0];
  });

  int a = 0, b = 0;
  segtree *maxi = new segtree(1, m);
  for (int i = 0; i < q; ++i) {
    auto [x, y, l, r, id] = queries[i];
    while (a < x) {
      maxi->update(matches[a++], -1, 1, m);
    }
    while (a > x) {
      maxi->update(matches[--a], 1, 1, m);
    }
    while (b < y) {
      maxi->update(matches[b++], 1, 1, m);
    }
    while (b > y) {
      maxi->update(matches[--b], -1, 1, m);
    }
    ans[id] = maxi->query(l, r, 1, m);
  }

  for (int i = 0; i < q; ++i) {
    cout << -ans[i][1] << " " << ans[i][0] << "\n";
  }
}