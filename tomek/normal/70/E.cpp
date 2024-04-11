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
const int INF = 1000000000; const LL INFLL = LL(INF) * LL(INF)/10;
typedef vector<int> VI; typedef vector<string> VS; typedef vector<VI> VVI;
template<class T> inline int size(const T&c) { return c.size(); }
int rint() { int x; if(scanf("%d",&x)!=1) return -1; return x; }
//}}}

int n;
vector<vector<int> > ch;
vector<int> parent;
vector<LL> dcost;

vector<int> isCenter;

void readInput() {
  n = rint();
  ch.resize(n);
  dcost.resize(2*n);
  dcost[0] = rint();
  FOR(i,1,n-1) dcost[i] = rint();
  FOR(i,n,2*n-1) dcost[i]=INFLL;
  REP(i,n-1) {
    int a = rint()-1;
    int b = rint()-1;
    ch[a].push_back(b);
    ch[b].push_back(a);
  }
  parent.assign(n,-1);
  isCenter.assign(n,0);
}

void treewalk(int x) {
  if(parent[x] != -1) {
    ch[x].erase(find(ch[x].begin(), ch[x].end(), parent[x]));
  }
  FOREACH(it, ch[x]) {
    parent[*it]=x;
    treewalk(*it);
  }
}

struct Res {
  LL score;
  int dist;
  int inchild;
};

Res cache[200][400][2];

Res f(int x, int dist, int doit) {
  Res &res = cache[x][dist][doit];
  if(res.score != -1) return res;
  res.score = INFLL;
  FOR(d2,0,dist-1) {
    Res res2 = f(x, d2, 1);
    if(res2.score < res.score) res=res2;
  }
  {
    Res rr;
    rr.score = dcost[0];
    rr.dist = 0;
    rr.inchild = -1;
    FOREACH(it, ch[x]) rr.score += f(*it, 1, 0).score;
    if(rr.score < res.score) res=rr;
  }
  if(!doit) {
    Res rr;
    rr.score = dcost[dist];
    rr.dist = dist;
    rr.inchild = -1;
    FOREACH(it, ch[x]) rr.score += f(*it, dist+1, 0).score;
    if(rr.score < res.score) res=rr;
  } else {
    Res rr;
    rr.score = dcost[dist];
    rr.dist = dist;
    rr.inchild = -1;
    FOREACH(it, ch[x]) rr.score += f(*it, dist+1, 0).score;
    LL bestv = INFLL;
    FOREACH(it, ch[x]) {
      LL v = f(*it, dist-1, 1).score - f(*it, dist+1, 0).score;
      if(v < bestv) { bestv=v; rr.inchild = *it; }
    }
    rr.score += bestv;
    if(rr.score < res.score) res=rr;
  }
  return res;
}

void calcCenters(int x, int dist, int doit) {
  Res res = f(x,dist,doit);
  if(res.dist==0) isCenter[x]=1;
  FOREACH(it, ch[x]) {
    if(*it == res.inchild) calcCenters(*it, res.dist-1, 1);
    else calcCenters(*it, res.dist+1, 0);
  }
}

LL calcCenters() {
  LL bestScore = INFLL;
  int bestDist = -1;
  FOR(d,0,n-1) {
    Res r = f(0, d, 1);
    if(r.score < bestScore) { bestScore=r.score; bestDist=d; }
  }
  calcCenters(0, bestDist, 1);
  return bestScore;
}

int findNearestCenter(int x) {
  queue<int> q;
  q.push(x);
  vector<int> vis(n,0);
  while(!q.empty()) {
    int a = q.front(); q.pop();
    if(vis[a]) continue;
    vis[a]=1;
    if(isCenter[a]) return a;
    if(parent[a]!=-1) q.push(parent[a]);
    FOREACH(it, ch[a]) q.push(*it);
  }
  return -1;
}

int main() {
  REP(a,200) REP(b,400) REP(c,2) cache[a][b][c].score=-1;
  readInput();
  treewalk(0);
  LL res = calcCenters();
  printf("%lld\n", res);
  REP(i,n) {
    if(i>0) printf(" ");
    printf("%d", 1 + findNearestCenter(i));
  }
  printf("\n");
}