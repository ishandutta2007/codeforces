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

int main() {
  int n = rint();
  int sum1=0, sum2=0;
  vector<int> middle;
  REP(i,n) {
    int s = rint();
    vector<int> v;
    REP(i,s) v.push_back(rint());
    REP(i,s/2) {
      sum1 += v[i];
      sum2 += v[s-1-i];
    }
    if(s%2) middle.push_back(v[s/2]);
  }
  sort(middle.begin(), middle.end(),greater<int>());
  REP(i,size(middle)) if(i%2==0) sum1+=middle[i]; else sum2 += middle[i];
  printf("%d %d\n", sum1, sum2);
}