//author: extraterrestrial_
#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,avx,tune=native")
using namespace std;
#define int ll
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define _ inline
#define pb push_back
#define F first
#define S second
#define MP make_pair
#define SZ(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pw(x) (1ll << (x))
#ifdef extraterrestrial_
  #define debug(x) cerr << #x << ": " << x << '\n';
#else
  #define debug(x)
#endif
const int INF = 1e9 + 10;
const ll BINF = 1e18 + 10;

mt19937 Random(int(time(0)));

struct Treap {
  struct vertex {
    int L, R, x, y, c, cnt, sum;
  };
  vector<vertex> t;
  Treap() {
    t.resize(6e5 + 10);
  }
  void out(int ind) {
    if (!ind) {
      return;
    }
    out(t[ind].L);
    cout << t[ind].x << ' ';
    out(t[ind].R);
  }
  int cnt = 0, root = 0;
  void upd(int ind) {
    if (ind) {
      t[ind].cnt = t[ind].c + t[t[ind].L].cnt + t[t[ind].R].cnt;
      t[ind].sum = t[t[ind].L].sum + t[t[ind].R].sum + t[ind].c * t[ind].x;
    }
  }
  pii split(int ind, int x) {
    if (!ind) {
      return {0, 0};
    }
    if (t[ind].x <= x) {
      pii sp = split(t[ind].R, x);
      t[ind].R = sp.F;
      upd(ind);
      upd(sp.S);
      return {ind, sp.S};
    }
    else {
      pii sp = split(t[ind].L, x);
      t[ind].L = sp.S;
      upd(ind);
      upd(sp.F);
      return {sp.F, ind};
    }
  }
  int merge(int ind1, int ind2) {
    if (!ind1) {
      return ind2;
    }
    if (!ind2) {
      return ind1;
    }
    if (t[ind1].y > t[ind2].y) {
      t[ind1].R = merge(t[ind1].R, ind2);
      upd(ind1);
      return ind1;
    }
    else {
      t[ind2].L = merge(ind1, t[ind2].L);
      upd(ind2);
      return ind2;
    }
  }
  bool find(int ind, int x) {
    if (!ind) {
      return false;
    }
    if (t[ind].x == x) {
      return true;
    }
    return t[ind].x > x ? find(t[ind].L, x) : find(t[ind].R, x);
  }
  void add1(int ind, int x, int delta) {
    if (t[ind].x == x) {
      t[ind].c += delta;
      upd(ind);
    }
    else {
      if (t[ind].x > x) {
        add1(t[ind].L, x, delta);
      }
      else {
        add1(t[ind].R, x, delta);
      }
      upd(ind);
    }
  }
  int init(int x, int c) {
    cnt++;
    t[cnt].L = t[cnt].R = 0;
    t[cnt].x = x;
    t[cnt].c = t[cnt].cnt = c;
    t[cnt].y = Random();
    t[cnt].sum = x * c;
    return cnt;
  }
  void add2(int x, int c) {
    int nw = init(x, c);
    pii lol = split(root, x);
    lol.F = merge(lol.F, nw);
    upd(lol.F);
    root = merge(lol.F, lol.S);
    upd(root);
  } 
  int get(int ind, int need) {
    if (!ind || !need) {
      return 0;
    }
    //cout << t[ind].x << ' ' << t[ind].c << ' ' << need << '\n';
    if (t[t[ind].L].cnt >= need) {
      return get(t[ind].L, need);
    }
    if (t[t[ind].L].cnt + t[ind].c >= need) {
      return t[t[ind].L].sum + t[ind].x * (need - t[t[ind].L].cnt);
    }
    return t[t[ind].L].sum + t[ind].c * t[ind].x + get(t[ind].R, need - t[t[ind].L].cnt - t[ind].c);
  }
};

void source() {
  int n, k, m;
  cin >> n >> k >> m;
  vector<vector<pii>> update(n + 2);
  for (int i = 1; i <= m; i++) {
    int from, to, cc, xx;
    cin >> from >> to >> cc >> xx;
    update[from].pb({cc, xx});
    update[to + 1].pb({-cc, xx});
  }
  Treap tree;
  int ans = 0, lastq = 0;
  for (int i = 1; i <= n; i++) {
    if (update[i].empty()) {
      ans += lastq;
      //debug(lastq);
      continue;
    }
    for (auto it : update[i]) {
      if (tree.find(tree.root, it.S)) {
        tree.add1(tree.root, it.S, it.F);
      }
      else {
        tree.add2(it.S, it.F);
      }
    }
    lastq = tree.get(tree.root, k);
    //debug(lastq);
    ans += lastq;
    //tree.out(tree.root);
    //cout << '\n';
  }
  cout << ans;
}
 
signed main() {
#ifdef extraterrestrial_
  assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#else
#define TASK ""
  //assert(freopen(TASK".in", "r", stdin));
  //assert(freopen(TASK".out", "w", stdout));
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  source();
#ifdef extraterrestrial_
  cerr << "\n\nTIME :: " << clock() * 1.0 / CLOCKS_PER_SEC;
#endif
  return 0;
}