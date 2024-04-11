//#define _GLIBCXX_DEBUG

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define lfs cout<<fixed<<setprecision(10)
#define ALL(a)  (a).begin(),(a).end()
#define ALLR(a)  (a).rbegin(),(a).rend()
#define spa << " " <<
#define fi first
#define se second
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define EB emplace_back
#define rep(i,n,m) for(ll i = (n); i < (ll)(m); i++)
#define rrep(i,n,m) for(ll i = (ll)(m) - 1; i >= (ll)(n); i--)
using ll = long long;
using ld = long double;
const ll MOD1 = 1e9+7;
const ll MOD9 = 998244353;
const ll INF = 1e18;
using P = pair<ll, ll>;
template<typename T1, typename T2>bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
template<typename T1, typename T2>bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
ll median(ll a,ll b, ll c){return a+b+c-max({a,b,c})-min({a,b,c});}
void ans1(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}
void ans2(bool x){if(x) cout<<"YES"<<endl;else cout<<"NO"<<endl;}
void ans3(bool x){if(x) cout<<"Yay!"<<endl;else cout<<":("<<endl;}
template<typename T1,typename T2>void ans(bool x,T1 y,T2 z){if(x)cout<<y<<endl;else cout<<z<<endl;}  
template<typename T>void debug(vector<vector<T>>&v,ll h,ll w){for(ll i=0;i<h;i++){cout<<v[i][0];for(ll j=1;j<w;j++)cout spa v[i][j];cout<<endl;}};
void debug(vector<string>&v,ll h,ll w){for(ll i=0;i<h;i++){for(ll j=0;j<w;j++)cout<<v[i][j];cout<<endl;}};
template<typename T>void debug(vector<T>&v,ll n){if(n!=0)cout<<v[0];for(ll i=1;i<n;i++)cout spa v[i];cout<<endl;};
template<typename T>vector<vector<T>>vec(ll x, ll y, T w){vector<vector<T>>v(x,vector<T>(y,w));return v;}
ll gcd(ll x,ll y){ll r;while(y!=0&&(r=x%y)!=0){x=y;y=r;}return y==0?x:y;}
vector<ll>dx={1,-1,0,0,1,1,-1,-1};vector<ll>dy={0,0,1,-1,1,-1,1,-1};
template<typename T>vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
template<typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v(ts...))>(a,make_v(ts...));}
template<typename T1, typename T2>ostream &operator<<(ostream &os, const pair<T1, T2>&p){return os << p.first << " " << p.second;}
template<typename T>ostream &operator<<(ostream &os, const vector<T> &v){for(auto &z:v)os << z << " ";cout<<"|"; return os;}
//mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
struct UnionFind {
  vector<ll> data;
  ll num;
  UnionFind(ll size) : data(size, -1) ,num(size){ }
  bool unite(ll x, ll y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
	  num--;
    }
    return x != y;
  }
  bool find(ll x, ll y) {
    return root(x) == root(y);
  }
  ll root(ll x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  ll size(ll x) {
    return -data[root(x)];
  }
};
template<typename T>
map<T,ll> compress(vector<T> &v){
  sort(ALL(v));
  v.erase(unique(ALL(v)),v.end());
  map<T, ll> ret;
  for(ll i=0;i<(ll)v.size();i++)
    ret[v[i]]=i;
  return ret;
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n;cin>>n;
  vector<ll>x(n),y(n),vx,vy;
  rep(i,0,n){
    cin>>x[i]>>y[i];
    vx.PB(x[i]);
    vy.PB(y[i]);
  }
  auto mx=compress(vx);
  auto my=compress(vy);
  ll sx=mx.size(),sy=my.size();
  auto v=make_v(4,sx,sy,-1);
  rep(i,0,n){
    ll xi=mx[x[i]];
    ll yi=my[y[i]];
    rep(j,0,4){
      v[j][xi][yi]=i;
    }
  }
  rep(i,0,sx){
    rep(j,0,sy-1)if(v[0][i][j+1]==-1)v[0][i][j+1]=v[0][i][j];
    rrep(j,0,sy-1)if(v[1][i][j]==-1)v[1][i][j]=v[1][i][j+1];
  }
  rep(j,0,sy){
    rep(i,0,sx-1)if(v[2][i+1][j]==-1)v[2][i+1][j]=v[2][i][j];
    rrep(i,0,sx-1)if(v[3][i][j]==-1)v[3][i][j]=v[3][i+1][j];
  }
  const ll inf=3e9;
  ll ok=inf,ng=-1;
  while(ok-ng>=2){
    UnionFind uf(n);
    ll mid=(ok+ng)/2;
    rep(i,0,n)rep(j,i+1,n){
      if(x[i]==x[j]&&abs(y[i]-y[j])<=mid)uf.unite(i,j);
      else if(y[i]==y[j]&&abs(x[i]-x[j])<=mid)uf.unite(i,j);
    }
    bool sw=false;
    rep(i,0,sx)rep(j,0,sy){
      set<ll>st;
      rep(o,0,4){
        ll to=v[o][i][j];
        if(to==-1)continue;
        if(vx[i]==x[to]&&abs(vy[j]-y[to])<=mid)st.insert(uf.root(to));
        if(vy[j]==y[to]&&abs(vx[i]-x[to])<=mid)st.insert(uf.root(to));
      }
      if(st.size()==uf.num)sw=true;
    }
    if(uf.num==2){
      rep(i,0,n)rep(j,i+1,n){
        if(x[i]!=x[j]&&y[i]!=y[j])continue;
        if(uf.find(i,j))continue;
        if(abs(x[i]-x[j])+abs(y[i]-y[j])<=mid*2)sw=true;
      }
    }
    if(sw)ok=mid;
    else ng=mid;
  }
  ans(ok==inf,-1,ok);
  return 0;
}