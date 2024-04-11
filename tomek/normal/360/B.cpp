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

int N,K;
vector<LL> v;

bool Good(LL d) {
  static vector<int> tab;
  tab.resize(N);
  REP(i,N) {
    tab[i] = i;
    REP(j,i) if(llabs(v[i]-v[j]) <= d * (i-j)) tab[i] = min(tab[i], tab[j]+i-j-1);
  }
  int cnt = N;
  REP(i,N) cnt = min(cnt, N-i-1+tab[i]);
  return cnt <= K;
}

int Solve() {
  LL aa = -1, bb = 2*INF+1;
  while(bb-aa>1) {
    LL cc = (aa+bb)/2;
    if(Good(cc)) bb = cc; else aa = cc;
  }
  return int(bb);
}

int main() {
  N = rint();
  K = rint();
  REP(i,N) v.push_back(rint());
  int res = Solve();
  printf("%d\n", res);
}