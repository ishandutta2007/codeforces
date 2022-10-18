#include <bits/stdc++.h>
using namespace std;

template <class T> class ConvexHullTrick { // Min version
private:
  struct Line {
    T a, b;
    Line(T a = 0, T b = 0) : a(a), b(b) {}
    T get(T x) { return a * x + b; }
  };
  struct Node {
    Line l;
    Node *lhs, *rhs;
    Node(Line l) : l(l), lhs(nullptr), rhs(nullptr) {}
  };
  const T MIN, MAX, INF;
  Node *root;
  Node *insert(Node *p, T left, T right, Line &l) {
    if (!p)
      return new Node(l);
    if (p->l.get(left) <= l.get(left) && p->l.get(right) <= l.get(right))
      return p;
    if (p->l.get(left) >= l.get(left) && p->l.get(right) >= l.get(right)) {
      p->l = l;
      return p;
    }

    T mid = (left + right) / 2;
    if (p->l.get(mid) > l.get(mid))
      swap(p->l, l);

    if (p->l.get(left) >= l.get(left))
      p->lhs = insert(p->lhs, left, mid, l);
    else
      p->rhs = insert(p->rhs, mid + 1, right, l);
    return p;
  }
  T query(Node *p, T left, T right, T x) {
    if (!p)
      return INF;
    if (left == right)
      return p->l.get(x);
    T mid = (left + right) / 2;
    if (x <= mid)
      return min(p->l.get(x), query(p->lhs, left, mid, x));
    else
      return min(p->l.get(x), query(p->rhs, mid + 1, right, x));
  }

public:
  ConvexHullTrick(T MIN, T MAX, T INF) : MIN(MIN), MAX(MAX), INF(INF), root(nullptr) {}
  void insert(T a, T b) {
    Line l(a, b);
    root = insert(root, MIN, MAX, l);
  }
  T query(T x) { return query(root, MIN, MAX, x); }
};

// 319C - Kalila and Dimna in the Logging Industry
const int MAXN = 100005;
int n, a[MAXN], b[MAXN];
long long dp[MAXN];

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    for(int i = 0; i < n; ++i)
        scanf("%d", &b[i]);

    ConvexHullTrick<long long> hull(0, 1e9, 1e18);
    hull.insert(b[0], 0);
    for(int i = 1; i < n; ++i) {
        dp[i] = hull.query(a[i]);
        hull.insert(b[i], dp[i]);
    }

    printf("%lld\n", dp[n-1]);

    return 0;
}