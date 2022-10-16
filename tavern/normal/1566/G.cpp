#include <bits/stdc++.h>

using namespace std;

#define eprintf( ... ) fprintf(stderr, __VA_ARGS__)

const int maxn = 2e5 + 5;
const int INF = 0x3f3f3f3f;

#define MP make_pair
#define fst first
#define snd second

class Data{
public:
  long long minSum;
  pair<int, pair<int, int> > minEdge;
  pair<int, int> ed[3];
  Data(){
    minSum = 0x3f3f3f3f3f3f3f3f;
    minEdge = MP(0x3f3f3f3f, MP(0x3f3f3f3f, 0x3f3f3f3f));
    for(int i = 0; i < 3; ++i)
      ed[i] = MP(0x3f3f3f3f, 0x3f3f3f3f);
    return;
  }

  inline Data operator + (const Data &oth)const{
    //eprintf("operator +\n");
    Data ret;
    ret.minSum = min(minSum, oth.minSum);
    ret.minEdge = min(minEdge, oth.minEdge);
    for(int i = 0; i < 3; ++i)
      ret.ed[i] = ed[i];
    for(int i = 0; i < 3; ++i){
      //eprintf("i = %d\n", i);
      bool f = false;
      for(int j = 0; j < 3; ++j)
	if(ret.ed[j].snd == oth.ed[i].snd)
	  ret.ed[j].fst = min(ret.ed[j].fst, oth.ed[i].fst), f = true;
      if(f){
	sort(ret.ed, ret.ed + 3);
	continue;
      }
      if(oth.ed[i] < ret.ed[0])
	ret.ed[2] = ret.ed[1], ret.ed[1] = ret.ed[0], ret.ed[0] = oth.ed[i];
      else if(oth.ed[i] < ret.ed[1])
	ret.ed[2] = ret.ed[1], ret.ed[1] = oth.ed[i];
      else if(oth.ed[i] < ret.ed[2])
	ret.ed[2] = oth.ed[i];
    }
    return ret;
  }
} ;

class SegmentTree{
public:
  static const int siz = 131072;
  Data dat[siz << 1];
  inline void update(int x, Data k){
    //eprintf("update\n");
    for(dat[x += siz] = k; x >>= 1; ){
      //eprintf("x = %d\n", x);
      dat[x] = dat[x << 1] + dat[x << 1 | 1];
    }
    //eprintf("finish update\n");
    return;
  }
  inline Data query(int l, int r){
    Data ret;
    //eprintf("query\n");
    for(l += siz, r += siz + 1; l < r; l >>= 1, r >>= 1){
      if(l & 1)
	ret = ret + dat[l++];
      if(r & 1)
	ret = ret + dat[--r];
    }
    //eprintf("finish query\n");
    return ret;
  }
} seg;

int n, m, q;
set<pair<int, int> > S[maxn];
map<int, int> ed[maxn];

inline void recalc(int u){
  Data res;
  if(S[u].size() >= 3)
    res.minSum = 0;
  int tot = 0;
  for(set<pair<int, int> >::iterator it = S[u].begin(); it != S[u].end() && tot < 3; ++it){
    if(S[u].size() >= 3)
      res.minSum += it -> fst;
    res.ed[tot++] = *it;
    res.minEdge = min(res.minEdge, MP(it -> fst, MP(u, it -> snd)));
  }
  seg.update(u, res);
  //eprintf("u = %d minEdge = (%d %d)\n", u, res.minEdge.snd.fst, res.minEdge.snd.snd);
  return;
}

inline void insert(int u, int v, int w){
  S[u].insert(MP(w, v));
  S[v].insert(MP(w, u));
  recalc(u), recalc(v);
  return;
}

inline void erase(int u, int v){
  int w = ed[u][v];
  S[u].erase(MP(w, v));
  S[v].erase(MP(w, u));
  recalc(u), recalc(v);
  return;
}

inline long long query(){
  long long ret = 0x3f3f3f3f3f3f3f3f;
  Data res = seg.query(0, n - 1);
  // Methyl
  ret = res.minSum;
  // Single Bond
  int u = res.minEdge.snd.fst, v = res.minEdge.snd.snd;
  if(u > v)
    swap(u, v);
  // with minimum edge
  if(u - 1 >= 0){
    Data res2 = seg.query(0, u - 1);
    for(int it = 0; it < 3; ++it)
      if(res2.ed[it].fst != INF && res2.ed[it].snd != u && res2.ed[it].snd != v)
	ret = min(ret, (long long)res.minEdge.fst + res2.ed[it].fst);
  }
  //eprintf("step 1 ret = %d\n", ret);
  if(u + 1 <= v - 1){
    Data res2 = seg.query(u + 1, v - 1);
    for(int it = 0; it < 3; ++it)
      if(res2.ed[it].fst != INF && res2.ed[it].snd != u && res2.ed[it].snd != v)
	ret = min(ret, (long long)res.minEdge.fst + res2.ed[it].fst);
  }
  //eprintf("step 2 ret = %d\n", ret);
  if(v + 1 <= n - 1){
    Data res2 = seg.query(v + 1, n - 1);
    for(int it = 0; it < 3; ++it)
      if(res2.ed[it].fst != INF && res2.ed[it].snd != u && res2.ed[it].snd != v)
	ret = min(ret, (long long)res.minEdge.fst + res2.ed[it].fst);
  }
  //eprintf("step 3 ret = %d\n", ret);
  // without minimum edge
  int ptr = 0;
  for(set<pair<int, int> >::iterator it = S[u].begin(); it != S[u].end() && ptr < 3; ++it, ++ptr){
    int qtr = 0;
    for(set<pair<int, int> >::iterator jt = S[v].begin(); jt != S[v].end() && qtr < 3; ++jt, ++qtr)
      if(it -> fst != INF && jt -> fst != INF && it -> snd != jt -> snd && it -> snd != v && jt -> snd != u){
	//eprintf("u = %d v = %d x = %d y = %d\n", u, v, it -> snd, jt -> snd);
	ret = min(ret, (long long)it -> fst + jt -> fst);
      }
  }
  //eprintf("finished! ret = %d\n", ret);
  return ret;
}

int main(){
  //freopen("G.in", "r", stdin);
  
  scanf("%d%d", &n, &m);

  for(int i = 0; i < n; ++i)
    recalc(i);

  for(int i = 0; i < m; ++i){
    int u, v, w; scanf("%d%d%d", &u, &v, &w);
    --u, --v;
    insert(u, v, w), ed[u][v] = ed[v][u] = w;
  }

  //eprintf("FUCK\n");
       
  printf("%lld\n", query());

  scanf("%d", &q);
  for(int i = 0; i < q; ++i){
    //eprintf("i = %d\n", i);
    int tp, u, v, w; scanf("%d%d%d", &tp, &u, &v);
    --u, --v;
    if(tp == 0)
      erase(u, v);
    else
      scanf("%d", &w), insert(u, v, w), ed[u][v] = ed[v][u] = w;
    printf("%lld\n", query());
  }
  return 0;
}