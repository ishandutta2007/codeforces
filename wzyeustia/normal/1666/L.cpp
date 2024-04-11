#include <bits/stdc++.h>
#define rep(a, b, c) for(int a = (b); a <= (c); ++ a)
#define per(a, b, c) for(int a = (b); a >= (c); -- a)
using namespace std;
template <class T> void rd(T &x){
  x = 0; int f = 1; char ch = getchar();
  while(ch < '0' || ch > '9'){ if(ch == '-') f = -1; ch = getchar(); }
  while(ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  x *= f;
}

const int maxn = 2e5 + 5;
int n, m, s;
vector <int> to[maxn];
int fa[maxn], color[maxn];
bool flag;
vector <int> ans1, ans2;

void get_ans(int x, int y){
  ans1.push_back(y);
  while(x != s){
    ans1.push_back(x);
    x = fa[x];
  }
  ans1.push_back(s);
  while(y != s){
    ans2.push_back(y);
    y = fa[y];
  }
  ans2.push_back(s);
}

void dfs(int u, int t){
  if(flag) return ;
  color[u] = t;
  for(int i = 0; i < to[u].size(); ++ i){
    int v = to[u][i];
    if(v == s || flag) continue;
    if(color[v] == t) continue;
    if(color[v]){
      flag = true;
      get_ans(u, v);
      return ;
    }
    fa[v] = u;
    dfs(v, t);
  }
}

int main(){
  rd(n), rd(m), rd(s);
  rep(i, 1, m){
    int u, v; rd(u), rd(v);
    to[u].push_back(v);
  }
  if(to[s].size() < 2){
    puts("Impossible");
    return 0;
  }
  for(int t = 0; t < to[s].size(); ++ t){
    if(flag) break;
    if(color[to[s][t]]){
      flag = true;
      get_ans(s, to[s][t]);
      break;
    }
    fa[to[s][t]] = s;
    dfs(to[s][t], t + 1);
  }
  if(flag){
    puts("Possible");
    printf("%d\n", ans1.size());
    for(int i = ans1.size() - 1; i >= 0; -- i) printf("%d ", ans1[i]); puts("");
    printf("%d\n", ans2.size());
    for(int i = ans2.size() - 1; i >= 0; -- i) printf("%d ", ans2[i]); puts("");
  }
  else {
    puts("Impossible");
  }
  return 0;
}