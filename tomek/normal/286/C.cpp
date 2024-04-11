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

vector<int> seq;
const int BIG = INF + 10;

vector<pair<int,int> > ss;  // value, index

void Collapse(int v) {
  static vector<int> cs;
  cs.push_back(v);
  while(!cs.empty()) {
    if(ss.empty()) throw 0;
    pair<int,int> p = ss.back(); ss.pop_back();
    if(p.first == cs.back()) {
      cs.pop_back();
    } else {
      cs.push_back(p.first);
      seq[p.second] *= -1;
    }
  }
}

bool process() {
  try {
    REP(i,size(seq)) {
      if(seq[i]>0) ss.push_back(make_pair(seq[i], i));
      else Collapse(-seq[i]);
    }
    return true;
  } catch (int) {
    return false;
  }
}

int main() {
  int n = rint();
  seq.push_back(BIG);
  REP(i,n) seq.push_back(rint());
  seq.push_back(-BIG);
  int t = rint();
  REP(i,t) seq[rint()] *= -1;
  if(process()) {
    printf("YES\n");
    FOR(i,1,n) printf("%d ", seq[i]);
    printf("\n");
  } else {
    printf("NO\n");
  }
}