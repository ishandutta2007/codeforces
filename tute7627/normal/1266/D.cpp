#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define lfs cout<<fixed<<setprecision(10)
#define ALL(a)  (a).begin(),(a).end()
#define ALLR(a)  (a).rbegin(),(a).rend()
#define spa << " " <<
#define test cout<<"test"<<endl;
#define fi first
#define se second
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define rep(i,n,m) for(ll i = (n); i < (ll)(m); i++)
#define rrep(i,n,m) for(ll i = (m) - 1; i >= (ll)(n); i--)
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
ostream &operator<<(ostream &os, pair<ll, ll>&p){
  return os << p.first << " " << p.second;
}  
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n,m;cin>>n>>m;
  vector<ll>cost(n);
  vector<tuple<ll,ll,ll>>e;
  vector<vector<ll>>in(n),out(n);
  rep(i,0,m){
    ll u,v,d;cin>>u>>v>>d;
    u--;v--;
    cost[v]+=d;
    e.EB(u,v,d);
    in[v].PB(i);
    out[u].PB(i);
  }
  rep(i,0,n){
    ll idx=0;
    rep(j,0,out[i].size()){
      ll u,v,d;
      tie(u,v,d)=e[out[i][j]];
      while(d>0&&idx<in[i].size()){
      //cout<<u spa v spa d<<endl;
        ll u2,v2,d2;
        tie(u2,v2,d2)=e[in[i][idx]];
        ll mi=min(d,d2);
        e[in[i][idx]]={u2,v2,d2-mi};
        d-=mi;
        if(mi>0&&v!=u2){
          in[v].EB(e.size());
          out[u2].EB(e.size());
          e.EB(u2,v,mi);
        }
        if(d2==mi)idx++;
      //cout<<u spa v spa d spa u2 spa v2 spa d2<<endl;
      }
      e[out[i][j]]={u,v,d};
    }
  }
  ll mx=0;
  vector<map<ll,ll>>mp(n);
  rep(i,0,e.size()){
    ll u,v,d;
      tie(u,v,d)=e[i];
      if(u!=v&&d>0){
        if(!mp[u].count(v))mx++;
        mp[u][v]+=d;
      }
  }
  cout<<mx<<endl;
  /*rep(i,0,mp.size()){
    ll u,v,d;
      tie(u,v,d)=e[i];
      //cout<<u+1 spa v+1 spa i spa d<<endl;
    if(d>0&&u!=v){
      cout<<u+1 spa v+1 spa d<<endl;
    }
  }*/
  rep(i,0,n)for(auto z:mp[i]){
    cout<<i+1 spa z.fi+1 spa z.se<<endl;
  }
  return 0;
}