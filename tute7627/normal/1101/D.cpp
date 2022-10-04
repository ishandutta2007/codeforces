#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ALL(a)  (a).begin(),(a).end()
#define ALLR(a)  (a).rbegin(),(a).rend()
#define spa << " " <<
#define test cout<<"test"<<endl;
#define fi first
#define se second
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define rep(i,n,m) for(ll i = n; i < (ll)(m); i++)
#define rrep(i,n,m) for(ll i = m - 1; i >= (ll)(n); i--)
using ll = int;
using ld = long double;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const ll INF = 1e9;
using P = pair<ll, ll>;
template<typename T>
void chmin(T &a,T b){if(a>b)a=b;}
template<typename T>
void chmax(T &a,T b){if(a<b)a=b;}
void pmod(ll &a,ll b){a=(a+b)%MOD;}
void pmod(ll &a,ll b,ll c){a=(b+c)%MOD;}
void qmod(ll &a,ll b){a=(a*b)%MOD;}
void qmod(ll &a,ll b,ll c){a=(b*c)%MOD;}
ll median(ll a,ll b, ll c){return a+b+c-max({a,b,c})-min({a,b,c});}
void ans1(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}
void ans2(bool x){if(x) cout<<"YES"<<endl;else cout<<"NO"<<endl;}
void ans3(bool x){if(x) cout<<"Yay!"<<endl;else cout<<":("<<endl;}
template<typename T1,typename T2>
void ans(bool x,T1 y,T2 z){if(x)cout<<y<<endl;else cout<<z<<endl;}  
template<typename T>
void debug(vector<vector<T>>&v,ll h,ll w){for(ll i=0;i<h;i++)
{cout<<v[i][0];for(ll j=1;j<w;j++)cout spa v[i][j];cout<<endl;}};
void debug(vector<string>&v,ll h,ll w){for(ll i=0;i<h;i++)
{for(ll j=0;j<w;j++)cout<<v[i][j];cout<<endl;}};
template<typename T>
void debug(vector<T>&v,ll n){if(n!=0)cout<<v[0];
for(ll i=1;i<n;i++)cout spa v[i];cout<<endl;};
template<typename T>
vector<vector<T>>vec(ll x, ll y, T w){
  vector<vector<T>>v(x,vector<T>(y,w));return v;}
ll gcd(ll x,ll y){ll r;while(y!=0&&(r=x%y)!=0){x=y;y=r;}return y==0?x:y;}
vector<ll>dx={1,0,-1,0,1,1,-1,-1};
vector<ll>dy={0,1,0,-1,1,-1,1,-1};
template<typename T>
vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
template<typename... Ts>
auto make_v(size_t a,Ts... ts){
  return vector<decltype(make_v(ts...))>(a,make_v(ts...));
}

ll MAX_V = 2e5 + 5;
P maxdepth;
vector<ll>t(MAX_V);//
void dfs(ll k, vector<vector<ll>>&g, ll d){
  t[k]=1;
  chmax(maxdepth,MP(d,k));
  for(ll i=0;i<g[k].size();i++){
    if(t[g[k][i]]==0){
      dfs(g[k][i],g, d+1); 
    }
  }
}
vector<ll>t2(MAX_V);//
void dfs2(ll k, vector<vector<ll>>&g, ll d){
  t2[k]=1;
  chmax(maxdepth,MP(d,k));
  for(ll i=0;i<g[k].size();i++){
    if(t2[g[k][i]]==0){
      dfs2(g[k][i],g, d+1); 
    }
  }
}
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
      ret.emplace(data[x],0).first->second++;
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
  //cout<<fixed<<setprecision(10);
  ll res=0,buf=0;
  bool judge = true;
  ll n;cin>>n;
  vector<ll>a(n);
  rep(i,0,n)cin>>a[i];
  vector<ll>u(n-1),v(n-1);
  vector<vector<ll>>G(n);
  rep(i,0,n-1){
    cin>>u[i]>>v[i];
    u[i]--;v[i]--;
    G[u[i]].PB(v[i]);
    G[v[i]].PB(u[i]);
  }
  struct osa_k osak(200001);
  vector<vector<ll>>p(200001);
  rep(i,0,n){
    auto mp=osak.factoring(a[i]);
    for(auto z:mp)p[z.fi].PB(i);
  }
  rep(i,2,200001){
    if(p[i].size()==0)continue;
    if(p[i].size()==1){
      chmax(res,1);
      continue;
    }
    //cout<<i<<endl;
    unordered_map<ll,ll>idx;
    rep(j,0,p[i].size())idx[p[i][j]]=j;
    vector<vector<ll>>g(p[i].size());
    rep(j,0,p[i].size()){
      rep(o,0,G[p[i][j]].size()){
        if(a[G[p[i][j]][o]]%i==0){
          g[j].PB(idx[G[p[i][j]][o]]);
          g[idx[G[p[i][j]][o]]].PB(j);
        }
      }
    }
    rep(j,0,p[i].size()){
      t[j]=0;
      t2[j]=0;
    }
    rep(j,0,p[i].size()){  
      //cout<<i spa j<<endl;
      if(t[j])continue;
      //cout<<i spa j spa p[i][j]<<endl;
      maxdepth=MP(0,-1);
      dfs(j,g,1);
      auto tmp=maxdepth.se;
      maxdepth=MP(0,-1);
      dfs2(tmp,g,1);
      chmax(res,maxdepth.fi);
    }
  }
  cout<<res<<endl;
  return 0;
}