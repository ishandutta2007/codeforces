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

int main() {
  int n = rint();
  int m = rint();
  vector<vector<int>> ops;
  REP(i,m) {
    vector<int> op;
    REP(j,4) op.push_back(rint());
    op[1]--; op[2]--;
    ops.push_back(op);
  }
  vector<int> a(n,INF);
  vector<int> d(n,0);
  for(const vector<int> &op : ops) {
    if(op[0]==1) {
      FOR(i,op[1],op[2]) d[i] += op[3];
    } else {
      FOR(i,op[1],op[2]) a[i] = min(a[i], op[3]-d[i]);
    }
  }
  d.assign(n,0);
  bool ok = true;
  for(const vector<int> &op : ops) {
    if(op[0]==1) {
      FOR(i,op[1],op[2]) d[i] += op[3];
    } else {
      int mm = -INF;
      FOR(i,op[1],op[2]) mm = max(mm, a[i]+d[i]);
      ok = ok && mm == op[3];
    }
  }
  if(ok) {
    printf("YES\n");
    REP(i,n) printf("%d ", a[i]);
    printf("\n");
  } else {
    printf("NO\n");
  }
}