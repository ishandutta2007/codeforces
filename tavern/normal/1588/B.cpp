#include <bits/stdc++.h>

using namespace std;

int n;

inline long long query(int l, int r){
  if(l > r)
    return 0;
  long long ret = 0;
  printf("? %d %d\n", l, r);
  fflush(stdout);
  scanf("%lld", &ret);
  return ret;
}

inline void solve(){
  scanf("%d", &n);
  int lb = 1, rb = n + 1;
  for(; lb + 1 < rb; ){
    int md = lb + rb >> 1;
    if(!query(1, md))
      lb = md;
    else
      rb = md;
  }
  int i = lb, j = i + query(i, n) - query(i + 1, n) + 1;
  int k = j  + query(j + 1, n) - query(j + 2, n) + 1;
  printf("! %d %d %d\n", i, j, k);
  fflush(stdout);
  return;
}

int main(){
  int T;
  for(scanf("%d", &T); T--; solve());
  return 0;
}