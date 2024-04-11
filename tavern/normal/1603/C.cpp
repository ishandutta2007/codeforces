#include <bits/stdc++.h>

using namespace std;

const int B = 320;
const int maxn = 1e5 + 5;
const int INF = 998244353;

int n;
int a[maxn], f[2][B * 2];

inline int ID(int x, int y){ int ret = (y < B ? y : B + x / y); return ret; }

inline void solve(){
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    scanf("%d", a + i);
  memset(f, 0, sizeof(f));
  int p = 0, q = 1, ans = 0;
  for(int i = n - 1; i >= 0; --i){
    memset(f[p], 0, sizeof(f[p]));
    if(i == n - 1)
      f[p][ID(a[i], a[i])] = 1;
    else{
      int res = 0;
      for(int j = 1; j < B * 2; ++j){
	if(!f[q][j])
	  continue;
	int v = j < B ? j : a[i + 1] / (j - B);
	int k = (a[i] + (v - 1)) / v;
	int u = a[i] / k;
	//printf("i = %d v = %d u = %d\n", i, v, u);
	(f[p][ID(a[i], u)] += f[q][j]) %= INF;
	(res += 1ll * f[q][j] * (k - 1) % INF) %= INF;
	//printf("res = %d\n", res);
      }
      (++f[p][ID(a[i], a[i])]) %= INF;
      (ans += 1ll * res * (i + 1) % INF) %= INF;
    }
    swap(p, q);
  }
  printf("%d\n", ans);
  return;
}

int main(){
  //freopen("C.in", "r", stdin);
  int T;
  for(scanf("%d", &T); T--; solve());
  return 0;
}