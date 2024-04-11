#include <bits/stdc++.h>

using namespace std;

inline void solve(){
  int n, s;
  scanf("%d%d", &n, &s);
  printf("%d\n", s / ((n / 2) + 1));
  return;
}

int main(){
  //freopen("A.in", "r", stdin);
  int T;
  for(scanf("%d", &T); T--; solve());
  return 0;
}