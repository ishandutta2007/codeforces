#include <bits/stdc++.h>
using namespace std;
int t,n,i,x,y,best,w,cw,rt,a[200200];
vector<int> g[200200];
bool all;
void dfs(int i, int p, int cur, int dst) {
  if (dst>best) {
    best=dst; cw=cur; w=i;
  }
  for (int j: g[i]) if (j!=p) {
    dfs(j,i,((a[j]==0)?cur:a[j]),(dst+int(a[j]!=0 && a[j]!=cur)));
  }
}
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    all=true;
    for (i=1; i<=n; i++) {
      scanf("%d",&a[i]);
      if (a[i]!=0) { all=false; rt=i; }
      g[i].clear();
    }
    for (i=1; i<n; i++) {
      scanf("%d%d",&x,&y);
      g[x].push_back(y);
      g[y].push_back(x);
    }
    if (all) {
      puts("1");
      continue;
    }
    best=0; w=rt; cw=a[rt];
    dfs(rt,0,a[rt],0);
    best=0;
    dfs(w,0,cw,0);
    printf("%d\n",(best+3)/2);
  }
  return 0;
}