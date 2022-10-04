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
template<typename T> using PQ = priority_queue<T>;
template<typename T> using QP = priority_queue<T,vector<T>,greater<T>>;
template<typename T1, typename T2>bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
template<typename T1, typename T2>bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
ll median(ll a,ll b, ll c){return a+b+c-max({a,b,c})-min({a,b,c});}
void ans1(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}
void ans2(bool x){if(x) cout<<"YES"<<endl;else cout<<"NO"<<endl;}
void ans3(bool x){if(x) cout<<"Yay!"<<endl;else cout<<":("<<endl;}
template<typename T1,typename T2>void ans(bool x,T1 y,T2 z){if(x)cout<<y<<endl;else cout<<z<<endl;}  
template<typename T>void debug(const T &v,ll h,ll w,string sv=" "){for(ll i=0;i<h;i++){cout<<v[i][0];for(ll j=1;j<w;j++)cout<<sv<<v[i][j];cout<<endl;}};
template<typename T>void debug(const T &v,ll n,string sv=" "){if(n!=0)cout<<v[0];for(ll i=1;i<n;i++)cout<<sv<<v[i];cout<<endl;};
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
template<typename Head, typename... Tail>void rearrange(vector<int>&ord,Head&& head, Tail&&... tail){
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
template<typename T>T min(const vector<T>&v){return *min_element(v.begin(),v.end());}
template<typename T>T max(const vector<T>&v){return *max_element(v.begin(),v.end());}
template<typename T>T reverse(const T &v){return T(v.rbegin(),v.rend());};
//mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
int popcount(ll x){return __builtin_popcountll(x);};
int poplow(ll x){return __builtin_ctzll(x);};
int pophigh(ll x){return 63 - __builtin_clzll(x);};
template<typename T>T poll(queue<T> &q){auto ret=q.front();q.pop();return ret;};
template<typename T>T poll(priority_queue<T> &q){auto ret=q.top();q.pop();return ret;};
template<typename T>T poll(QP<T> &q){auto ret=q.top();q.pop();return ret;};
template<typename T>T poll(stack<T> &s){auto ret=s.top();s.pop();return ret;};
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
template<typename T>
struct Doubling
{
  const ll LOG = 21;
  vector< vector< T > > table;
  
  Doubling(ll sz)
  {
    table.assign(LOG, vector< T >(sz, -1));
  }

  void set_next(ll k, T x)
  {
    table[0][k] = x;
  }

  void build()
  {
    for(ll k = 0; k + 1 < LOG; k++) {
      for(ll i = 0; i < table[k].size(); i++) {
        if(table[k][i] == -1) table[k + 1][i] = -1;
        else table[k + 1][i] = table[k][table[k][i]];
      }
    }
  }
  ll query1(ll k, ll t)//t
  {
    ll ret = 1;
    for(ll i = LOG - 1; i >= 0; i--){
      if(table[i][k] != -1 && table[i][k] < t){
        ret += 1 << i;
        k = table[i][k];
      }
    }
    if(table[0][k] >= t)return ret;
    else return -1;
  }
  ll query2(ll k, ll t)//t
  {
    for(ll i = LOG - 1; i >= 0; i--) {
      if((t >> i) & 1) k = table[i][k];
    }
    return k;
  }
};
//maxa=10^7150ms,78MB10^81800ms,780MB
struct osa_k{
  ll maxa;
  vector<ll>data;//data[i]:i
  osa_k(ll a):maxa(a){
    data.assign(maxa+1,1LL);
    build();
  }
  void build(){
    for(ll i=0;i<=maxa;i++)data[i] = i;
    for(ll i=2;i*i<=maxa;i++){
      if(data[i] < i)continue;
      for(ll j=i*i;j<=maxa;j+=i){
        if(data[j] == j)data[j] = i;
      }
    }
  }
  bool isPrime(ll x){
    return (x >= 2)&&(data[x] == x);
  }
  map<ll,ll>factoring(ll x){
    map<ll,ll>ret;
    while(x > 1){
      ret[data[x]]++;
      x /= data[x];
    }
    return ret;
  }
  vector<ll>divisor_enum(ll x){
    auto v = factoring(x);
    vector<ll>ret;
    ret.push_back(1);
    for(auto z:v){
      ll sz = ret.size();
      ll tmp = z.fi;
      for(ll i=0;i<z.se;i++){
        for(ll j=0;j<sz;j++){
          ret.push_back(ret[j] * tmp);
        }
        tmp *= z.fi;
      }
    }
    sort(ret.begin(),ret.end());//ok
    return ret;
  }
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  osa_k osak(200005);
  ll n,q;cin>>n>>q;
  vector<ll>a(n);
  rep(i,0,n)cin>>a[i];
  map<ll,ll>mp;
  Doubling<int>db(n+1);
  db.set_next(n,n);
  ll mi=n;
  rrep(i,0,n){
    auto f=osak.factoring(a[i]);
    for(auto z:f){
      if(mp.count(z.fi))chmin(mi,mp[z.fi]);
      mp[z.fi]=i;
    }
    db.set_next(i,mi);
  }
  db.build();
  //debug(db.table[0],n+1);
  while(q--){
    ll l,r;cin>>l>>r;l--;
    cout<<db.query1(l,r)<<endl;
  }
  return 0;
}