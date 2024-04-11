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
#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define TRACE(x) cerr << "TRACE(" #x ")" << endl;
#define DEBUG(x) cerr << #x << " = " << (x) << endl;

typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1000000000; const LL INFLL = LL(INF) * LL(INF);
template<class T> inline int size(const T&c) { return c.size(); }
int rint() { int x; if(scanf("%d",&x)!=1) return -1; return x; }
string rstring() { static char buf[100000]; if(scanf("%s",buf)!=1) return ""; return buf; }
//}}}

const int MOD = INF + 7;
inline int add(int a, int b) { return (a+b)%MOD; }

int LIMIT;
int TOP;

inline int Ones(int n) {
  return (1<<n)-1;
}

inline int Pow2(int n) { return (1<<n) % MOD; }
inline int mul(int a, int b) { return LL(a)*b % MOD; }

int HIGHEST, ANY_BITS;

int cache[32][32][32];

int Go(int p, int freeBits, int freeAnyBits) {
  int &res = cache[p][freeBits][freeAnyBits];
  if(res!=-1) return res;
  if(p==TOP) {
    res = Pow2(freeAnyBits);
  } else {
    if(HIGHEST & (1<<p)) res = mul(Pow2(freeBits), Go(p+1, freeBits, freeAnyBits));
    else res = 0;
    res = add(res, Go(p+1, freeBits + 1, freeAnyBits + (p<ANY_BITS)));
  }
  //DEBUG(p); DEBUG(freeBits); DEBUG(freeAnyBits); DEBUG(res);
  return res;
}

int Solve(int highest, int anyBits) {
  HIGHEST = highest;
  ANY_BITS = anyBits;

  memset(cache, -1, sizeof(cache));
  return Go(0, 0, 0);
}

int Solve() {
  int res = Solve(Ones(TOP+1), 0);
  REP(i, TOP) if(LIMIT&(1<<i)) {
    res = add(res, Solve((LIMIT & ~Ones(i+1)) | Ones(i), i));
  }
  return res;
}

int main() {
  LIMIT = rint()+1;
  TOP = 0;
  REP(i,30) if(LIMIT & (1<<i)) TOP = i;

  int res = Solve();
  printf("%d\n", res);
}