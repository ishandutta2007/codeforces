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

vector<int> tablesizes;

string nextTag;

int readChar() {
  int a = 0;
  while(a>=0 && a<=32) a = getchar();
  return a;
}

void readTag() {
  nextTag = "";
  int c = readChar();
  if(c==EOF) return;
  for(;;) {
    c = readChar();
    if(c=='>') break;
    nextTag += char(c);
  }
}

int readTable() {
  readTag();
  int res = 0;
  while(nextTag == "tr") {
    readTag();
    while(nextTag=="td") {
      readTag();
      if(nextTag=="table") {
        tablesizes.push_back(readTable());
      }
      readTag();
      ++res;
    }
    readTag();
  }
  readTag();
  return res;
}

int main() {
  readTag();
  tablesizes.push_back(readTable());
  sort(tablesizes.begin(), tablesizes.end());
  REP(i,size(tablesizes)) printf("%d ", tablesizes[i]);
  printf("\n");
}