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
int dist;
int pos[3];

bool trybuild(int d) {
  int p[3];
  int done=0;
  REP(i,3) {
    if(done==size(v)) {
      p[i] = 0;
    } else {
      p[i] = v[done];
      done = lower_bound(v.begin(), v.end(), v[done]+d+1) - v.begin();
    }
  }
  if(done==size(v)) {
    REP(i,3) pos[i]=p[i];
    dist=d;
    return true;
  } else return false;
}

void calc() {
  int a = -1;
  int b = v.back()-v.front()+1;
  while(b-a>1) {
    int c = (a+b)/2;
    if(trybuild(c)) b=c; else a=c;
  }
}

int main() {
  n = rint();
  v.resize(n);
  REP(i,n) v[i]=rint();
  sort(v.begin(), v.end());
  calc();
  printf("%.6f\n", double(dist)/2);
  REP(i,3) printf("%.6f ", double(dist)/2 + pos[i]);
  printf("\n");
}