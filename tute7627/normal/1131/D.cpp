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
using ll = long long;
using ld = long double;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const ll INF = 1e18;
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
struct SCC{
  ll n;
  vector<vector<ll>>G,Gr;
  vector<ll>index;//
  vector<ll>ret;//dfs
  SCC(vector<vector<ll>>g):G(g),n(g.size()){
    index.assign(n,-1LL);
    build();
  }
  void build(){
    Gr.assign(n,vector<ll>());
    for(ll i=0;i<n;i++){
      for(ll j=0;j<G[i].size();j++){
        Gr[G[i][j]].push_back(i);
      }
    }
    for(ll i=0;i<n;i++)if(index[i]==-1)dfs1(i);
    fill(ALL(index),-1);
    ll cnt=0;
    reverse(ALL(ret));
    for(ll i=0;i<n;i++){
      if(index[ret[i]]==-1){
        dfs2(ret[i],cnt);
        cnt++;
      }
    }
  }
  void dfs1(ll k){
    index[k]=1;
    for(ll i=0;i<G[k].size();i++){
      if(index[G[k][i]]==-1)dfs1(G[k][i]);
    }
    ret.push_back(k);
  }
  void dfs2(ll k, ll idx){
    index[k]=idx;
    for(ll i=0;i<Gr[k].size();i++){
      if(index[Gr[k][i]]==-1)dfs2(Gr[k][i],idx);
    }
  }
  vector<ll>output(){return index;};
};


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  //cout<<fixed<<setprecision(10);
  ll res=0,buf=0;
  bool judge = true;
  ll n,m;cin>>n>>m;
  vector<string>s(n);
  rep(i,0,n)cin>>s[i];
  vector<vector<ll>>g(n+m);
  rep(i,0,n)rep(j,0,m){
    if(s[i][j]=='<'||s[i][j]=='=')g[i].PB(n+j);
    if(s[i][j]=='>'||s[i][j]=='=')g[n+j].PB(i);
  }
  SCC scc(g);
  auto v=scc.output();
  //debug(v,n+m);
  rep(i,0,n)rep(j,0,m){
    if(s[i][j]=='<'&&v[i]>=v[n+j])judge=false;
    if(s[i][j]=='>'&&v[i]<=v[n+j])judge=false;
    if(s[i][j]=='='&&v[i]!=v[n+j])judge=false;
  }
  ans1(judge);
  if(judge){
    vector<P>a(n+m);
    
    rep(i,0,n+m){
      a[i]=MP(v[i],i);
    }
    sort(ALL(a));
    ll cnt=0,pos1=0,pos2=0;
    bool judge1=false,judge2=false;
    rep(i,0,n+m){
      bool judgebuf=true;
      if(!judge1&&!judge2)judgebuf=false;
      pos2=pos1;
      while(a[pos1].fi==i){
        if(a[pos1].se<n)judge1=true;
        else judge2=true;
        pos1++;
      }
      if(judge1&&judge2){
        if(judgebuf)cnt++;
        judge1=false;judge2=false;
      }
      while(a[pos2].fi==i){
        if(a[pos2].se<n)judge1=true;
        else judge2=true;
        v[a[pos2].se]=cnt;
        pos2++;
      }
    }
    rep(i,0,n){
      if(i!=0)cout<<" ";
      cout<<v[i]+1;
    }
    cout<<endl;
    rep(i,n,n+m){
      if(i!=n)cout<<" ";
      cout<<v[i]+1;
    }
    cout<<endl;
  }
  return 0;
}