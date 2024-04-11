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
template<typename T>void rearrange(vector<ll>&ord, vector<T>&v){
  auto tmp = v;
  for(int i=0;i<tmp.size();i++)v[i] = tmp[ord[i]];
}
template<typename Head, typename... Tail>void rearrange(vector<ll>&ord,Head&& head, Tail&&... tail){
  rearrange(ord, head);
  rearrange(ord, tail...);
}
//mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
int popcount(ll x){return __builtin_popcountll(x);};
int poplow(ll x){return __builtin_ctzll(x);};
int pophigh(ll x){return 63 - __builtin_clzll(x);};
struct SCC{
  int n;
  const vector<vector<int>>&G;
  vector<int>index;//
  vector<int>start,visited,low,ord;
  int now_ord,group_num;
  SCC(const vector<vector<int>>&g):G(g),n(g.size()){
    index.assign(n,-1LL);
    build();
  }
  void build(){
    low.assign(n,0);ord.assign(n,-1);index.assign(n,0);
    visited.reserve(n);
    now_ord=0,group_num=0;
    for(int i=0;i<n;i++){
      if(ord[i]==-1)dfs(i);
    }
    for(auto& x:index)x=group_num-1-x;
  }
  void dfs(int v){
    low[v]=ord[v]=now_ord++;
    visited.push_back(v);
    for(auto to:G[v]){
      if(ord[to]==-1){
        dfs(to);
        low[v]=min(low[v],low[to]);
      }
      else{
        low[v]=min(low[v],ord[to]);
      }
    }
    if(low[v]==ord[v]){
      while(1){
        int u=visited.back();
        visited.pop_back();
        ord[u]=n;
        index[u]=group_num;
        if(u==v)break;
      }
      group_num++;
    }

  }
  vector<vector<int>>edges;
  void build_edges(){
    edges.assign(*max_element(ALL(index))+1,vector<int>());
    for(ll i=0;i<n;i++){
      for(ll j=0;j<G[i].size();j++){
        if(index[i]!=index[G[i][j]]){
          edges[index[i]].push_back(index[G[i][j]]);
        }
      }
    }
  }
  vector<int>output(){return index;};
};

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n;cin>>n;
  vector<ll>k(n);
  rep(i,0,n)cin>>k[i];
  ll sz=8*9*5*7;
  //ll sz=12;
  vector<vector<int>>g(n*sz);
  rep(i,0,n){
    int m;cin>>m;
    vector<int>to(m);
    rep(j,0,m){
      cin>>to[j];to[j]--;
    }
    rep(j,0,sz){
      ll tm=((j+k[i])%sz+sz)%sz;
      g[i*sz+j].PB(to[tm%m]*sz+tm);
    }
  }
  SCC scc(g);
  auto &idx=scc.index;
  scc.build_edges();
  int mx=*max_element(ALL(idx))+1;
  vector<vector<int>>comp(mx);
  rep(i,0,n*sz)comp[idx[i]].PB(i/sz);
  vector<int>dp(mx);
  vector<bool>used(n);
  rep(i,0,mx){
    queue<int>que;
    for(auto z:comp[i]){
      if(!used[z]){
        que.push(z);
        used[z]=true;
        dp[i]++;
      }
    }
    while(!que.empty()){
      used[que.front()]=false;
      que.pop();
    }
  }
  //debug(dp,dp.size());
  rrep(i,0,mx){
    for(auto to:scc.edges[i])dp[i]=dp[to];
  }
  //debug(dp,dp.size());
  ll q;cin>>q;
  while(q--){
    ll x,y;cin>>x>>y;x--;
    y=(y%sz+sz)%sz;
    //cout<<x spa y<<endl;
    cout<<dp[idx[x*sz+y]]<<endl;
  }
  return 0;
}