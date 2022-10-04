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
int popcount(ll x){return __builtin_popcountll(x);};
int poplow(ll x){return __builtin_ctzll(x);};
int pophigh(ll x){return 63 - __builtin_clzll(x);};
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
struct BiUnionFind:UnionFind{
  ll n;
  BiUnionFind(ll n):n(n),UnionFind(2*n){

  }
  bool unite(ll x,ll y,bool t){
    if(find(x,y+n*t))return false;
    else{
      UnionFind::unite(x,y+n*!t);
      UnionFind::unite(x+n,y+n*t);
      return true;
    }
  }
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n,m,k;cin>>n>>m>>k;
  map<P,vector<P>>mp;
  vector<vector<ll>>g(n);
  vector<ll>c(n);
  rep(i,0,n)cin>>c[i],c[i]--;
  rep(i,0,m){
    ll a,b;cin>>a>>b;a--;b--;
    if(c[a]==c[b]){
      g[a].PB(b);
      g[b].PB(a);
    }
    else{
      auto p=minmax(c[a],c[b]);
      mp[p].EB(a,b);
    }
  }
  vector<ll>col(n,-1),root(n,-1);
  vector<bool>nibu(k,true);
  rep(i,0,n){
    if(col[i]!=-1)continue;
    auto dfs=[&](auto &&f,ll pos,ll x)->void{
      col[pos]=x;
      root[pos]=i;
      for(auto to:g[pos]){
        if(col[to]!=-1&&col[to]==x)nibu[c[i]]=false;
        if(col[to]!=-1)continue;
        f(f,to,x^1);
      }
    };
    dfs(dfs,i,0);
  }
  res=k*(k-1)/2;
  ll ng=0;
  rep(i,0,k){
    if(!nibu[i]){
      res-=k-ng-1;
      ng++;
    }
  }
  for(auto z:mp){
    if(!nibu[z.fi.fi]||!nibu[z.fi.se])continue;
    BiUnionFind uf(2*z.se.size());
    map<ll,ll>idx;
    ll cnt=0;
    bool sw=false;
    for(auto e:z.se){
      P r(root[e.fi],root[e.se]);
      for(auto v:{r.fi,r.se}){
        if(!idx.count(v)){
          idx[v]=cnt++;
        }
      }
      if(!uf.unite(idx[r.fi],idx[r.se],col[e.fi]^col[e.se]))sw=true;
    }
    res-=sw;
  }
  cout<<res<<endl;
  return 0;
}