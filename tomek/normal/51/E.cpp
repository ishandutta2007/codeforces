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

const int MAXN = 700;

int n;
bool edge[MAXN][MAXN];
int deg[MAXN];
int len2[MAXN][MAXN];

void readInput() {
  n = rint();
  int m = rint();
  REP(i,m) {
    int a = rint()-1;
    int b = rint()-1;
    edge[a][b]=true;
    edge[b][a]=true;
    ++deg[a];
    ++deg[b];
  }
}

LL calc() {
  REP(a,n) REP(b,a) {
    int cnt=0;
    REP(c,n) {
      if(edge[a][c] && edge[b][c]) ++cnt;
    }
    len2[a][b]=cnt;
    len2[b][a]=cnt;
  }
  LL res = 0;
  REP(a,n) REP(b,a) if(edge[a][b]) {
    REP(c,n) if(c!=a && c!=b) {
      int ac = len2[a][c];
      if(edge[b][c]) --ac;
      int bc = len2[b][c];
      if(edge[a][c]) --bc;
      res += LL(ac) * LL(bc);
      if(edge[b][c] && edge[a][c]) res -= deg[c]-2;
    }
  }
  assert(res%5==0);
  return res/5;
}

int main() {
  readInput();
  LL res = calc();
  cout << res << "\n";
}