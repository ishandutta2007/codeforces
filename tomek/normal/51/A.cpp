#include <set>
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

int main() {
  int ntc = rint();
  char buf[10];
  set<string> ss;
  REP(tc,ntc) {
    if(tc>0) scanf("%s", buf);
    scanf("%s", buf);
    string s;
    s += buf[0];
    s += buf[1];
    scanf("%s", buf);
    s += buf[1];
    s += buf[0];
    string best = s;
    REP(i,4) {
      char t = s[0]; s[0]=s[1]; s[1]=s[2]; s[2]=s[3]; s[3]=t;
      if(s < best) best=s;
    }
    ss.insert(best);
  }
  int res = size(ss);
  printf("%d\n", res);
}