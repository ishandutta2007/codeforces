#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define limit(x,l,r) max(l,min(x,r))
#define lims(x,l,r) (x = max(l,min(x,r)))
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)),x.end())
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define bn(x) ((1<<x)-1)
#define dup(x,y) (((x)+(y)-1)/(y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
inline int in() { int x; scanf("%d",&x); return x;}
template<typename T>inline istream& operator>>(istream&i,v(T)&v)
{rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const v(T)&v)
{stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>inline ostream& operator<<(ostream&o,const v(T)&v)
{if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>inline istream& operator>>(istream&i,pair<T1,T2>&v)
{return i>>v.fi>>v.se;}
template<typename T1,typename T2>inline ostream& operator<<(ostream&o,const pair<T1,T2>&v)
{return o<<v.fi<<","<<v.se;}
template<typename T>inline ll suma(const v(T)& a) { ll res(0); for (auto&& x : a) res += x; return res;}
const double eps = 1e-10;
const ll LINF = 1e18;
const int INF = 1001001001;
#define dame { puts("-1"); return 0;}
#define yn {puts("YES");}else{puts("NO");}
const int MX = 200005;

vi to[MX];

P pfs(int v, int d=0, int p=-1) {
  P res(d,v);
  rep(i,sz(to[v])) {
    int u = to[v][i];
    if (u == p) continue;
    P r = pfs(u,d+1,v);
    maxs(res,r);
  }
  return res;
}

int used[MX];
int efs(int v, int tv, int p=-1) {
  if (v == tv) {
    used[v] = 1;
    return 1;
  }
  rep(i,sz(to[v])) {
    int u = to[v][i];
    if (u == p) continue;
    int r = efs(u,tv,v);
    if (r != -1) {
      used[v] = 1;
      return r+1;
    }
  }
  return -1;
}

vi s;
int dfs(int v, int p=-1) {
  vi x;
  rep(i,sz(to[v])) {
    int u = to[v][i];
    if (u == p || used[u]) continue;
    int r = dfs(u,v);
    x.pb(r);
  }
  if (sz(x) == 0) return 1;
  sort(rng(x));
  int res = x.back(); x.pop_back();
  s.insert(s.end(),rng(x));
  return res+1;
}


int main() {
  int n;
  scanf("%d",&n);
  rep(i,n-1) {
    int a,b;
    scanf("%d%d",&a,&b);
    --a; --b;
    to[a].pb(b);
    to[b].pb(a);
  }
  vi ans;
  ans.pb(1);
  int v = pfs(0).se;
  int u = pfs(v).se;
  ans.pb(efs(u,v));
  rep(i,n) {
    if (!used[i]) continue;
    int x = dfs(i)-1;
    if (x) s.pb(x);
  }
  sort(rng(s));
  while (sz(s)) {
    ans.pb(ans.back()+s.back());
    s.pop_back();
  }
  while (sz(ans) < n) ans.pb(n);
  cout<<ans<<endl;
  return 0;
}