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

// Fraction
struct frac {
  ll a, b;
  frac(ll a=0, ll b=1){
    ll x = gcd(abs(a),abs(b));
    if (b < 0) x = -x;
    this->a = a/x;
    this->b = b/x;
  }
  ll gcd(ll x, ll y) { return y?gcd(y,x%y):x;}
  // frac inv() { return frac(b,a);}
  frac operator+(frac x) { return frac(a*x.b + x.a*b, b*x.b);}
  frac operator-(frac x) { return frac(a*x.b - x.a*b, b*x.b);}
  frac operator*(frac x) { return frac(a*x.a, b*x.b);}
  frac operator/(frac x) { return frac(a*x.b, b*x.a);}
  bool operator<(const frac& x)const {return a*x.b < x.a*b;}
};
//



int main() {
  int n;
  scanf("%d",&n);
  map<frac,int> s;
  v(frac) x;
  rep(i,n) {
    int a,b,c;
    // scanf("(%d+%d)/%d",&a,&b,&c);
    string t;
    cin>>t;
    a = b = c = 0;
    int mode = 0;
    for (char e : t) {
      if (mode == 0) {
        if (e == '(') continue;
        if (e == '+') mode = 1;
        else a = a*10+(e-'0');
      } else if (mode == 1) {
        if (e == ')') continue;
        if (e == '/') mode = 2;
        else b = b*10+(e-'0');
      } else {
        c = c*10+(e-'0');
      }
    }
    x.pb(frac(a+b,c));
    s[x[i]]++;
  }
  vi ans;
  rep(i,n) ans.pb(s[x[i]]);
  cout<<ans<<endl;
  return 0;
}