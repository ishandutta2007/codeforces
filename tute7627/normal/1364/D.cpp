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
template<typename T1, typename T2>
bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
template<typename T1, typename T2>
bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
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
vector<ll>dx={1,-1,0,0,1,1,-1,-1};
vector<ll>dy={0,0,1,-1,1,-1,1,-1};
template<typename T>
vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
template<typename... Ts>
auto make_v(size_t a,Ts... ts){
  return vector<decltype(make_v(ts...))>(a,make_v(ts...));
}
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2>&p){
  return os << p.first << " " << p.second;
}
//mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n,m,k;cin>>n>>m>>k;
  vector<vector<ll>>g(n);
  rep(i,0,m){
    ll u,v;cin>>u>>v;u--;v--;
    g[u].PB(v);
    g[v].PB(u);
  }
  if(m==n-1){
    vector<ll>d(n);
    rep(i,0,n)d[i]=g[i].size();
    queue<ll>que;
    vector<ll>ret;
    rep(i,0,n)if(d[i]==1)que.push(i);
    vector<bool>used(n);
    while(!que.empty()){
      auto p=que.front();
      que.pop();
      for(auto to:g[p]){
        d[to]--;
        if(d[to]==1)que.push(to);
      }
      if(used[p])continue;
      ret.PB(p+1);
      used[p]=true;
      for(auto to:g[p])used[to]=true;
    }
    cout<<1<<endl;
    debug(ret,(k+1)/2);
    return 0;
  }
  vector<ll>ret;
  {
    vector<ll>v;
    vector<bool>used(n);
    auto dfs=[&](auto &&f,ll k,ll par)->void{
      used[k]=true;
      v.push_back(k);
      for(auto to:g[k]){
        if(!ret.empty())return;
        if(to==par)continue;
        if(used[to]){
          //cout<<k spa to<<endl;
          for(auto z:v){
            //cout<<z<<endl;
            if(to==z||!ret.empty())ret.PB(z+1);
          }
          return;
        }
      }
      for(auto to:g[k]){
        if(!ret.empty())return;
        if(to==par)continue;
        f(f,to,k);
      }
      v.pop_back();
    };
    dfs(dfs,0,-1);
  }
  if(ret.size()<=k){
    cout<<2<<endl;
    cout<<ret.size()<<endl;
    debug(ret,ret.size());
  }
  else{
    vector<ll>ret2;
    rep(i,0,ret.size()){
      if(i%2==0&&i+1!=ret.size())ret2.PB(ret[i]);
    }
    cout<<1<<endl;
    debug(ret2,(k+1)/2);
  }
  return 0;
}