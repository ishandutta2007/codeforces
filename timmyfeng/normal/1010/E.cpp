#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

template <class T>
struct fenwick_tree_2d {

  vector<int> vals[N];
  vector<T> tree[N];

  int get(int x, int y) {
    return upper_bound(vals[x].begin(), vals[x].end(), y) - vals[x].begin();
  }

  void add(int x, int y) {
    for ( ; x < N; x += x & -x) {
      vals[x].push_back(y);
    }
  }

  void build() {
    for (int i = 1; i < N; ++i) {
      sort(vals[i].begin(), vals[i].end());
      vals[i].erase(unique(vals[i].begin(), vals[i].end()), vals[i].end());
      tree[i].resize(vals[i].size() + 1u);
    }
  }

  void update(int x, int y, T val) {
    for ( ; x < N; x += x & -x) {
      for (int i = get(x, y); i < int(tree[x].size()); i += i & -i) {
        tree[x][i] += val;
      }
    }
  }

  T query(int x, int y) {
    T res = 0;
    for ( ; x > 0; x -= x & -x) {
      for (int i = get(x, y); i > 0; i -= i & -i) {
        res += tree[x][i];
      }
    }
    return res;
  }

};

struct event {
  int x1, x2, y1, y2, z, type;
  bool operator<(event oth) const {
    return z < oth.z;
  }
};

struct range {
  int l = N - 5;
  int r = 1;
  void update(int a) {
    l = min(l, a);
    r = max(r, a);
  }
} dimension[3], rect[3];

fenwick_tree_2d<int> ft;
int ans[N];
int b[3];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int mx;
  for (int i = 0; i < 3; ++i) {
    cin >> mx;
  }

  int n, m, k;
  cin >> n >> m >> k;

  while (n--) {
    for (int i = 0; i < 3; ++i) {
      int a;
      cin >> a;
      dimension[i].update(a);
    }
  }

  vector<event> events;
  while (m--) {
    bool ok = false;
    for (int i = 0; i < 3; ++i) {
      int a;
      cin >> a;
      rect[i] = range();
      rect[i].update(a);
      if (a <= dimension[i].r) {
        rect[i].update(1);
      }
      if (a >= dimension[i].l) {
        rect[i].update(N - 5);
      }
      ok |= (a < dimension[i].l || a > dimension[i].r);
    }

    if (!ok) {
      cout << "INCORRECT\n";
      exit(0);
    }

    events.push_back({rect[0].l, rect[0].r + 1, rect[1].l, rect[1].r + 1, rect[2].l, 1});
    events.push_back({rect[0].l, rect[0].r + 1, rect[1].l, rect[1].r + 1, rect[2].r + 1, -1});
  }
  cout << "CORRECT\n";

  for (int i = 0; i < k; ++i) {
    for (int& j : b) {
      cin >> j;
    }

    bool ok = true;
    for (int j = 0; j < 3; ++j) {
      ok &= (b[j] >= dimension[j].l && b[j] <= dimension[j].r);
    }

    if (ok) {
      ans[i] = 1;
    } else {
      events.push_back({b[0], i, b[1], 0, b[2], 0});
    }
  }

  for (event e : events) {
    if (e.type != 0) {
      ft.add(e.x1, e.y1);
      ft.add(e.x1, e.y2);
      ft.add(e.x2, e.y1);
      ft.add(e.x2, e.y2);
    }
  }
  ft.build();

  stable_sort(events.begin(), events.end());
  for (event e : events) {
    if (e.type == 0) {
      ans[e.x2] = -(ft.query(e.x1, e.y1) > 0);
    } else {
      ft.update(e.x1, e.y1, e.type);
      ft.update(e.x1, e.y2, -e.type);
      ft.update(e.x2, e.y1, -e.type);
      ft.update(e.x2, e.y2, e.type);
    }
  }

  for (int i = 0; i < k; ++i) {
    if (ans[i] == 1) {
      cout << "OPEN\n";
    } else if (ans[i] == 0) {
      cout << "UNKNOWN\n";
    } else {
      cout << "CLOSED\n";
    }
  }
}