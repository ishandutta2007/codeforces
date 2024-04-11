#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define fst first
#define snd second
#define sz(x) (int)((x).size())
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << (x) << endl;
#define ints(args...) int args; readln(args);
#define lls(args...) ll args; readln(args);

template<typename... Args>
void readln(Args&... args) { ((cin >> args), ...); }
template<typename... Args>
void writeln(Args... args) { ((cout << args << " "), ...); cout << '\n'; }

struct Node {
  int L, R;
  ll sum;
  int maxv, minv;
  Node *lc, *rc;
  int lazy;

  void spread() {
    if (lazy != 0) {
      if (L != R) {
        lc->lazy = lazy;
        rc->lazy = lazy;
      }
      sum = (ll)(R-L+1) * lazy;
      maxv = lazy;
      minv = lazy;
      lazy = 0;
    }
  }

  void calc() {
    sum = lc->sum + rc->sum;
    maxv = max(lc->maxv, rc->maxv);
    minv = min(lc->minv, rc->minv);
  }

  int lb(int s, int v) {
    spread();
    if (R < s) return -1;

    if (maxv <= v) return max(L, s);
    else if (minv > v) return -1;

    int v1 = lc->lb(s, v);
    if(v1 != -1) return v1;
    return rc->lb(s, v);
  }

  pii sump(int s, int v) {
    spread();
    if (R < s) return {-1, 0};

    if (s <= L && sum <= v) {
      return {R+1, sum};
    }

    if (L == R) {
      if (sum <= v) return {R+1, sum};
      else return {R, 0};
    }

    int M = (L+R)/2;
    if (s > M) {
      return rc->sump(s, v);
    }
    else {
      pii x = lc->sump(s, v);
      if (x.fst == M+1) {
        pii y = rc->sump(M+1, v-x.snd);
        return {y.fst, y.snd + x.snd};
      }
      else return x;
    }
  }

  void udt(int l, int r, int v) {
    spread();
    if(r < L || R < l) return;
    if (l <= L && R <= r) {
      lazy = v;
      spread();
      return;
    }

    lc->udt(l, r, v);
    rc->udt(l, r, v);
    calc();
  }

  int eval(int x) {
    spread();
    if(x < L || R < x) return 0;
    if (L == R) return sum;
    else return lc->eval(x) + rc->eval(x);
  }

  ll getsum(int l, int r) {
    spread();
    if (r < L || R < l) return 0;
    if (l <= L && R <= r) {
      return sum;
    }
    return lc->getsum(l, r) + rc->getsum(l, r);
  }
};

const int MN = 2e5 + 5;

int A[MN];

Node *init(int L, int R) {
  Node *n = new Node({L, R});
  if (L == R) {
    n->maxv = n->minv = n->sum = A[L];
    return n;
  }
  else {
    int M = (L+R)/2;
    n->lc = init(L, M);
    n->rc = init(M+1, R);
    n->calc();
    return n;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ints(N, Q);
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  auto rt = init(0, N-1);
  for(int q = 0; q < Q; q++) {
    ints(type, x, y); x--;
    if(type == 1) {
      int p = rt->lb(0, y);
      if (p > x) p = -1;
      if (p != -1) {
        rt->udt(p, x, y);
      }
    }
    else {
      int ans = 0;
      int cnt = 0;
      while(x < N && (cnt) < 3) {
        int p = rt->lb(x, y);
        if (p == -1) break;
        pii res = rt->sump(p, y);
        if (res.fst <= p) break;
        x = res.fst;
        y -= res.snd;
        ans += (res.fst - p);
      }
      writeln(ans);
    }
  }
  return 0;
}

// 5 3
// 20 12 12 1 1
// 2 1 22
// 2 2 22
// 2 3 22