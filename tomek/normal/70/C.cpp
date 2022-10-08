//{{{
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include <cassert>
#include <ctime>
#include <queue>
using namespace std;
#define VAR(a,b) __typeof(b) a=(b)
#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)
#define ALL(c) (c).begin(),(c).end()
#define TRACE(x) cerr << "TRACE(" #x ")" << endl;
#define DEBUG(x) cerr << #x << " = " << x << endl;

template<class T>
ostream& operator<<(ostream&o, const vector<T>&v) {
  o<<'{';
  FOREACH(it,v) o<<*it<<',';
  return o<<'}';
}
typedef long long LL;
const int INF = 1000000000; const LL INFLL = LL(INF) * LL(INF);
typedef vector<int> VI; typedef vector<string> VS; typedef vector<VI> VVI;
template<class T> inline int size(const T&c) { return c.size(); }
int rint() { int x; if(scanf("%d",&x)!=1) return -1; return x; }
//}}}

int gcd(int a,int b) {
  return b==0 ? a : gcd(b, a%b);
}

inline pair<int,int> revfrac(pair<int,int> p) {
  return make_pair(p.second, p.first);
}

int maxx,maxy,minmatches;
int maxxy;
vector<int> rev;
vector<pair<int,int> > frac;
map<pair<int,int>, int> xcount, ycount;

int calcRev(int x) {
  int y=0;
  while(x) {
    y = 10*y + (x%10);
    x/=10;
  }
  return y;
}

int main() {
  maxx = rint();
  maxy = rint();
  minmatches = rint();
  maxxy = max(maxx, maxy);
  rev.resize(maxxy+1);
  REP(i,size(rev)) rev[i] = calcRev(i);
  frac.resize(maxxy+1);
  FOR(i,1,maxxy) {
    int a = rev[i];
    int b = i;
    int g = gcd(a,b);
    a /= g;
    b /= g;
    frac[i] = make_pair(a,b);
  }
  int y = maxy;
  LL total = 0;
  FOR(i,1,y) ycount[frac[i]]++;
  int x = 0;
  int bestx = 0, besty=0;
  LL bestxy = -1;
  REP(i,maxy) {
    while(x < maxx && total < minmatches) {
      ++x;
      total += ycount[revfrac(frac[x])];
      xcount[frac[x]]++;
    }
    if(total >= minmatches) {
      LL xy = LL(x) * y;
      if(bestxy==-1 || xy < bestxy) { bestx = x; besty=y; bestxy=xy; }
    }
    total -= xcount[revfrac(frac[y])];
    ycount[frac[y]]--;
    --y;
  }
  if(bestxy==-1) { printf("-1\n"); }
  else printf("%d %d\n", bestx, besty);

}