#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

const int MaxN = 100000;
const int MaxV = 200000, MaxLog = 18;

int N, Q;
char S[MaxN + 5];

struct SegTree {
  int cnt;
  int rt[MaxV + 5], sum[MaxV * MaxLog + 5], lson[MaxV * MaxLog + 5], rson[MaxV * MaxLog + 5];

  void insertTree(int pos, int val, int &x, int l, int r) {
    if (x == 0) x = ++cnt;
    if (l == r) {
      sum[x] += val;
      return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) insertTree(pos, val, lson[x], l, mid);
    else insertTree(pos, val, rson[x], mid + 1, r);
    sum[x] = sum[lson[x]] + sum[rson[x]];
  }

  void mergeTree(int &x, int y, int l, int r) {
    if (x == 0 || y == 0) {
      x = x + y;
      return;
    }
    cnt++;
    lson[cnt] = lson[x], rson[cnt] = rson[x], sum[cnt] = sum[x];
    x = cnt;
    int mid = (l + r) >> 1;
    mergeTree(lson[x], lson[y], l, mid);
    mergeTree(rson[x], rson[y], mid + 1, r);
    sum[x] = sum[lson[x]] + sum[rson[x]];
  }

  int queryTree(int left, int right, int x, int l, int r) {
    if (x == 0) return 0;
    if (left == l && right == r) return sum[x];
    int mid = (l + r) >> 1;
    if (right <= mid) return queryTree(left, right, lson[x], l, mid);
    else if (left > mid) return queryTree(left, right, rson[x], mid + 1, r);
    else return queryTree(left, mid, lson[x], l, mid) + queryTree(mid + 1, right, rson[x], mid + 1, r);
  }
};
SegTree T;

namespace SAM {
  int cnt, last;
  int ch[MaxV + 5][26], len[MaxV + 5], link[MaxV + 5];
  bool np[MaxV + 5];
  std::vector<int> g[MaxV + 5];

  inline void init() {
    link[0] = -1;
  }

  inline void expand(int c) {
    int cur = ++cnt, p = last;
    last = cur;
    len[cur] = len[p] + 1;
    np[cur] = true;
    while (p != -1 && ch[p][c] == 0) {
      ch[p][c] = cur;
      p = link[p];
    }
    if (p == -1) return;
    int q = ch[p][c];
    if (len[p] + 1 == len[q]) {
      link[cur] = q;
      return;
    }
    int clone = ++cnt;
    len[clone] = len[p] + 1;
    link[clone] = link[q];
    for (int i = 0; i < 26; ++i) ch[clone][i] = ch[q][i];
    link[q] = link[cur] = clone;
    for (int u = p; u != -1 && ch[u][c] == q; u = link[u]) ch[u][c] = clone;
  }

  inline void suftree() {
    for (int i = 1; i <= cnt; ++i)
      g[link[i]].push_back(i);
  }

  void getRight(int u) {
    if (np[u] == true) {
      T.insertTree(len[u], 1, T.rt[u], 1, N);
      // fprintf(stderr, "have[%d][%d] = 1\n", u, len[u]);
    }
    for (int v : g[u]) {
      getRight(v);
      T.mergeTree(T.rt[u], T.rt[v], 1, N);
    }
  }
}

void init() {
  scanf("%s", S + 1);
  N = strlen(S + 1);
  scanf("%d", &Q);
}

inline bool exist(int u, int len, int l, int r) {
  // fprintf(stderr, "exist(%d, %d, %d, %d)\n", u, len, l, r);
  if (u == 0) return false;
  if (T.queryTree(l + len - 1, r, T.rt[u], 1, N) == 0) return false;
  else return true;
}

void solve() {
  SAM::init();
  for (int i = 1; i <= N; ++i)
    SAM::expand(S[i] - 'a');
  // for (int i = 0; i <= SAM::cnt; ++i) {
  //   fprintf(stderr, "i = %d\n", i);
  //   for (int c = 0; c < 26; ++c)
  //     fprintf(stderr, "%d%c", SAM::ch[i][c], " \n"[c == 25]);
  // }
  // for (int i = 0; i <= SAM::cnt; ++i)
  //   fprintf(stderr, "i = %d, link = %d, np = %d\n", i, SAM::link[i], SAM::np[i]);
  SAM::suftree();
  SAM::getRight(0);
  for (int q = 1; q <= Q; ++q) {
    int l, r;
    static char t[MaxN * 2 + 5];
    scanf("%d %d", &l, &r);
    scanf("%s", t + 1);
    // fprintf(stderr, "t = %s\n", t + 1);
    int m = strlen(t + 1);
    int lcp = -1;
    char replace = '\0';
    for (int i = 1, id = 0; i <= r - l + 1; ++i) {
      for (int c = (i <= m ? t[i] - 'a' + 1 : 0); c < 26; ++c)
        if (exist(SAM::ch[id][c], i, l, r) == true) {
          lcp = i - 1;
          replace = c + 'a';
          break;
        }
      if (i == m + 1) break;
      id = SAM::ch[id][t[i] - 'a'];
      if (exist(id, i, l, r) == false) break;
    }
    if (lcp == -1) puts("-1");
    else {
      for (int i = 1; i <= lcp; ++i) putchar(t[i]);
      putchar(replace);
      putchar('\n');
    }
  }
}

int main() {
  init();
  solve();
  return 0;
}