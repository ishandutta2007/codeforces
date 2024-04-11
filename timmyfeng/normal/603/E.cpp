#include <bits/stdc++.h>
using namespace std;

struct linkcut {

  linkcut *par, *left, *right;
  array<int, 2> value, path;
  int sub, vir, weight;
  bool flip;

  linkcut(array<int, 2> x, int y) {
    par = left = right = nullptr;
    path = value = x;
    weight = sub = y;
    flip = false;
    vir = 0;
  }

};

array<int, 2> path(linkcut *u) {
  return u ? u->path : array<int, 2>{0, 0};
}

int sub(linkcut *u) {
  return u ? u->sub : 0;
}

void pull(linkcut *u) {
  if (u) {
    u->path = max({path(u->left), u->value, path(u->right)});
    u->sub = sub(u->left) + u->vir + u->weight + sub(u->right);
  }
}

void push(linkcut *u) {
  if (u && u->flip) {
    u->flip = false;
    swap(u->left, u->right);
    if (u->left) {
      u->left->flip ^= true;
    }
    if (u->right) {
      u->right->flip ^= true;
    }
  }
}

bool root(linkcut *u) {
  return !u->par || (u->par->left != u && u->par->right != u);
}

bool left(linkcut *u) {
  return u->par->left == u;
}

void assign(linkcut *u, linkcut *v, bool d) {
  (d ? u->left : u->right) = v;
  if (v) {
    v->par = u;
  }
}

void rotate(linkcut *u) {
  linkcut *p = u->par, *g = p->par;
  bool d = left(u);
  assign(p, d ? u->right : u->left, d);
  if (root(p)) {
    u->par = g;
  } else {
    assign(g, u, left(p));
  }
  assign(u, p, !d);
}

void splay(linkcut *u) {
  while (!root(u)) {
    linkcut *p = u->par, *g = p->par;
    push(g), push(p), push(u);
    if (!root(p)) {
      if (left(u) == left(p)) {
        rotate(p);
      } else {
        rotate(u);
      }
    }
    rotate(u);
    pull(g), pull(p), pull(u);
  }
  push(u);
}

void access(linkcut *u) {
  linkcut *c = nullptr;
  for (linkcut *v = u; v; v = v->par) {
    splay(v);
    v->vir += sub(v->right);
    v->right = c;
    v->vir -= sub(v->right);
    pull(v);
    c = v;
  }
  splay(u);
}

void reroot(linkcut *u) {
  access(u);
  u->flip ^= true;
}

void link(linkcut *u, linkcut *v) {
  reroot(v), access(u);
  u->vir += sub(v);
  v->par = u;
  pull(u);
}

void cut(linkcut *u, linkcut *v) {
  reroot(v), access(u);
  u->left = nullptr;
  v->par = nullptr;
  pull(u);
}

const int N = 100000 + 1;
const int M = 300000;

linkcut *bovinia[N], *edges[M];
array<int, 2> points[M];
int n;

bool same(int u, int v) {
  access(bovinia[u]), access(bovinia[v]);
  return bovinia[u]->par;
}

void link(int a) {
  auto [u, v] = points[a];
  access(bovinia[u]), access(bovinia[v]);
  n -= sub(bovinia[u]) % 2;
  n -= sub(bovinia[v]) % 2;
  link(edges[a], bovinia[u]);
  link(edges[a], bovinia[v]);
  access(edges[a]);
  n += sub(edges[a]) % 2;
}

void cut(int a) {
  access(edges[a]);
  int s = sub(edges[a]);
  if (s == 0) {
    return;
  }
  n -= s % 2;

  auto [u, v] = points[a];
  cut(edges[a], bovinia[u]);
  cut(edges[a], bovinia[v]);
  access(bovinia[u]), access(bovinia[v]);
  n += sub(bovinia[u]) % 2;
  n += sub(bovinia[v]) % 2;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int m;
  cin >> n >> m;

  for (int i = 1; i <= n; ++i) {
    bovinia[i] = new linkcut({0, 0}, 1);
  }

  priority_queue<array<int, 2>> que;

  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;

    points[i] = {u, v};
    edges[i] = new linkcut({w, i}, 0);

    if (same(u, v)) {
      reroot(bovinia[u]), access(bovinia[v]);
      auto [a, j] = path(bovinia[v]);
      if (w < a) {
        cut(j);
      }
    }

    if (!same(u, v)) {
      que.push({w, i});
      link(i);
    }

    int ans = -1;
    while (n == 0) {
      auto [a, j] = que.top();
      ans = a;
      cut(j);
      if (n > 0) {
        link(j);
        break;
      }
      que.pop();
    }

    cout << ans << "\n";
  }
}