#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <iterator>
#include <algorithm>

using namespace std;

const int maxn = 222222;

vector <int> all;
set <int> occ;
set <int>::iterator it, it2;
map <int, int> here, wh;
set < pair <int, int> > s;
int nn,t,q,len,st,p,le,ri,i;
int z,x,v,ans,ll,rr,xx,low,high;
int id[maxn], il[maxn], ir[maxn];
int cr[maxn], a[maxn], h[maxn];

int main() {
//  freopen("in","r",stdin);
//  freopen("out","w",stdout);
  scanf("%d%d",&nn,&t);
  s.clear();
  s.insert(make_pair(-nn,-1));
  here.clear();
  occ.clear();
  occ.insert(0);
  occ.insert(nn+1);
  all.clear();
  for (q=0;q<t;q++) {
    scanf("%d",&id[q]);
    if (id[q] == 0) scanf("%d%d",&il[q],&ir[q]); else
    if (!here[id[q]]) {
      len = -(*(s.begin())).first;
      st = -(*(s.begin())).second;
      s.erase(s.begin());
      p = st+(len >> 1);
      cr[q] = p;
      all.push_back(p);
      occ.insert(p);
      if (st <= p-1) s.insert(make_pair(-(p-st),-st));
      if (p+1 <= st+len-1) s.insert(make_pair(-(st+len-p-1),-(p+1)));
      here[id[q]] = p;
    } else {
      p = here[id[q]];
      cr[q] = -p;
      it = occ.find(p);
      it2 = it;
      it2--;
      le = *it2;
      it++;
      ri = *it;
      occ.erase(p);
      if (le+1 <= p-1) s.erase(make_pair(-(p-le-1),-(le+1)));
      if (p+1 <= ri-1) s.erase(make_pair(-(ri-p-1),-(p+1)));
      s.insert(make_pair(-(ri-le-1),-(le+1)));
      here[id[q]] = 0;
    }
  }
  sort(all.begin(), all.end());
  all.erase(unique(all.begin(), all.end()), all.end());
  wh.clear();
  z = all.size();
  for (i=0;i<z;i++) wh[all[i]] = i+1;
  for (i=1;i<=z;i++) h[i] = all[i-1];
  for (i=1;i<=z;i++) a[i] = 0;
  for (q=0;q<t;q++)
    if (id[q] == 0) {
      ll = 1; rr = z+1;
      while (ll < rr) {
        xx = (ll+rr) >> 1;
        if (h[xx] >= il[q]) rr = xx;
        else ll = xx+1;
      }
      low = ll;
      ll = 0; rr = z;
      while (ll < rr) {
        xx = (ll+rr+1) >> 1;
        if (h[xx] <= ir[q]) ll = xx;
        else rr = xx-1;
      }
      high = ll;
      ans = 0;
      if (low <= high) {
        x = high;
        while (x > 0) {
          ans += a[x];
          x &= x-1;
        }
        x = low-1;
        while (x > 0) {
          ans -= a[x];
          x &= x-1;
        }
      }
      printf("%d\n",ans);
    } else {
      x = cr[q];
      v = 1;
      if (x < 0) {
        x = -x;
        v = -1;
      }
      x = wh[x];
      while (x <= z) {
        a[x] += v;
        x = (x | (x-1)) + 1;
      }
    }
  return 0;
}