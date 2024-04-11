#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int M = N * 2;
const int MAX = N * 30;

int n, m, x, y, u, v, c, t, U[N], V[N], C[N], T[N], ok = 0;

struct Edge {
  int to, t, id;
};

map < int, vector < Edge > > who[N];

struct Te {
  int id1, id2;
}E[MAX];

int tot;

int fir[MAX], ne[MAX * 2], to[MAX * 2], cnt, pnt, stk[MAX], top, scc_no[MAX], scc_tot, dfn[MAX], low[MAX], dlt, col[MAX];

#define Foreachson(i, x) for(int i = fir[x]; i; i = ne[i])

int One(int x) {
  return (x << 1) + 1;
}

int Zero(int x) {
  return (x << 1);
}

void add(int x, int y) {
  if(ok) {
    //cerr << x <<" " << y << endl;
  }
  ne[++ cnt] = fir[x];
  fir[x] = cnt;
  to[cnt] = y;
}

void link(int x, int y) {
  add(x, y);
  add((y ^ 1), (x ^ 1));
}

void dfs(int x) {
  //cerr << x << endl;
  dfn[x] = low[x] = ++ dlt;
  stk[++ top] = x;
  Foreachson(i, x) {
    int V = to[i];
    if(dfn[V] && !scc_no[V]) low[x] = min(low[x], dfn[V]);
    else if(!dfn[V]) dfs(V), low[x] = min(low[x], low[V]);
  }
  if(dfn[x] == low[x]) {
    ++ scc_tot;
    for(;;) {
      scc_no[stk[top]] = scc_tot;
      -- top;
      if(stk[top + 1] == x) return;
    }
  }
}

vector <int> Must[N];

bool pd(int x) {
  for(int i = 1; i <= One(pnt); ++ i) fir[i] = scc_no[i] = dfn[i] = low[i] = 0;
  for(int i = 1; i <= n; ++ i) Must[i].clear();
  for(int i = 1; i <= cnt; ++ i) ne[i] = to[i] = 0;
  dlt =  cnt = pnt = scc_tot = 0;
  pnt = n + m;
  for(int i = 1; i <= m; ++ i) {
    if(T[i] > x) {
      link(One(i + n), Zero(i + n));
      continue;
    }
    Must[U[i]].push_back(i);
    Must[V[i]].push_back(i);
  }
  for(int i = 1; i <= n; ++ i) {
    for(int j = 0; j < (int) Must[i].size(); ++ j) {
      ++ pnt;
      if(j != 0) link(One(pnt - 1), One(pnt));
      link(One(Must[i][j] + n), One(pnt));
      if(j != 0)link(One(Must[i][j] + n), Zero(pnt - 1));
    }
  }
  for(int i = 1; i <= tot; ++ i) {
    //if(ok) cerr << i <<" " << E[i].id1 << " 1" <<  endl;
    //if(ok) cerr << i <<" " << E[i].id2 <<" 2" << endl;
    link(Zero(E[i].id1 + n), One(E[i].id2 + n));
    link(Zero(E[i].id2 + n), One(E[i].id1 + n));
    //link(Zero(i + n + m), Zero(E[i].id2 + n));
  }
  for(int i = 2; i <= One(pnt); ++ i) {
    if(!dfn[i]) dfs(i);
  }
  //cerr << " asdasd" << endl;
  //for(int i = 1; i <= pnt / 2; ++ i)
  //cerr << scc_no[One(i)] << " " << scc_no[Zero(i)] << endl;
  for(int i = 1; i <= pnt; ++ i) {
    if(scc_no[Zero(i)] == scc_no[One(i)]) {
      return 0;
    }
  }
  return 1;
}

int main() {
  cin >> n >> m;  for(int i = 1; i <= m; ++ i) {
    scanf("%d%d%d%d", &u, &v, &c, &t);
    who[u][c].push_back((Edge){v, t, i});
    who[v][c].push_back((Edge){u, t, i});
    U[i] = u, V[i] = v, T[i] = t, C[i] = c;
  }
  for(int i = 1; i <= n; ++ i) {
    for(map < int, vector < Edge > > :: iterator it = who[i].begin(); it != who[i].end(); ++ it) {
      vector < Edge > now = it -> second;
      if(now.size() > 2) {
	puts("No");
	return 0;
      }
      if(now.size() <= 1) continue;
      //cerr << now[0].id <<" " << now[1].id << endl;
      E[++ tot] = (Te){now[0].id, now[1].id};
    }
  }
  int l = 0, r = 1e9 + 1, res = -1;
  while(l <= r) {
    int mid = (l + r) >> 1;
    if(pd(mid)) {
      r = mid - 1; res = mid;
    }
    else l = mid + 1;
  }
  if(res == -1) {
    puts("No");
    return 0;
  }
  puts("Yes");
  ok = 1;
  pd(res);
  vector <int> All; All.clear();
  for(int i = 1; i <= m; ++ i) {
    if(scc_no[One(i + n)] < scc_no[Zero(i + n)]) {
      All.push_back(i);
    }
  }
  //for(int i = 1; i <= m; ++ i)
  //cerr << scc_no[Zero(i + n)] << " " << scc_no[One(i + n)] << endl;
  cout << res << " " << All.size() << endl;
  for(int i = 0; i < (int) All.size(); ++ i) printf("%d ", All[i]);
  puts("");
}