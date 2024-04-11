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
template<typename T>void debug(T &v,ll h,ll w,string sv=" "){for(ll i=0;i<h;i++){cout<<v[i][0];for(ll j=1;j<w;j++)cout<<sv<<v[i][j];cout<<endl;}};
template<typename T>void debug(T &v,ll n,string sv=" "){if(n!=0)cout<<v[0];for(ll i=1;i<n;i++)cout<<sv<<v[i];cout<<endl;};
template<typename T>vector<vector<T>>vec(ll x, ll y, T w){vector<vector<T>>v(x,vector<T>(y,w));return v;}
ll gcd(ll x,ll y){ll r;while(y!=0&&(r=x%y)!=0){x=y;y=r;}return y==0?x:y;}
vector<ll>dx={1,-1,0,0,1,1,-1,-1};vector<ll>dy={0,0,1,-1,1,-1,1,-1};
template<typename T>vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
template<typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v(ts...))>(a,make_v(ts...));}
template<typename T1, typename T2>ostream &operator<<(ostream &os, const pair<T1, T2>&p){return os << p.first << " " << p.second;}
template<typename T>ostream &operator<<(ostream &os, const vector<T> &v){for(auto &z:v)os << z << " ";cout<<"|"; return os;}
template<typename T>void rearrange(vector<int>&ord, vector<T>&v){
  auto tmp = v;
  for(int i=0;i<tmp.size();i++)v[i] = tmp[ord[i]];
}
template<typename Head, typename... Tail>void rearrange(vector<ll>&ord,Head&& head, Tail&&... tail){
  rearrange(ord, head);
  rearrange(ord, tail...);
}
template<typename T> vector<int> ascend(const vector<T>&v){
  vector<int>ord(v.size());iota(ord.begin(),ord.end(),0);
  sort(ord.begin(),ord.end(),[&](int i,int j){return v[i]<v[j];});
  return ord;
}
template<typename T> vector<int> descend(const vector<T>&v){
  vector<int>ord(v.size());iota(ord.begin(),ord.end(),0);
  sort(ord.begin(),ord.end(),[&](int i,int j){return v[i]>v[j];});
  return ord;
}
ll FLOOR(ll n,ll div){return n>=0?n/div:(n-div+1)/div;}
ll CEIL(ll n,ll div){return n>=0?(n+div-1)/div:n/div;}
//mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
int popcount(ll x){return __builtin_popcountll(x);};
int poplow(ll x){return __builtin_ctzll(x);};
int pophigh(ll x){return 63 - __builtin_clzll(x);};

template< typename T = int >
struct edge {
  int to;
  T cost;
  int id;
  edge() = default;
  edge(int to, T cost = 1, int id = -1):to(to), cost(cost), id(id){}
  operator int() const { return to; }
};

template<typename T>
using Graph = vector<vector<edge<T>>>;
template<typename T>
Graph<T> readGraph(int n,int m,int indexed=1,bool directed=false,bool weighted=false){
  Graph<T> ret(n);
  for(int es = 0; es < m; es++){
    int u,v,w=1;
    cin>>u>>v;u-=indexed,v-=indexed;
    if(weighted)cin>>w;
    ret[u].emplace_back(v,w,es);
    if(!directed)ret[v].emplace_back(u,w,es);
  }
  return ret;
}
template<typename T>
Graph<T> readParent(int n,int indexed=1,bool directed=true){
  Graph<T>ret(n);
  for(int i=1;i<n;i++){
    int p;cin>>p;
    p-=indexed;
    ret[p].emplace_back(i);
    if(!directed)ret[i].emplace_back(p);
  }
  return ret;
}
using ul = unsigned long long;
template<ll mod>
struct RollingHash{
  vector<ul> hash,p;
  const ul positivizer = mod * 4;
  ul base;
  RollingHash(string s, ul b){
    ul n = (ul)s.size();
    base = b;
    hash.assign(n+1,0);
    p.assign(n+1,1);
    for(ll i=0;i<n;i++){
      hash[i+1]=calcmod(mul(hash[i],base)+s[i]);
      p[i+1]=mul(p[i],base);
    }
  }
  ul get(ll l, ll r){ //[l,r]
    return calcmod(hash[r+1] + positivizer - mul(hash[l],p[r-l+1]));
  }
  ul mul(ul a, ul b){
    ul au = a >> 31;
    ul ad = a & (1UL << 31) - 1;
    ul bu = b >> 31;
    ul bd = b & (1UL << 31) - 1;
    ul mid = ad * bu + au * bd;
    ul midu = mid >> 30;
    ul midd = mid & (1UL << 30) - 1;
    return calcmod(au * bu * 2 + midu + (midd << 31) + ad * bd);
  }
  ul calcmod(ul val){
    val = (val & mod) + (val >> 61);
    if(val >= mod) val -= mod;
    return val;
  }
  ul merge(ul x,ul y, ll len){
    return calcmod(mul(x,len)+y);
  }
};
struct RandomNumberGenerator {
  mt19937_64 mt;

  RandomNumberGenerator() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}

  ll operator()(ll a, ll b) { // [a, b)
    uniform_int_distribution< long long > dist(a, b - 1);
    return dist(mt);
  }

  ll operator()(ll b) { // [0, b)
    return (*this)(0, b);
  }
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  const unsigned long long tmp_mod = (1ULL << 61) - 1;
  RandomNumberGenerator rng;
  unsigned long long base = rng(100000,1000000);
  //unsigned long long base = 100000;
  using RH = RollingHash<tmp_mod>;
  ll n;cin>>n;
  ll sz=9;
  vector<string>s(n);
  using ull=unsigned long long;
  map<ull,ll>mp;
  rep(i,0,n){
    set<ull>st;
    cin>>s[i];
    RH rh(s[i],base);
    rep(i,0,sz)rep(j,i,sz){
      st.insert(rh.get(i,j));
    }
    for(auto z:st)mp[z]++;
  }
  auto solve=[&](ll k){
    RH rh(s[k],base);
    rep(i,0,sz)rep(j,0,sz-i){
      ll l=j,r=j+i;
      //cout<<l spa r spa rh.get(l,r) spa mp[rh.get(l,r)]<<endl;
      if(mp[rh.get(l,r)]==1){
        cout<<s[k].substr(j,i+1)<<endl;
        return;
      }
    }
  };
  rep(i,0,n)solve(i);
  return 0;
}