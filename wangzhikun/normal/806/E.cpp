//tourist's solution
#include <bits/stdc++.h>

using namespace std;

inline int signum(int x) {
  return (x < 0 ? -1 : (x > 0 ? 1 : 0));
}

const int inf = (int) 1e9;

const int N = 500010;

pair <int, int> a[N];
int pos[N];

pair <int, int> mn[4 * N];
int add[4 * N];

void push(int x) {
  add[x + x] += add[x];
  mn[x + x].first += add[x];
  add[x + x + 1] += add[x];
  mn[x + x + 1].first += add[x];
  add[x] = 0;
}

void pull(int x) {
  mn[x] = min(mn[x + x], mn[x + x + 1]);
}

void build(int x, int l, int r) {
  add[x] = 0;
  if (l == r) {
    mn[x] = make_pair(a[l].first, l);
    return;
  }
  int y = (l + r) >> 1;
  build(x + x, l, y);
  build(x + x + 1, y + 1, r);
  pull(x);
}

void modify(int x, int l, int r, int ll, int rr, int v) {
  if (ll <= l && r <= rr) {
    add[x] -= v;
    mn[x].first -= v;
    return;
  }
  push(x);
  int y = (l + r) >> 1;
  if (ll <= y) {
    modify(x + x, l, y, ll, rr, v);
  }
  if (rr > y) {
    modify(x + x + 1, y + 1, r, ll, rr, v);
  }
  pull(x);
}

pair <int, int> find_min(int x, int l, int r, int ll, int rr) {
  if (ll <= l && r <= rr) {
    return mn[x];
  }
  push(x);
  int y = (l + r) >> 1;
  pair <int, int> res = make_pair(inf, -1);
  if (ll <= y) {
    res = min(res, find_min(x + x, l, y, ll, rr));
  }
  if (rr > y) {
    res = min(res, find_min(x + x + 1, y + 1, r, ll, rr));
  }
  pull(x);
  return res;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i].first);
    a[i].second = i;
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    pos[a[i].second] = i;
  }
  build(1, 0, n - 1);
  set <int> minus, zero, plus;
  for (int id = 0; id < n; id++) {
    int i = pos[id];
    auto p = find_min(1, 0, n - 1, i, i);
    int vote = signum(p.first);
    if (vote == 0) {
      zero.insert(i);
    } else {
      if (vote == -1) {
        minus.insert(i);
        modify(1, 0, n - 1, i, n - 1, -1);
        int last_minus = *(--minus.end());
        if (a[last_minus].first == 1 - (int) minus.size()) {
          minus.erase(last_minus);
          modify(1, 0, n - 1, last_minus, n - 1, 1);
          zero.insert(last_minus);
        } else {
          if (!zero.empty()) {
            int first_zero = *(zero.begin());
            zero.erase(first_zero);
            plus.insert(first_zero);
            modify(1, 0, n - 1, first_zero, n - 1, 1);
          }
        }
      } else {
        plus.insert(i);
        modify(1, 0, n - 1, i, n - 1, 1);
        auto q = find_min(1, 0, n - 1, i, n - 1);
        if (q.first == -1) {
          int pos = q.second;
          plus.erase(pos);
          modify(1, 0, n - 1, pos, n - 1, -1);
          zero.insert(pos);
        }
      }
    }
    printf("%d\n", (int) plus.size() - (int) minus.size());
  }
  return 0;
}