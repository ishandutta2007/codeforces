#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;

int n, order[N], lzy[4 * N];
pair<int, int> a[N], st[4 * N];
set<int> pos, neg, zer;

void push(int node) {
  st[node * 2].first += lzy[node];
  st[node * 2 + 1].first += lzy[node];
  lzy[node * 2] += lzy[node];
  lzy[node * 2 + 1] += lzy[node];
  lzy[node] = 0;
}

void build(int node, int l, int r) {
  if (l == r) {
    st[node] = {a[l].first, l};
    return;
  }
  int mid = l + r >> 1;
  build(node * 2, l, mid);
  build(node * 2 + 1, mid + 1, r);
  st[node] = min(st[node * 2], st[node * 2 +  1]);
}

void modify(int node, int l, int r, int ll, int rr, int x) {
  if (l > r || l > rr || r < ll) return;
  if (ll <= l && r <= rr) {
    st[node].first += x;
    lzy[node] += x;
    return;
  }
  push(node);
  int mid = l + r >> 1;
  modify(node * 2, l, mid, ll, rr, x);
  modify(node * 2 + 1, mid + 1, r, ll, rr, x);
  st[node] = min(st[node * 2], st[node * 2 + 1]);
}

pair<int, int> get(int node, int l, int r, int ll, int rr) {
  if (l > r || l > rr || r < ll) return {1e9, 1e9};
  if (ll <= l && r <= rr) return st[node];
  push(node);
  int mid = l + r >> 1;
  pair<int, int> L = get(node * 2, l, mid, ll, rr);
  pair<int, int> R = get(node * 2 + 1, mid + 1, r, ll, rr);
  st[node] = min(st[node * 2], st[node * 2 + 1]);
  return min(L, R);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    order[a[i].second] = i;
  }
  build(1, 0, n - 1);
  for (int x = 0; x < n; x++) {
    int i = order[x];
    int bal = get(1, 0, n - 1, i, i).first;
    int my = (bal < 0 ? -1 : (bal == 0 ? 0 : +1));
    if (my == 0) {
      zer.insert(i);
    } else if (my > 0) {
      pos.insert(i);
      modify(1, 0, n - 1, i, n, -1);
      pair<int, int> t = get(1, 0, n - 1, i, n - 1);
      if (t.first < 0) {
        pos.erase(t.second);
        zer.insert(t.second);
        modify(1, 0, n - 1, t.second, n - 1, 1);
      }
    } else {
      neg.insert(i);
      modify(1, 0, n - 1, i, n - 1, 1);
      auto it = prev(neg.end());
      int q = *it;
      if (a[q].first + neg.size() == 1) {
        neg.erase(q);
        zer.insert(q);
        modify(1, 0, n - 1, q, n - 1, -1);
      } else if (!zer.empty()) {
        q = *zer.begin();
        zer.erase(q);
        pos.insert(q);
        modify(1, 0, n - 1, q, n - 1, -1);
      }
    }
    cout << (int) pos.size() - (int) neg.size() << '\n';
  }
  return 0;
}