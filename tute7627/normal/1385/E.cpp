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
vector<ll>tsort(vector<vector<ll>>&g){
  ll n = g.size();
  vector<ll>ret(n),ret2(n);
  vector<ll>v(n);
  for(ll i=0;i<n;i++)for(ll j=0;j<g[i].size();j++)v[g[i][j]]++;
  stack<ll>st;
  for(ll i=0;i<n;i++)if(v[i]==0)st.push(i);
  for(ll i=0;i<n;i++){
    if(st.empty())return vector<ll>();//
    ll x=st.top();
    st.pop();
    ret[x]=i;
    ret2[i]=x;
    for(ll j=0;j<g[x].size();j++){
      v[g[x][j]]--;
      if(v[g[x][j]]==0)st.push(g[x][j]);
    }
  }
  //ret:ret2:
  return ret;
}
void solve(){
  ll n,m;cin>>n>>m;
  vector<vector<ll>>g(n);
  vector<P>ret;
  vector<P>cand;
  rep(i,0,m){
    ll t,x,y;cin>>t>>x>>y;x--;y--;
    if(t==0){
      cand.EB(x,y);
    }
    else{
      ret.EB(x,y);
      g[x].PB(y);
    }
  }
  auto v=tsort(g);
  if(v.empty()){
    cout<<"NO"<<endl;
    return;
  }
  cout<<"YES"<<endl;
  for(auto p:cand){
    if(v[p.fi]<v[p.se])ret.PB(p);
    else ret.EB(p.se,p.fi);
  }
  rep(i,0,m)cout<<ret[i].fi+1 spa ret[i].se+1<<endl;
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll t;cin>>t;
  while(t--){
    solve();
  }
  return 0;
}