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
vector<ll>divisor_enum(ll n){
  vector<ll>ret;
  for(ll i=1;i*i<=n;i++){
    if(n%i==0){
      if(i*i==n)ret.PB(i);
      else{
        ret.PB(i);
        ret.PB(n/i);
      }
    }
  }
  return ret;
}
map<ll,ll> factoring(ll n){ 
  ll buf=n;
  map<ll,ll>ret;
  ll i,j;
  for(i=2;buf!=1&&i*i<=n;i++){
    for(j=0;buf%i==0;j++){
      buf/=i;
    }
    if(j>0)ret.emplace(i,j);
  }
  if(buf!=1)ret.emplace(buf,1);
  return ret;
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll T;cin>>T;
  while(T--){
    ll n;cin>>n;
    auto d=divisor_enum(n);
    rep(i,0,d.size()){
      if(d[i]==1)d.erase(d.begin()+i);
    }
    auto mp=factoring(n);
    vector<ll>p;
    for(auto z:mp)p.PB(z.fi);
    vector<ll>ret;
    if(p.size()==1){
      ret=d;
    }
    else if(p.size()==2){
      ll k=p[0]*p[1];
      vector<ll>s;
      vector<ll>p0,p1;
      for(auto z:d){
        if(z%k==0)s.PB(z);
        else if(z%p[0]==0)p0.PB(z);
        else p1.PB(z);
      }
      for(auto z:p0)ret.PB(z);
      if(!s.empty())ret.PB(s[0]);
      for(auto z:p1)ret.PB(z);
      rep(i,1,s.size())ret.PB(s[i]);
    }
    else{
      ll sz=p.size();
      ll ds=d.size();
      vector<bool>t(ds);
      set<ll>st;
      rep(i,0,sz)st.insert(p[i]*p[(i+1)%sz]);
      rep(i,0,ds)if(st.count(d[i]))t[i]=true;
      rep(i,0,sz){
        rep(j,0,ds){
          if(t[j])continue;
          if(d[j]%p[i]==0){
            ret.PB(d[j]);
            t[j]=true;
          }
        }
        ret.PB((p[i]*p[(i+1)%sz]));
      }
    }
    ll ds=ret.size();
    ll cnt=0;
    rep(i,0,ds){
      if(gcd(ret[i],ret[(i+1)%ds])==1)cnt++;
    }
    debug(ret,ret.size());
    cout<<cnt<<endl;
  }
  return 0;
}