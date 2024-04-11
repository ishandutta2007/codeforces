#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

int n;
int f[maxn], pre[2][maxn];
char s[2][maxn];

inline void solve(){
  scanf("%d", &n);
  for(int it = 0; it < 2; ++it)
    scanf("%s", s[it] + 1);

  for(int i = 0; i <= n; ++i)
    f[i] = -0x3f3f3f3f;
  f[0] = 0, pre[0][0] = pre[1][0] = -1;
  for(int i = 1; i <= n; ++i){
    for(int it = 0; it < 2; ++it){
      pre[it][i] = pre[it][i - 1];
      if(s[0][i] - '0' == it || s[1][i] - '0' == it)
	pre[it][i] = i;
    }
    if(pre[0][i] == pre[1][i])
      f[i] = f[i - 1] + 2;
    else if(pre[0][i] < pre[1][i])
      f[i] = max(f[i - 1] + 0, ~pre[0][i] ? f[pre[0][i] - 1] + 2 : 0);
    else
      f[i] = max(f[i - 1] + 1, ~pre[1][i] ? f[pre[1][i] - 1] + 2 : 0);
  }

  printf("%d\n", f[n]);
  return;
}

int main(){
  //freopen("C.in", "r", stdin);
  int T;
  for(scanf("%d", &T); T--; solve());
  return 0;
}