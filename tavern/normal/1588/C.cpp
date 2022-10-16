#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5 + 5;

class SegmentTree{
public:
  static const int siz = 524288;
  long long tag[siz << 1], dat[siz << 1];
  
  inline void init(int x, int l, int r, int s){
    dat[x] = 0, tag[x] = 0;
    if(l == r){
      dat[x] = ((l & 1) == s ? 0 : 1e18);
      return;
    }
    int md = l + r >> 1;
    init(x << 1, l, md, s);
    init(x << 1 | 1, md + 1, r, s);
    return;
  }
  inline void update(int s, int t, int k, int x, int l, int r){
    if(l >= s && r <= t){
      tag[x] += k, dat[x] += k;
      return;
    }
    int md = l + r >> 1;
    if(s <= md)
      update(s, t, k, x << 1, l, md);
    if(t > md)
      update(s, t, k, x << 1 | 1, md + 1, r);
    dat[x] = min(dat[x << 1], dat[x << 1 | 1]) + tag[x];
    return;
  }
  inline int find(int y, int k, int x, int l, int r){
    if(dat[x] >= k)
      return 0x3f3f3f3f;
    if(l == r)
      return l;
    int md = l + r >> 1, ret = 0x3f3f3f3f;
    if(y <= md)
      ret = find(y, k - tag[x], x << 1, l, md);
    if(ret == 0x3f3f3f3f)
      ret = find(y, k - tag[x], x << 1 | 1, md + 1, r);
    return ret;
  }
} S[2];

int n;
int a[maxn];
long long sum[maxn];
map<long long, vector<int> > vec[2];

inline void solve(){
  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    scanf("%d", a + i), sum[i] = a[i] - (i ? sum[i - 1] : 0), vec[i & 1][sum[i]].push_back(i);
  /*
  for(int i = 0; i < n; ++i)
    printf("%lld ", sum[i]); puts("");
  */
  S[0].init(1, 0, n - 1, 0), S[1].init(1, 0, n - 1, 1);
  long long ans = 0;
  for(int i = n - 1; i >= 0; --i){
    S[i & 1].update(i, n - 1, a[i], 1, 0, n - 1);
    S[!(i & 1)].update(i, n - 1, -a[i], 1, 0, n - 1);
    int pos = min(S[0].find(i, 0, 1, 0, n - 1), S[1].find(i, 0, 1, 0, n - 1));
    //printf("i = %d pos = %d\n", i, pos);
    long long s = (i ? sum[i - 1] : 0);
    ans += upper_bound(vec[i & 1][-s].begin(), vec[i & 1][-s].end(), pos)
      - lower_bound(vec[i & 1][-s].begin(), vec[i & 1][-s].end(), i);
    ans += upper_bound(vec[!(i & 1)][s].begin(), vec[!(i & 1)][s].end(), pos)
      - lower_bound(vec[!(i & 1)][s].begin(), vec[!(i & 1)][s].end(), i);
  }
  for(int i = 0; i < n; ++i)
    vec[i & 1][sum[i]].clear();
  printf("%lld\n", ans);
  return;
}

int main(){
  //freopen("C.in", "r", stdin);
  int T;
  for(scanf("%d", &T); T--; solve());
  return 0;
}