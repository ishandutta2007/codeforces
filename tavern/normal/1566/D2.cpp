#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define PB push_back

const int maxn = 305;
const int maxv = maxn * maxn;

int n, m;
int a[maxv], cnt[maxv], ptr[maxv];
int vis[maxn][maxn];
vector<int> vec[maxv];

inline bool cmp(const int &i, const int &j){
  if(i / m != j / m)
    return (i / m) < (j / m);
  return (i % m) > (j % m);
}

inline void solve(){
  scanf("%d%d", &n, &m);
  vector<int> all;
  for(int i = 0; i < n * m; ++i)
    scanf("%d", a + i), all.PB(a[i]);
  sort(all.begin(), all.end());
  all.erase(unique(all.begin(), all.end()), all.end());

  for(int i = 0; i < n * m; ++i)
    a[i] = lower_bound(all.begin(), all.end(), a[i]) - all.begin(), ++cnt[a[i]];

  int tot = 0;
  for(int i = 0; i < n * m; ++i){
    ptr[i] = 0;
    vec[i].clear();
    for(int j = tot; j < tot + cnt[i]; ++j)
      vec[i].PB(j);
    sort(vec[i].begin(), vec[i].end(), cmp);
    tot += cnt[i];
  }

  for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j)
      vis[i][j] = false;

  int ans = 0;
  for(int i = 0; i < n * m; ++i){
    int pos = vec[a[i]][ptr[a[i]]]; ++ptr[a[i]];
    int x = pos / m, y = pos % m;
    for(int j = y + 1; j < m; ++j)
      ans += (!vis[x][j]);
    vis[x][y] = true;
  }

  printf("%d\n", ans);

  for(int i = 0; i < n * m; ++i)
    --cnt[a[i]];
  return;
}

int main(){
  //freopen("D.in", "r", stdin);
  int T;
  for(scanf("%d", &T); T--; solve());
  return 0;
}