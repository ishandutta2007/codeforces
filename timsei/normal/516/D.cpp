#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 5;
const int M = N * 2;
const int Tay = 22;

#define lowbit(x) (x & (-x))

namespace BIT {
  int S[N];
  void add(int x, int v) {
    ++ x;
    for(int i = x; i < N; i += lowbit(i)) {
      S[i] += v;
    }
  }
  
  int sum(int x) {
    ++ x;
    int res = 0;
    for(int i = x; i; i -= lowbit(i))
      res += S[i];
    return res;
  }

  int query(int l, int r) {
    if(!l) return sum(r);
    return sum(r) - sum(l - 1);
  }
  
  void init(void) {
    memset(S, 0, sizeof(S));
  }
}

#define Foreachson(i, x) for(int i = fir[x]; i; i = ne[i])

int n , m , q;

namespace Graph_builder {
  int dp[N], du[N], fir[N], ne[M], to[M], C[M], cnt, x, y, z, L[N], R[N], dfs_clock, dp2[N];
  int st[N][Tay], rt, id[N];

  map <int , int> Map, D;
  
  inline void add(int x , int y , int z) {
    ne[++ cnt] = fir[x];
    fir[x] = cnt;
    to[cnt] = y;
    C[cnt] = z;
    ++ du[y];
  }

  inline void link(int x, int y, int z) {
    add(x, y, z);
    add(y, x, z);
  }

  void dfs(int x, int f) {
    dp[x] = dp2[x]= -1e9;
    if(du[x] == 1) dp[x] = 0;
    Foreachson(i, x) {
      int V = to[i];
      if(V == f) continue;
      dfs(V, x);
      if(C[i] + dp[V] > dp[x]) dp2[x] = dp[x], dp[x] = C[i] + dp[V];
      else if(C[i] + dp[V] > dp2[x]) dp2[x] = C[i] + dp[V];
      //if(dp2[V] + C[i] > dp2[x]) dp2[x] = C[i] + dp2[V];
    }
  }

  void dfs2(int x, int f, int Dfa) {
    if(Dfa > dp[x]) dp2[x] = dp[x], dp[x] = Dfa;
    else if(Dfa > dp2[x]) dp2[x] = Dfa;
    Foreachson(i, x) {
      int V = to[i];
      if(V == f) continue;
      if(dp[V] + C[i] == dp[x])
        dfs2(V, x, dp2[x] + C[i]);
      else dfs2(V, x, dp[x] + C[i]);
    }
  }

  void dfs3(int x, int f) {
    st[x][0] = f;
    for(int i = 1; i < Tay; ++ i) st[x][i] = st[st[x][i - 1]][i - 1];
    L[x] = ++ dfs_clock;
    id[L[x]] = x;
    Foreachson(i, x) {
      int V = to[i];
      if(V == f)
        continue;
      dfs3(V, x);
    }
    R[x] = dfs_clock;
  }

  void init(void) {
    cin.sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i < n; ++ i) {
      cin >> x >> y >> z;
      //x = i + 1;y = rand() % i + 1; z = rand() % ((int)1e9);
      link(x, y, z);
    }
    dfs(1, 0);
    dp[0] = -1e18;
    dfs2(1, 0, -1e9);
    rt = 0;
    int Min = 1e18;
    for(int i = 1; i <= n; ++ i)
      Min = min(Min, dp[i]);
    for(int i = 1; i <= n; ++ i) ++ Map[dp[i]];
    int tot = 0;
    for(map <int , int> ::iterator it = Map.begin(); it != Map.end(); ++ it)
      D[it -> first] = ++ tot;
    for(int i = 1; i <= n; ++ i) dp2[i] = D[dp[i]];
    for(int i = 1; i <= n; ++ i)
      if(Min == dp[i]) rt = i;
    dfs3(rt, 0);
  }
}

using namespace Graph_builder;

namespace solver {
  int ans[N], l;

  struct Query {
    int id, val, l, r;
  };

  vector <Query> Q[N];

  void init(void) {
    for(int i = 0; i <= n; ++ i)
      Q[i].clear(), ans[i] = 0;
  }
  void solve(void) {
    cin >> l;
    init();
    for(int i = 1; i <= n; ++ i) {
      int now = i;
      for(int j = Tay - 1; j >= 0; -- j)
        if(dp[i] - dp[st[now][j]] <= l) now = st[now][j];
      Q[L[now] - 1].push_back((Query){i, -1, dp2[now], dp2[i]});
      Q[R[now]].push_back((Query){i, +1, dp2[now], dp2[i]});
    }
    BIT::init();
    for(int i = 1; i <= n; ++ i) {
      BIT::add(dp2[id[i]], 1);
      for(int j = 0; j < (int)Q[i].size(); ++ j) {
        ans[Q[i][j].id] += Q[i][j].val * BIT::query(Q[i][j].l, Q[i][j].r);
      }
    }
    int res = 0;
    for(int i = 1; i <= n; ++ i) res = max(res, ans[i]);
    cout << res << endl;
  }
}

main() {
  Graph_builder::init();
  //return 0;
  for(cin >> q; q --; ) {
    solver::solve();
  }
}