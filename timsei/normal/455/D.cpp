#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int MAX = N * 2;

int n, m, A[N], opt, l, r,
  rt[N], id[MAX], ch[MAX][2], S[MAX], sz, fa[MAX], k;
bool vis[N];

#define lc (ch[x][0])
#define rc (ch[x][1])

void up(int x) {
  S[x] = S[lc] + S[rc] + 1;
}

pair <int, int> split(int x, int l) {
  if(!l) return make_pair(0, x);
  if(S[lc] + 1 == l) {
    int t = ch[x][1];
    ch[x][1] = 0;
    fa[t] = 0;
    up(x);
    return make_pair(x, t);
  }
  if(l <= S[lc]) {
    pair <int, int> Left = split(lc, l);
    fa[ch[x][0]] = 0;
    ch[x][0] = Left.second;
    if(lc) fa[ch[x][0]] = x;
    up(x);
    return make_pair(Left.first, x);
  }
  else {
    pair <int, int> Right = split(rc, l - S[lc] - 1);
    fa[ch[x][1]] = 0;
    ch[x][1] = Right.first;
    if(rc) fa[ch[x][1]] = x;
    up(x);
    return make_pair(x, Right.second);
  }
}

int merge(int x, int y) {
  if(!x || !y) return x + y;
  if(1LL * RAND_MAX * S[x] >= 1LL * (S[x] + S[y]) * rand()) {
    ch[x][1] = merge(ch[x][1], y);
    up(x);
    fa[ch[x][1]] = x;
    return x;
  }
  else {
    ch[y][0] = merge(x, ch[y][0]);
    up(y);
    fa[ch[y][0]] = y;
    return y;
  }
}

int getRk(int x, int y) {
  vector <int> Path;
  Path.clear();
  while(y != x) {
    Path.push_back(y);
    y = fa[y];
  }
  Path.push_back(x);
  reverse(Path.begin(), Path.end());
  int res = 0;
  for(int i = 0; i < (int) Path.size(); ++ i) {
    if(i != (Path.size()) - 1) {
      if(Path[i + 1] == ch[Path[i]][0]) {
      }
      else res += S[ch[Path[i]][0]] + 1;
    }
    else res += 1 + S[ch[Path[i]][0]];
  }
  return res;
}

int findkth(int x, int k) {
  if(S[lc] + 1 == k) return x;
  if(k <= S[lc]) return findkth(lc, k);
  else findkth(rc, k - S[lc] - 1);
}

void perform(int now, int l, int r) {
  int Rk = getRk(rt[A[now]], now + n);
  int it = rt[A[now]], who = 0, ans = 0;
  while(1) {
    if(!it) break;
    if(getRk(rt[0], it - n) < l) {
      it = ch[it][1];
    }
    else {
      ans = it;
      if(ch[it][0]) {
	it = ch[it][0];
      }
      else break;
    }
  }
  it = ans;
  if(!it) assert(0);
  who = getRk(rt[A[now]], it);
  if(it == now + n) return;
  else {
    pair <int, int> a = split(rt[A[now]], who - 1);
    pair <int, int> b = split(a.second, Rk - who + 1);
    pair <int, int> c = split(b.first, Rk - who);
    rt[A[now]] = merge(merge(merge(a.first, c.second), c.first), b.second);
  }
}

int get(int x, int y) {
  if(!y) return 0;
  int now = x;
  int ans = 0;
  while(1) {
    if(!x) break;
    if(getRk(rt[0], x - n) > y) x = ch[x][0];
    else {
      ans = x;
      if(ch[x][1]) {
	x = ch[x][1];
      }
      else break;
    }
  }
  x = ans;
  if(!x) return 0;
  else return getRk(now, x);
}

int query(int k, int l, int r) {
  int it = rt[k];
  return get(it, r) - get(it, l - 1);
}

int main() {
  scanf("%d", &n);
  for(int i = 1; i <= n; ++ i) {
    scanf("%d", &A[i]);
    S[i + n] = S[i] = 1;
    rt[A[i]] = merge(rt[A[i]], i + n);
    rt[0] = merge(rt[0], i);
  }
  cin >> m;
  int ans = 0;
  
  for(int i = 1; i <= m; ++ i) {
    scanf("%d%d%d", &opt, &l, &r);
    l = (l + ans - 1) % n + 1;
    r = (r + ans - 1) % n + 1;
    if(l > r) swap(l, r);
    if(opt == 1) {
      if(l == r) continue;
      int now = findkth(rt[0], r);
      perform(now, l, r);
      pair <int, int> a = split(rt[0], l - 1);
      pair <int, int> b = split(a.second, r - l + 1);
      pair <int, int> c = split(b.first, r - l);
      rt[0] = a.first;
      rt[0] = merge(rt[0], c.second);
      rt[0] = merge(rt[0], c.first);
      rt[0] = merge(rt[0], b.second);
    }
    else {
      if(l > r) swap(l, r);
      scanf("%d", &k);
      k = (k + ans - 1) % n + 1 ;
      printf("%d\n", ans = query(k, l, r));
    }
  }
}