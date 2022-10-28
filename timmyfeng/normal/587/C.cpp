#include <bits/stdc++.h>
using namespace std;

const int A = 10;

struct linkcut {

  linkcut *par, *left, *right;
  vector<int> value, path;
  int sub, vir;
  bool flip;

  linkcut(vector<int> x) {
    if ((int) x.size() > A) {
      x.resize(A);
    }

    par = left = right = nullptr;
    value = path = x;
    sub = 1, vir = 0;
    flip = false;
  }

};

int sub(linkcut *u) {
  return u ? u->sub : 0;
}

vector<int> path(linkcut *u) {
  return u ? u->path : vector<int>();
}

void pull(linkcut *u) {
  if (u) {
    u->sub = sub(u->left) + u->vir + 1 + sub(u->right);

    u->path.clear();
    vector<int> l = path(u->left), r = path(u->right), temp;
    merge(l.begin(), l.end(), r.begin(), r.end(), back_inserter(temp));
    merge(temp.begin(), temp.end(), u->value.begin(), u->value.end(), back_inserter(u->path));

    if ((int) u->path.size() > A) {
      u->path.resize(A);
    }
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

vector<int> people[N];
linkcut *andarz[N];
int edge[N][2];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, q;
  cin >> n >> m >> q;

  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < 2; ++j) {
      cin >> edge[i][j];
    }
  }

  for (int i = 1; i <= m; ++i) {
    int c;
    cin >> c;
    people[c].push_back(i);
  }

  for (int i = 1; i <= n; ++i) {
    andarz[i] = new linkcut(people[i]);
  }

  for (int i = 0; i < n - 1; ++i) {
    int u = edge[i][0], v = edge[i][1];
    link(andarz[u], andarz[v]);
  }

  while (q--) {
    int u, v, a;
    cin >> u >> v >> a;

    reroot(andarz[u]), access(andarz[v]);
    vector<int> ans = path(andarz[v]);

    if ((int) ans.size() > a) {
      ans.resize(a);
    }

    cout << ans.size() << " ";
    for (auto i : ans) {
      cout << i << " ";
    }
    cout << "\n";
  }
}