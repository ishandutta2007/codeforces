#include <bits/stdc++.h>

using namespace std;

inline void solve(){
  int x, y; scanf("%d%d", &x, &y);
  if(x <= y){
    int k = (y - y / 2) / (x / 2);
    printf("%lld\n", (y + 1ll * k * x) / 2);
  }
  else
    printf("%d\n", x + y);
  return;
}

int main(){
  //freopen("B.in", "r", stdin);
  int T;
  for(scanf("%d", &T); T--; solve());
  return 0;
}