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

int n;
vector<int> v;

inline bool ok(int a,int b) {
  return !(a==0 && b != 0);
}

inline bool ok(int a,int b,int c,int d) {
  return ok(a,b) && ok(c,d) && a*d==b*c;
}

bool geometric(int skip) {
  int done = 0;
  int first = 0, second=0;
  int prev=0;
  REP(i,n) if(i!=skip) {
    if(done==0) first=v[i];
    else if(done==1) {
      second=v[i];
      if(!ok(first, second)) return false;
      prev=second;
    }
    else if(!ok(first,second,prev,v[i])) return false;
    prev=v[i];
    ++done;
  }
  return true;
}

bool canskip1() {
  int a = v[0];
  int b = v[1];
  if(!ok(a,b)) return false;
  int skipped=0;
  int prev=b;
  FOR(i,2,n-1) {
    if(!ok(a,b,prev,v[i])) {
      ++skipped;
      if(skipped>=2) return false;
    }
    else {
      prev=v[i];
    }
  }
  return true;
}

int calc() {
  if(geometric(-1)) return 0;
  if(geometric(0)) return 1;
  if(geometric(1)) return 1;
  if(canskip1()) return 1;
  return 2;
}

int main() {
  n = rint();
  v.resize(n);
  REP(i,n) v[i]=rint();
  int res = calc();
  printf("%d\n", res);
}