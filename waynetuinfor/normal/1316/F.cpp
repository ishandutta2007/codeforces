#include <bits/stdc++.h>
using namespace std;

constexpr int kMod = 1'000'000'000 + 7;
vector<int> pw;

struct Node {
  static mt19937 rng;
  int val, sz, res, pref, suff;
  Node *lc, *rc;
  uint32_t pri;

  Node(int v) : 
    lc(nullptr), rc(nullptr), sz(1), pri(rng()), val(v), pref(v), suff(v), res(0) {}

  void Pull() {
    int lsz = lc ? lc->sz : 0;
    int rsz = rc ? rc->sz : 0;
    sz = 1;
    int64_t kres = 0;
    int64_t kpref = 1LL * val * pw[lsz];
    int64_t ksuff = 1LL * val * pw[rsz];
    if (lc) {
      sz += lc->sz;
      kres += 1LL * lc->res * pw[1 + rsz];
      kpref += lc->pref;
      ksuff += 1LL * lc->suff * pw[1 + rsz];
      kres += 1LL * val * pw[rsz] % kMod * lc->pref;
    }
    if (rc) {
      sz += rc->sz; 
      kres += 1LL * rc->res * pw[1 + lsz];
      kpref += 1LL * rc->pref * pw[1 + lsz];
      ksuff += rc->suff;
      kres += 1LL * val * pw[lsz] % kMod * rc->suff;
    }
    if (lc && rc) {
      kres += 1LL * lc->pref * rc->suff;
    }
    res = kres % kMod;
    pref = kpref % kMod;
    suff = ksuff % kMod;
  }
};

mt19937 Node::rng(7122);

Node *Merge(Node *a, Node *b) {
  if (!a || !b) return a ? a : b;
  if (a->pri > b->pri) {
    a->rc = Merge(a->rc, b);
    a->Pull();
    return a;
  } else {
    b->lc = Merge(a, b->lc);
    b->Pull();
    return b;
  }
}

void SplitByVal(Node *t, int v, Node *&a, Node *&b) {
  if (!t) {
    a = b = nullptr;
    return;
  }
  if (t->val <= v) {
    a = t;
    SplitByVal(t->rc, v, a->rc, b);
    a->Pull();
  } else {
    b = t;
    SplitByVal(t->lc, v, a, b->lc);
    b->Pull();
  }
}

void SplitBySize(Node *t, int v, Node *&a, Node *&b) {
  if (!t) {
    a = b = nullptr;
    return;
  }
  int k = 1 + (t->lc ? t->lc->sz : 0);
  if (k <= v) {
    a = t;
    SplitBySize(t->rc, v - k, a->rc, b);
    a->Pull();
  } else {
    b = t;
    SplitBySize(t->lc, v, a, b->lc);
    b->Pull();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) cin >> p[i];
  // for (int i = 0; i < n; ++i) p[i] = Node::rng() % 1000000000 + 1;
  pw.resize(n + 1, 1);
  for (int i = 1; i <= n; ++i) pw[i] = (pw[i - 1] + pw[i - 1]) % kMod;

  const auto GetInv = [&]() {
    constexpr int kV = (kMod + 1) / 2;
    int res = 1;
    for (int i = 0; i < n; ++i) res = 1LL * res * kV % kMod;
    return res;
  };

  const int kInv = GetInv();

  Node *nd = nullptr;
  for (int i = 0; i < n; ++i) {
    Node *ls, *rs;
    SplitByVal(nd, p[i], ls, rs);
    nd = Merge(Merge(ls, new Node(p[i])), rs);
  }
  cout << 1LL * nd->res * kInv % kMod << "\n";

  int q;
  cin >> q;
  while (q--) {
    int i, x;
    cin >> i >> x;
    // i = Node::rng() % n + 1;
    // x = Node::rng() % 1000000000 + 1;
    i--;
    Node *ls, *rs;
    SplitByVal(nd, p[i], ls, rs);
    Node *a, *b;
    SplitBySize(ls, ls->sz - 1, a, b);
    nd = Merge(a, rs);
    p[i] = x;
    *b = Node(p[i]);
    SplitByVal(nd, p[i], ls, rs);
    nd = Merge(Merge(ls, b), rs);
    cout << 1LL * nd->res * kInv % kMod << "\n";
  }
}