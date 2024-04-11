/**
 *    author:  tourist
 *    created: 10.09.2017 15:04:48       
**/
#include <bits/stdc++.h>

using namespace std;

struct treap {
  long long x, y;
  long long add_x, add_y;
  int height;

  treap *left, *right;

  treap (long long x, long long y) : x(x), y(y) {
    height = rand ();
    add_x = add_y = 0;
    left = right = 0;
  }

  void push () {
    if (!add_x && !add_y) {
      return;
    }
    if (left) {
      left->x += add_x;
      left->add_x += add_x;
      left->y += add_y;
      left->add_y += add_y;
    }
    if (right) {
      right->x += add_x;
      right->add_x += add_x;
      right->y += add_y;
      right->add_y += add_y;
    }
    add_x = add_y = 0;
  }

  void recalc () {
  }
};

treap* merge ( treap *x, treap *y ) {
  if (!x)
    return y;
  if (!y)
    return x;
  if (x->height < y->height) {
    x->push ();
    x->right = merge (x->right, y);
    x->recalc ();
    return x;
  } else {
    y->push ();
    y->left = merge (x, y->left);
    y->recalc ();
    return y;
  }
}

treap* get_left(treap *x) {
  if (!x) {
    return x;
  }
  if (!x->left) {
    return x;
  }
  x->push();
  return get_left(x->left);
}

treap* get_right(treap *x) {
  if (!x) {
    return x;
  }
  if (!x->right) {
    return x;
  }
  x->push();
  return get_right(x->right);
}

void split(treap* t, treap* &l, treap* &r, const function<bool(treap*)> &is_right) {
  if (!t) {
    l = r = 0;
    return;
  }
  t->push();
  if (is_right(t)) {
    split(t->left, l, t->left, is_right);
    r = t;
  } else {
    split(t->right, t->right, r, is_right);
    l = t;
  }
}

const int N = 1234567;

pair <long long, int> e[N];

int main() {
  int n, m;
  long long C;
  scanf("%d %d %lld", &n, &m, &C);
  int cnt = 2 * (n + m);
  for (int i = 0; i < cnt; i++) {
    scanf("%lld", &e[i].first);
    e[i].second = (i < 2 * n ? 1 : 2);
  }
  sort(e, e + cnt);
  treap *r = new treap(0, 0);
  int mask = 0;
  long long big_add = 0;
  for (int i = 0; i < cnt - 1; i++) {
    mask ^= e[i].second;
    if (mask == 0) {
      continue;
    }
    long long t = e[i + 1].first - e[i].first;
    if (t == 0) {
      continue;
    }
    if (mask == 1) {
      r->x += t;
      r->add_x += t;
    }
    if (mask == 2) {
      r->y += t;
      r->add_y += t;
    }
    if (mask == 3) {
      big_add += t;
      treap *t1, *t2, *t3;
      split(r, t1, t2, [&C](treap* t) { return (t->x - t->y >= -C); });
      split(t2, t2, t3, [&C](treap* t) { return (t->x - t->y >= C + 1); });
      long long x3 = -C, y3 = 0;
      long long x4 = 0, y4 = -C;
      if (t1) {
        treap *tmp = get_right(t1);
        x3 = tmp->x;
        y3 = tmp->x + C;
      }
      if (t3) {
        treap *tmp = get_left(t3);
        x4 = tmp->y + C;
        y4 = tmp->y;
      }
      if (x3 > x4 || y3 > y4) {
        if (!t2) {
          t2 = new treap(x3, y3);
        } else {
          treap *tmp = get_left(t2);
          if (x3 > tmp->x || y3 > tmp->y) {
            t2 = merge(new treap(x3, y3), t2);
          }
        }
      }
      if (x4 > x3 || y4 > y3 || (x3 == x4 && y3 == y4)) {
        if (!t2) {
          t2 = new treap(x4, y4);
        } else {
          treap *tmp = get_right(t2);
          if (x4 > tmp->x || y4 > tmp->y) {
            t2 = merge(t2, new treap(x4, y4));
          }
        }
      }
      t2->x += t;
      t2->add_x += t;
      t2->y += t;
      t2->add_y += t;
      treap *t2l = get_left(t2);
      treap *t2r = get_right(t2);
      treap *t4;
      split(t1, t1, t4, [&t2l](treap* t) { return (t->y <= t2l->y); });
      split(t3, t4, t3, [&t2r](treap* t) { return (t->x > t2r->x); });
      r = merge(t1, merge(t2, t3));
    }
  }
  cout << (big_add + (get_right(r))->x) << endl;
  return 0;
}