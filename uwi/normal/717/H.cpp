#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <map>
#include <set>
#include <iostream>
#include <sstream>
#include <numeric>
#include <cctype>
#include <bitset>
#include <cassert>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcount
#define uni(x) x.erase(unique(rng(x)),x.end())
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define df(x) int x = in()
#define dame { puts("0"); return 0;}
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,vector<T>,greater<T> >
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}
template<typename T>istream& operator>>(istream&i,vector<T>&v)
{rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(vector<T>&v)
{stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>ostream& operator<<(ostream&o,vector<T>&v)
{if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v)
{return i>>v.fi>>v.se;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,pair<T1,T2>&v)
{return o<<v.fi<<","<<v.se;}
const int MX = 100005, INF = 1001001001;
const ll LINF = 1e18;
const double eps = 1e-10;

int n, m, t;
vp e;
vvi c;
vi g;
vi b;


inline void setb() {
  rep(i,t) b[i] = rand()%2;
}
inline void setg() {
  rep(i,n) g[i] = c[i][rand()%sz(c[i])];
}

int main() {
  snuke;
  scanf("%d%d",&n,&m);
  e = vp(m);
  rep(i,m) {
    scanf("%d%d",&e[i].fi,&e[i].se);
    e[i].fi--; e[i].se--;
  }
  c = vvi(n);
  rep(i,n) {
    int k;
    scanf("%d",&k);
    c[i] = vi(k);
    rep(j,k) scanf("%d",&c[i][j]), maxs(t,c[i][j]), c[i][j]--;
  }
  b = vi(t); g = vi(n);
  while (1) {
    setb();
    setg();
    int cnt = 0;
    rep(i,m) {
      cnt += (b[g[e[i].fi]]^b[g[e[i].se]]);
    }
    if (cnt*2 >= m) {
      rep(i,n) g[i]++;
      rep(i,t) b[i]++;
      cout<<g<<endl;
      cout<<b<<endl;
      return 0;
    }
  }
  return 0;
}