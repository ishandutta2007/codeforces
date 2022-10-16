#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 4e6 + 5;

int n, m;
ll f[maxn], g[maxn];

int main(){
  //freopen("B.in", "r", stdin);
  scanf("%d%d", &n, &m);
  g[1] = 1;
  for(int i = 1; i <= n; ++i){
    (f[i] += f[i - 1]) %= m;
    g[i] += f[i];
    (f[i + 1] += g[i]) %= m;
    for(int j = 2; j <= n / i; ++j){
      int l = j * i, r = j * i + j;
      (f[l] += g[i]) %= m;
      if(r <= n)
	(f[r] += m - g[i]) %= m;
    }
  }

  printf("%lld\n", g[n]);
  return 0;
}