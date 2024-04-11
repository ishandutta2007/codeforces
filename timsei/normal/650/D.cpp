#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 100;
const int M = N * 2;

int n, m, h[N], a;

struct Qu {
  int b, id;
}tp;

vector < Qu > G[N];

int tmp[N * 2], tot, ans[N], res[N], who[N];

#define lowbit(x) (x & (-x))

namespace BIT {

  int S[N * 2];
  
  void init() {
    memset(S, 0, sizeof(S));
  }
  
  void add(int x, int v) {
    ++ x;
    for(int i = x; i < N; i += lowbit(i))
      S[i] = max(S[i], v);
  }

  int Sum(int x) {
    ++ x;
    int res = 0;
    for(int i = x; i; i -= lowbit(i)) {
      res = max(res, S[i]);
    }
    return res;
  }
}

int getval(int x) {
  return lower_bound(tmp + 1, tmp + tot + 1, x) - tmp;
}

int can[N], must[N];
int vis[N];

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; ++ i)
    scanf("%d", &h[i]), tmp[++ tot] = h[i];
  for(int i = 1; i <= m; ++ i) {
    scanf("%d%d", &a, &tp.b);
    //tmp.b = getval(tmp.b);
    tmp[++ tot] = tp.b;
    tp.id = i;
    G[a].push_back(tp);
    who[i] = a;
  }
  sort(tmp + 1, tmp + tot + 1);
  for(int i = 1; i <= n; ++ i) h[i] = getval(h[i]);
  for(int i = 1; i <= n; ++ i) G[i].reserve(G[i].size());
  for(int i = 1; i <= n; ++ i) {
    for(int j = 0; j < (int) G[i].size(); ++ j)
      G[i][j].b = getval(G[i][j].b);
  }

  BIT :: init();

  int MAX = tot + 2;
  
  for(int i = 1; i <= n; ++ i) {
    for(int j = 0; j < (int) G[i].size(); ++ j) {
      ans[G[i][j].id] = BIT :: Sum(G[i][j].b - 1) + 1;
    }
    int now = BIT :: Sum(h[i] - 1) + 1;
    can[i] = now;
    BIT :: add(h[i], now);
  }

  int Ans = BIT :: Sum(MAX);
  
  BIT :: init();
  
  for(int i = n; i >= 1; -- i) {
    for(int j = 0; j < (int)G[i].size(); ++ j) {
      //cerr << G[i][j].b <<" " << ans[G[i][j].id] << endl;
      //cerr << MAX - G[i][j].b - 1 << endl;
      ans[G[i][j].id] += BIT :: Sum(MAX - G[i][j].b - 1);
    }
    int now = BIT :: Sum(MAX - h[i] - 1);
    if(now + can[i] != Ans) can[i] = -1;
    else ++ vis[can[i]];
    //cerr << i <<" " << h[i] << " " << MAX - h[i] <<" " << now + 1 << endl;
    BIT :: add(MAX - h[i], now + 1);
  }

  for(int i = 1; i <= n; ++ i) {
    if(can[i] == -1) continue;
    if(vis[can[i]] == 1) must[i] = 1;
  }  
  
  for(int i = 1; i <= m; ++ i) {
    printf("%d\n", max(Ans - must[who[i]], ans[i]));
  }
}