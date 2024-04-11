#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 5;
const int M = 1e3 + 5;
const int Segment_Size = N * 4;

int A[M][M], X[N], Y[N], n, m, x, y, r[N], L[Segment_Size], R[Segment_Size], Tag[Segment_Size];

#define lc (no << 1)
#define rc (no << 1 | 1)
#define getmid int mid = (L[no] + R[no]) >> 1

struct NODE {
  int Mn, Num;
}T[Segment_Size];

NODE operator + (NODE a, NODE b) {
  NODE now; now.Mn = min(a.Mn, b.Mn);
  now.Num = (a.Mn == now.Mn) * a.Num + (b.Mn == now.Mn) * b.Num;
  return now;
}

void pt(int no, int y) {
  Tag[no] += y;
  T[no].Mn += y;
}

void up(int no) {
  T[no] = T[lc] + T[rc];
}

void dn(int no) {
  if(L[no] == R[no]) return;
  if(Tag[no]) {
    pt(lc, Tag[no]);
    pt(rc, Tag[no]);
    up(no);
    Tag[no] = 0;
  }
}

void add(int no, int l, int r, int t) {
  dn(no);
  if(L[no] == l && R[no] == r) {
    pt(no, t);
    return;
  }
  getmid;
  if(l > mid) add(rc, l, r, t);
  else if(r <= mid) add(lc, l, r, t);
  else add(lc, l, mid, t), add(rc, mid + 1, r, t);
  up(no);
}

NODE Q(int no, int l, int r) {
  dn(no);
  if(L[no] == l && R[no] == r) {
    return T[no];
  }
  getmid;
  if(l > mid) return Q(rc, l, r);
  else if(r <= mid) return Q(lc, l, r);
  else return Q(lc, l, mid) + Q(rc, mid + 1, r);
}

void build(int no, int l, int r) {
  L[no] = l, R[no] = r;
  if(l == r) {
    T[no].Mn = 0, T[no].Num = 1;
    return;
  }
  getmid;
  build(lc, l, mid);
  build(rc, mid + 1, r);
  up(no);
}

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

struct Gai {
  int l, r, t;
};

vector < Gai > G[N];

namespace LCT {
  #undef lc
  #undef rc
  #define lc ch[x][0]
  #define rc ch[x][1]
  int ch[N][2], fa[N];
  bool rev[N];

  bool isroot(int x) {
    return (ch[fa[x]][0] != x) && (ch[fa[x]][1] != x);
  }
  
  void pt(int x) {
    rev[x] ^= 1;
    swap(lc, rc);
  }
  
  void pd(int x) {
    if(rev[x]) {
      pt(lc);
      pt(rc);
      rev[x] = 0;
    }
  }
  
  void ddd(int x) {
    if(!isroot(x)) ddd(fa[x]);
    pd(x);
  }

  bool dir(int x) {
    return ch[fa[x]][1] == x;
  }
  
  void rotate(int x) {
    int dx = dir(x), F = fa[x], df = dir(F), GF = fa[F];
    if(!isroot(F)) ch[GF][df] = x;
    fa[x] = GF; fa[F] = x; if(ch[x][!dx]) fa[ch[x][!dx]] = F;
    ch[F][dx] = ch[x][!dx];
    ch[x][!dx] = F;
  }
  
  void splay(int x) {
    ddd(x);
    if(isroot(x)) return;
    while(!isroot(x)) {
      if(isroot(fa[x])) return (void) rotate(x);
      if(dir(x) == dir(fa[x])) rotate(fa[x]), rotate(x);
      else rotate(x), rotate(x);
    }
  }

  void access(int x) {
    int t = 0;
    while(x) {
      splay(x);
      ch[x][1] = t;
      t = x;
      x = fa[x];
    }
  }

  int find(int x) {
    access(x); splay(x); pd(x);
    while(ch[x][0]) x = ch[x][0], pd(x);
    return x;
  }

  void makeroot(int x) {
    access(x); splay(x);
    pt(x);
  }

  void link(int x, int y){makeroot(x); fa[x] = y;}

  void cut(int x, int y){makeroot(x); access(y); splay(y); ch[y][0] = fa[x] = 0;}
}

void del(int x, int www) {
  int nx = X[x], ny = Y[x];
  for(int j = 0; j < 4; ++ j) {
    int tx = nx + dx[j], ty = ny + dy[j];
    if(!A[tx][ty]) continue;
    if(LCT :: find(A[tx][ty]) == LCT :: find(A[nx][ny]))
    LCT :: cut(A[tx][ty], A[nx][ny]);
  }
}

int main() {
  cin >> n >> m;
  build(1, 1, n * m);
  for(int i = 1; i <= n; ++ i) {
    for(int j = 1; j <= m; ++ j)
      scanf("%d", &A[i][j]),
	X[A[i][j]] = i, Y[A[i][j]] = j;
  }
  
  for(int i = 1; i <= n; ++ i) {
    for(int j = 1; j <= m; ++ j) {
      if(i < n) {
	int a = A[i][j], b = A[i + 1][j];
	if(a > b) swap(a, b);
	G[a].push_back((Gai){b, n * m, -1});
      }
      if(j < m){
	int a = A[i][j], b = A[i][j + 1];
	if(a > b) swap(a, b);
	G[a].push_back((Gai){b, n * m, -1});
      }
    }
  }

  long long ans = 0;

  r[n * m + 1] = n * m;
  
  for(int i = n * m; i >= 1; -- i) {
    r[i] = r[i + 1];
    add(1, i, n * m, 1);

    int nx = X[i], ny = Y[i];

    //LCT :: debug();
    //cerr << endl;
    
    for(int j = 0; j < 4; ++ j) {
      int tx = nx + dx[j], ty = ny + dy[j];
      if(A[tx][ty] < i || A[tx][ty] > r[i]) {
	continue;
      }
      //cerr << A[tx][ty] <<" " << A[nx][ny] << " " << LCT :: find(A[tx][ty]) <<" " << LCT :: find(A[nx][ny]) <<  endl;
      while(LCT :: find(A[tx][ty]) == LCT :: find(A[nx][ny])) {
	  del(r[i], i); -- r[i];
	  //cerr << r[i] <<" " << LCT :: find(A[tx][ty]) <<" " << LCT :: find(A[nx][ny]) << endl;
      }
      if(A[tx][ty] > r[i]) continue;
      LCT :: link(A[tx][ty], i);
      //cerr << A[tx][ty] <<" " << i << endl;
    }
    
    for(int j = 0; j < (int) G[i].size(); ++ j)
      add(1, G[i][j].l, G[i][j].r, G[i][j].t);
    NODE now = Q(1, i, r[i]);
    if(now.Mn == 1) ans += now.Num;
    else {
      while(!now.Mn) {
	del(r[i], i); -- r[i]; now = Q(1, i, r[i]);
      }
      ans += now.Num;
    }
  }
  cout << ans << endl;
}