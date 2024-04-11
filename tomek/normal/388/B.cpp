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

const int MAXN = 1000;

int n;
int last;
int dist;
bool edge[MAXN][MAXN];

void addEdge(int a, int b) {
  edge[a][b] = true;
  edge[b][a] = true;
}

void solve(int k) {
  if(k==1) return;
  solve(k/2);
  addEdge(last, n);
  addEdge(last, n+1);
  addEdge(n,n+2);
  addEdge(n+1,n+2);
  last = n+2;
  dist += 2;
  n += 3;
  if(k%2) addEdge(1+dist-1, last);
}

int main() {
  int k = rint();
  n = 200;
  FOR(i,1,199) addEdge(i,i+1);
  last = 1;
  dist = 0;
  solve(k);
  addEdge(last, 0);
  printf("%d\n", n);
  REP(i,n) {
    REP(j,n) printf("%c", edge[i][j] ? 'Y' : 'N');
    printf("\n");
  }
}