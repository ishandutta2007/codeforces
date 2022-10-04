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
using PT=pair<bool,bool>;
PT solve(ll s,ll e){
  PT ret;
  //
  {
    if(e%2==1){
      ret.fi=!(s&1);
    }
    else{
      ll now=e+1;
      ll cnt=0;
      while(1){
        ll pre=now;
        now=(now+1)/2;
        if(s>=now){
          if(~cnt&1){
            ret.fi=!((pre-s)&1);
          }
          else ret.fi=1;
        break;
        }
        if(~now&1&&cnt&1){
          ret.fi=!((now-s)&1);
          break;
        }
        else cnt++;
      }
    }
  }
  //
  {
    if(e%4<=1){
      ll now=e+1;
      ll cnt=0;
      while(1){
        ll pre=now;
        now=(now+1)/2;
        if(s>=now){
          if(cnt&1){
            ret.se=!((pre-s)&1);
          }
          else ret.se=1;
          break;
        }
        if(~now&1&&~cnt&1){
          ret.se=!((now-s)&1);
          break;
        }
        else cnt++;
      }
    }
    else{
      if(s*2>e)ret.se=1;
      else{
        ll now=(e+2)/2;
        ret.se=!((now-s)&1);
      }
    }
  }
  return ret;
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  /*rep(i,30,42){
    cout<<i<<endl;
    rep(j,1,i+1){
      cout<<j spa solve(j,i)<<endl;
    }
  }
  return 0;*/
  ll t;cin>>t;
  vector<PT>p(t);
  rep(i,0,t){
    ll s,e;cin>>s>>e;
    p[i]=solve(s,e);
  }
  auto dp=vec(t+1,2,false);
  dp[t][0]=false,dp[t][1]=true;
  rrep(i,0,t){
    if(p[i].fi&&dp[i+1][1])dp[i][0]=true;
    if(p[i].se&&dp[i+1][0])dp[i][0]=true;
    if(!p[i].fi&&dp[i+1][1])dp[i][1]=true;
    if(!p[i].se&&dp[i+1][0])dp[i][1]=true;
  }
  P tmp;
  tmp.fi=dp[0][0];
  dp=vec(t+1,2,false);
  dp[t][0]=true,dp[t][1]=false;
  rrep(i,0,t){
    if(p[i].fi&&dp[i+1][1])dp[i][0]=true;
    if(p[i].se&&dp[i+1][0])dp[i][0]=true;
    if(!p[i].fi&&dp[i+1][1])dp[i][1]=true;
    if(!p[i].se&&dp[i+1][0])dp[i][1]=true;
  }
  tmp.se=dp[0][0];
  cout<<tmp<<endl;
  return 0;
}