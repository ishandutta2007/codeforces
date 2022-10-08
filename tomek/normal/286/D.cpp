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
#include <cassert>
#include <ctime>
#include <queue>
#include <set>
using namespace std;
#define VAR(a,b) __typeof(b) a=(b)
#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)
#define TRACE(x) cerr << "TRACE(" #x ")" << endl;
#define DEBUG(x) cerr << #x << " = " << (x) << endl;

typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1000000000; const LL INFLL = LL(INF) * LL(INF);
template<class T> inline int size(const T&c) { return c.size(); }
int rint() { int x; if(scanf("%d",&x)!=1) return -1; return x; }
string rstring() { static char buf[100000]; if(scanf("%s",buf)!=1) return ""; return buf; }
//}}}

struct WallEv {
  int x;
  int t;
  int ends;
};

inline bool operator<(const WallEv &a, const WallEv &b) {
  return a.x < b.x;
}

struct DerivEv {
  int t;
  int dd;
};

inline bool operator<(const DerivEv &a, const DerivEv &b) {
  return a.t < b.t;
}

vector<WallEv> wallEvs;
vector<DerivEv> derivEvs;

void calcDerivEvs() {
  multiset<int> ts;
  REP(i, size(wallEvs)) {
    const WallEv &we = wallEvs[i];
    if(we.ends == 0) {
      ts.insert(we.t);
    } else {
      ts.erase(ts.find(we.t));
    }
    if(i < size(wallEvs)-1 && !ts.empty()) {
      int x1 = we.x;
      int x2 = wallEvs[i+1].x;
      if(x1 < x2) {
        int t = *ts.begin();
        DerivEv de;
        de.t = t - x2;
        de.dd = 1;
        derivEvs.push_back(de);
        de.t = t - x1;
        de.dd = -1;
        derivEvs.push_back(de);
      }
    }
  }
  sort(derivEvs.begin(), derivEvs.end());
}

void processQueries(int n) {
  int dp = 0;
  int t = -INF;
  int v = 0;
  int deriv = 0;
  REP(i,n) {
    int q = rint();
    while(dp < size(derivEvs)) {
      const DerivEv &de =  derivEvs[dp];
      if(de.t >= q) break;
      v += deriv * (de.t - t);
      t = de.t;
      deriv += de.dd;
      ++dp;
    }
    int res = v + deriv * (q-t);
    printf("%d\n", res);
  }
}

int main() {
  int n=rint(),m=rint();
  wallEvs.reserve(2*m);
  REP(i,m) {
    int l = rint();
    int r = rint();
    int t = rint();
    WallEv we;
    we.x = l;
    we.t = t;
    we.ends = 0;
    wallEvs.push_back(we);
    we.x = r;
    we.ends = 1;
    wallEvs.push_back(we);
  }
  sort(wallEvs.begin(), wallEvs.end());
  calcDerivEvs();
  processQueries(n);
}