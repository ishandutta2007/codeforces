#include <bits/stdc++.h>
using namespace std;

const int N = 1111111;

#define int long long

const int cxt = 1e6;

struct NODE {
  int x, y;
  void input(void) {
    scanf("%lld%lld", &x, &y);
  }

  friend NODE operator + (NODE a, NODE b) {
    return (NODE){a.x + b.x, a.y + b.y};
  }

  friend NODE operator - (NODE a, NODE b) {
    return (NODE){a.x - b.x, a.y - b.y};
  }

  int norm(void) {
    return x * x + y * y;
  }
}P[N];

int c[N], n, fa[N], cnt, id[N];
bool vis[N];

vector <int> G[N];

void dfs(int x) {
  if(fa[x] != 0) {
    c[x] = c[fa[x]] * c[x];
  }
  for(int i = 0; i < (int) G[x].size(); ++ i) {
    dfs(G[x][i]);
  }
}

main(void) {
  cin >> n;
  for(int i = 1; i <= n; ++ i) id[i] = i;
  for(int i = 1; i <= n; ++ i) P[i].input();
  cnt = n;
  for(int i = 1; i <= n - 2; ++ i) {
    bool ok = 0;

    vector <int> sda; sda.clear();
    for(int a = i; (!ok) && (a <= i + 2); ++ a) {
      if(ok) break;
      for(int b = a + 1; b <= i + 2; ++ b) {
	if((P[id[a]] - P[id[b]]).norm() <= cxt * cxt) {
	  ok = 1;
	  ++ cnt;
	  fa[id[a]] = cnt;
	  fa[id[b]] = cnt;
	  G[cnt].push_back(id[a]);
	  G[cnt].push_back(id[b]);
	  c[id[a]] = 1;
	  c[id[b]] = -1;
	  P[cnt] = (P[id[a]] - P[id[b]]);
	  sda.push_back(cnt);
	  for(int qqq = i; qqq <= i + 2; ++ qqq) if(qqq != a && qqq != b) sda.push_back(id[qqq]);
	  break;
	}
	if((P[id[a]] + P[id[b]]).norm() <= cxt * cxt) {
	  ok = 1;
	  ++ cnt;
	  fa[id[a]] = cnt;
	  fa[id[b]] = cnt;
	  G[cnt].push_back(id[a]);
	  G[cnt].push_back(id[b]);
	  c[id[a]] = 1;
	  c[id[b]] = 1;
	  P[cnt] = (P[id[a]] + P[id[b]]);
	  sda.push_back(cnt);
	  for(int qqq = i; qqq <= i + 2; ++ qqq) if(qqq != a && qqq != b) sda.push_back(id[qqq]);
	  break;
	}
      }
      if(ok) break;
    }
    if(!ok) throw;

    id[i + 1] = sda[0];
    id[i + 2] = sda[1];
  }
  if((P[id[n]] - P[id[n - 1]]).norm() < (P[id[n]] + P[id[n - 1]]).norm()) {
    c[id[n]] = 1; c[id[n - 1]] = -1;
  }
  else c[id[n]] = c[id[n - 1]] = 1;
  ++ cnt;
  fa[id[n]] = fa[id[n - 1]] = cnt;
  G[cnt].push_back(id[n]);
  G[cnt].push_back(id[n - 1]);
  c[cnt] = 1;
  dfs(cnt);
  //for(int i = 1; i <= cnt; ++ i) if(!vis[i]) dfs(i);
  for(int i = 1; i <= n; ++ i) printf("%lld ", c[i]);
  puts("");
}