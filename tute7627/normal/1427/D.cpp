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

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n;cin>>n;
  vector<ll>a(n);
  rep(i,0,n)cin>>a[i];
  vector<vector<ll>>ret;
  auto ope=[&](vector<ll>v){
    ret.PB(vector<ll>());
    //return;
    ll sz=ret.size();
    ret[sz-1].PB(v.size());
    for(auto z:v)ret[sz-1].PB(z);
    vector<vector<ll>>tmp(v.size());
    ll idx=0;
    rep(i,0,v.size()){
      while(v[i]--){
        tmp[i].PB(a[idx++]);
      }
    }
    //cout<<tmp<<endl;
    reverse(ALL(tmp));
    //cout<<tmp<<endl;
    a.clear();
    for(auto zz:tmp)for(auto z:zz)a.PB(z);
    //debug(a,n);
  };
  while(1){
    ll rev=0;
    ll idx=0;
    rep(i,0,n)if(a[i]==1)idx=i;
    ll xr=idx,yr=idx;
    while(xr>0&&idx-xr+2==a[xr-1])xr--;
    while(yr<n-1&&yr-idx+2==a[yr+1])yr++;
    if(abs(xr-idx)>abs(yr-idx))rev=1;
    //cout<<idx spa xr spa yr<<endl;
    if(idx==0&&yr==n-1)break;
    if(idx==n-1&&xr==0){
      vector<ll>tmp(n,1);
      ope(tmp);
      break;
    }
    vector<ll>in;
    if(rev){
      ll nxt=idx-xr+2;
      ll to=0;
      rep(i,0,n){
        if(a[i]==nxt)to=i;
      }
      if(to<xr){
        rep(i,0,to)in.PB(1);
        in.PB(xr-to);
        rep(i,xr,n)in.PB(1);
      }
      else{
        //cout<<"test"<<endl;
        rep(i,0,xr)in.PB(1);
        in.PB(idx-xr+1);
        in.PB(to-idx);
        rep(i,to+1,n)in.PB(1);
      }
    }
    else{
      ll nxt=yr-idx+2;
      ll to=0;
      rep(i,0,n){
        if(a[i]==nxt)to=i;
      }
      //cout<<nxt spa to<<endl;
      if(to>yr){
        rep(i,0,yr+1)in.PB(1);
        in.PB(to-yr);
        rep(i,to+1,n)in.PB(1);
      }
      else{
        rep(i,0,to)in.PB(1);
        in.PB(idx-to);
        in.PB(yr-idx+1);
        rep(i,yr+1,n)in.PB(1);
      }
    }
    ope(in);
    //cout<<xr spa idx spa yr<<endl;
    //debug(in,in.size());
    //debug(a,n);
    //if(ret.size()>=5)break;
  }
  cout<<ret.size()<<endl;
  for(auto z:ret)debug(z,z.size());
  return 0;
}