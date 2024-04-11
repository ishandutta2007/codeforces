#include <bits/stdc++.h>

using namespace std;

const int siz = 1048576;
const int maxn = 1e6 + 5;

int dat[siz << 1], tag[siz << 1];

inline void update(int s, int t, int k, int x = 1, int l = 0, int r = siz - 1){
  if(l >= s && r <= t){
    dat[x] += k, tag[x] += k;
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

inline int query(int s, int t, int x = 1, int l = 0, int r = siz - 1){
  if(l >= s && r <= t){
    return dat[x];
  }
  int md = l + r >> 1, ret = 0x3f3f3f3f;
  if(s <= md)
    ret = min(ret, query(s, t, x << 1, l, md));
  if(t > md)
    ret = min(ret, query(s, t, x << 1 | 1, md + 1, r));
  return ret + tag[x];
}

inline void clear(int s, int t, int x = 1, int l = 0, int r = siz - 1){
  dat[x] = tag[x] = 0;
  if(l == r)
    return;
  int md = l + r >> 1;
  if(s <= md)
    clear(s, t, x << 1, l, md);
  if(t > md)
    clear(s, t, x << 1 | 1, md + 1, r);
  return;
}

int n, m;

int dat2[maxn];

inline void update2(int x){ for(++x; x; x -= x & (-x)) ++dat2[x]; }
inline int query2(int x){ int ret = 0; for(++x; x <= n; x += x & (-x)) ret += dat2[x]; return ret; }

int a[maxn], b[maxn];

inline void solve(){
  scanf("%d%d", &n, &m);

  vector<pair<int, int> > veca, vecb;

  long long ans = 0;
  
  for(int i = 0; i < n; ++i){
    scanf("%d", a + i), veca.push_back(make_pair(a[i], i));
    update(i + 1, n, 1);
  }
  
  for(int i = 0; i < m; ++i)
    scanf("%d", b + i), vecb.push_back(make_pair(b[i], ~i));

  sort(veca.begin(), veca.end());
  sort(vecb.begin(), vecb.end());

  for(int i = 0; i <= n; ++i)
    dat2[i] = 0;

  for(int i = 0, j; i < veca.size(); i = j){
    for(j = i; j < veca.size() && veca[j].first == veca[i].first; ++j)
      ans += query2(veca[j].second);
    for(j = i; j < veca.size() && veca[j].first == veca[i].first; ++j)
      update2(veca[j].second);
  }

  int i, j, k;
  for(i = 0, j = 0, k; i < vecb.size(); i = k){
    int val = vecb[i].first;
    for(; j < veca.size() && veca[j].first < val; ++j)
      update(veca[j].second + 1, n, -1), update(0, veca[j].second, 1);
    int tmp = j;
    for(; j < veca.size() && veca[j].first == val; ++j)
      update(veca[j].second + 1, n, -1);
    for(k = i; k < vecb.size() && vecb[k].first == vecb[i].first; ++k)
      ans += query(0, n);
    for(j = tmp; j < veca.size() && veca[j].first == val; ++j)
      update(0, veca[j].second, 1);
  }

  clear(0, n);
  
  printf("%lld\n", ans);
  return;
}

int main(){
  //freopen("C.in", "r", stdin);
  
  int T;
  for(scanf("%d", &T); T--; solve());
  return 0;
}