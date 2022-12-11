#include <cstdio>

#ifdef Tweetuzki
#define debug(arg...) fprintf(stderr, arg)
#else
#define debug(arg...) void(0)
#endif

const int MaxN = 100000;

int N;
int A[MaxN + 5];

struct Splay {
#define lson ch[0]
#define rson ch[1]
#define rt lson[rtf]
  int cnt, rtf;
  int fa[MaxN + 5], ch[2][MaxN + 5], siz[MaxN + 5];
  long long val[MaxN + 5], add[MaxN + 5];

  Splay() {
    cnt = 0;
    rtf = MaxN + 4;
  }

  inline int getson(int x, int f) { return rson[f] == x; }
  inline void update(int x) { siz[x] = siz[lson[x]] + siz[rson[x]] + 1; }

  inline void pushdown(int x) {
    if (add[x] != 0) {
      if (lson[x] != 0) {
        val[lson[x]] += add[x];
        add[lson[x]] += add[x];
      }
      if (rson[x] != 0) {
        val[rson[x]] += add[x];
        add[rson[x]] += add[x];
      }
      add[x] = 0;
    }
  }

  inline void rotate(int x) {
    int f = fa[x], g = fa[f];
    int l = getson(x, f);
    fa[ch[l ^ 1][x]] = f; fa[f] = x; fa[x] = g;
    ch[l][f] = ch[l ^ 1][x]; ch[l ^ 1][x] = f;
    ch[getson(f, g)][g] = x;
    update(f);
  }

  inline void splay(int x, int tf) {
    while (fa[x] != tf) {
      int f = fa[x], g = fa[f];
      if (g != tf) {
        if (getson(x, f) == getson(f, g)) rotate(f);
        else rotate(x);
      }
      rotate(x);
    }
    update(x);
  }

  void insert(int k, long long v, int f, int s) {
    debug("insert(%d, %d, %d)\n", k, f, s);
    int &x = ch[s][f];
    if (x == 0) {
      x = ++cnt;
      siz[x] = 1;
      fa[x] = f;
      val[x] = v;
      add[x] = 0;
      splay(x, rtf);
      return;
    }
    pushdown(x);
    siz[x]++;
    if (k <= siz[lson[x]]) insert(k, v, x, 0);
    else {
      k -= siz[lson[x]] + 1;
      insert(k, v, x, 1);
    }
  }

  inline int binarySearch(int v) {
    int rk = 0, u = rt, res = 0, finalU = rt;
    while (u != 0) {
      pushdown(u);
      finalU = u;
      if (val[u] > 1LL * (rk + siz[lson[u]] + 1) * v) {
        res = rk + siz[lson[u]] + 1;
        rk += siz[lson[u]] + 1;
        u = rson[u];
      } else u = lson[u];
    }
    if (finalU != 0) splay(finalU, rtf);
    return res;
  }

  inline int queryKth(int k) {
    int u = rt;
    while (u != 0) {
      debug("u = %d, k = %d\n", u, k);
      pushdown(u);
      if (k <= siz[lson[u]]) u = lson[u];
      else if (k == siz[lson[u]] + 1) {
        splay(u, rtf);
        return u;
      } else {
        k -= siz[lson[u]] + 1;
        u = rson[u];
      }
    }
    return -1;
  }

  inline void updateRange(int pos, long long v) {
    if (pos == 1) {
      val[rt] += v;
      add[rt] += v;
    } else {
      int pre = queryKth(pos - 1);
      splay(pre, rtf);
      val[rson[pre]] += v;
      add[rson[pre]] += v;
    }
  }
};
Splay T;

void init() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
}

void solve() {
  for (int i = 1; i <= N; ++i) {
    int pos = T.binarySearch(A[i]);
    debug("pos = %d\n", pos);
    T.insert(pos, 1LL * pos * A[i], T.rtf, 0);
    T.updateRange(pos + 1, A[i]);
  }
  long long v = 0, s = 0;
  for (int i = 1; i <= N; ++i) {
    s += T.val[T.queryKth(i)];
    if (s > v) v = s;
  }
  printf("%lld\n", v);
}

int main() {
#ifdef Tweetuzki
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
//  freopen("errorfile.txt", "w", stderr);
#endif
  init();
  solve();
  return 0;
}