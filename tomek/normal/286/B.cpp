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

int n;
void Print(const vector<int> &p, int st) {
  REP(i,n) {
    printf("%d ", p[st]+1);
    st++;
    if(st==n) st=0;
  }
  printf("\n");
}

void Shift(vector<int> &p, int &st, int k) {
  int a = p[st];
  int jump=0;
  while(jump<n) {
    jump+=k;
    if(jump>n) jump=n;
    int pos = st+jump;
    if(pos>=n) pos-=n;
    swap(a, p[pos]);
  }
  st++;
  if(st==n) st=0;
}

int main() {
  n = rint();
  vector<int> p(n);
  REP(i,n) p[i]=i;
  int st = 0;
  FOR(k,2,n) Shift(p,st,k);
  Print(p, st);
}