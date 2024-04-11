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
LL rLL() { LL x; if(scanf("%lld",&x)!=1) return -1; return x; }
string rstring() { static char buf[100000]; if(scanf("%s",buf)!=1) return ""; return buf; }
//}}}

int main() {
  int n = rint();
  vector<int> p(n+1);
  vector<pair<int,int> > pairs;
  FOR(i,1,n) {
    int j = n+1-i;
    if(i<j) {
      pairs.push_back(make_pair(i,j));
    } else if(i==j) {
      p[i]=i;
    }
  }
  if(size(pairs)%2!=0) {
    printf("-1\n");
    return 0;
  }
  for(int i=0;i<size(pairs);i+=2) {
    p[pairs[i].first] = pairs[i+1].first;
    p[pairs[i+1].first] = pairs[i].second;
    p[pairs[i].second] = pairs[i+1].second;
    p[pairs[i+1].second] = pairs[i].first;
  }
  FOR(i,1,n) printf("%d ", p[i]);
  printf("\n");
}