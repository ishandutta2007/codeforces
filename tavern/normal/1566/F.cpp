#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define PB push_back
typedef long long ll;

const int maxn = 2e5 + 5;
const int maxv = maxn * 2;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int n, m;
int a[maxn], l[maxn], r[maxn], ord[maxn], vis[maxn];
vector<ll> f[maxn], g[maxn], h[maxn];
vector<int> all[maxn];

inline bool cmp(const int &i, const int &j){ return MP(l[i], -r[i]) < MP(l[j], -r[j]); }

inline int find(vector<int> &vec, int k){
  int lb = -1, rb = vec.size();
  for(; lb + 1 < rb; ){
    int md = lb + rb >> 1;
    if(r[vec[md]] >= k)
      rb = md;
    else
      lb = md;
  }
  return rb;
}

inline void calcMin(int i){
  g[i].resize(all[i].size() + 1), h[i].resize(all[i].size() + 1);
  for(int j = all[i].size(); j >= 0; --j)
    g[i][j] =
      min(j == all[i].size() ? INF : g[i][j + 1],
	  f[i][j] - (j == all[i].size() ? a[i] : r[all[i][j]]) * 2);
  for(int j = 0; j <= all[i].size(); ++j)
    h[i][j] =
      min(j == 0 ? INF : h[i][j - 1],
	  f[i][j] - (j ==  all[i].size() ? a[i] : r[all[i][j]]));
  return;
}

inline void solve(){
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; ++i)
    scanf("%d", a + i);
  for(int i = 0; i < m; ++i)
    scanf("%d%d", l + i, r + i), ord[i] = i;

  sort(a, a + n);
  sort(ord, ord + m, cmp);

  for(int i = 0; i <= n; ++i)
    all[i].clear();

  int mn = 0x3f3f3f3f;
  for(int it = m - 1; it >= 0; --it){
    int i = ord[it];
    vis[i] = false;
    if(lower_bound(a, a + n, l[i]) < upper_bound(a, a + n, r[i]))
      vis[i] = true;
    if(mn <= r[i])
      vis[i] = true;
    if(!vis[i])
      mn = min(mn, r[i]), all[upper_bound(a, a + n, l[i]) - a].PB(i);
  }

  for(int i = 0; i <= n; ++i)
    reverse(all[i].begin(), all[i].end());
  /*
  for(int i = 0; i <= n; ++i){
    printf("i = %d\n", i);
    for(int j = 0; j < all[i].size(); ++j)
      printf("(%d %d) ", l[all[i][j]], r[all[i][j]]); puts("");
  }
  */
  f[0].resize(all[0].size() + 1);
  for(int i = 1; i < f[0].size(); ++i)
    f[0][i] = INF;
  f[0][0] = 0;
  calcMin(0);
  
  for(int i = 0; i < n; ++i){
    f[i + 1].resize(all[i + 1].size() + 1);
    for(int j = 0; j <= all[i + 1].size(); ++j){
      int vr = j ? l[all[i + 1][j - 1]] - a[i] : 0;
      int pos = find(all[i], a[i] - vr);
      //printf("pos = %d vr = %d\n", pos, vr);
      f[i + 1][j] = min(g[i][pos] + a[i] * 2 + vr,
		    pos ? h[i][pos - 1] + a[i] + vr * 2 : INF);
    }
    /*
    printf("i = %d\n", i);
    for(int j = 0; j <= all[i + 1].size(); ++j)
      printf("%lld ", f[i + 1][j]); puts("");
    */ 
    calcMin(i + 1);
  }

  printf("%lld\n", f[n].back());
  return;
}

int main(){
  //freopen("F.in", "r", stdin);
  int T;
  for(scanf("%d", &T); T--; solve());
  return 0;
}