#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

int n;
int a[maxn];

inline void solve(){
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    scanf("%d", a + i);
  int g = 0;
  for(int j = 0; j < 30; ++j){
    int cnt = 0;
    for(int i = 0; i < n; ++i)
      cnt += (a[i] >> j & 1);
    g = __gcd(g, cnt);
  }
  for(int i = 1; i <= n; ++i)
    if(g % i == 0)
      printf("%d ", i); puts("");
  return;
}

int main(){
  //freopen("A.in", "r", stdin);
  int T;
  for(scanf("%d", &T); T--; solve());
  return 0;
}