//#define _GLIBCXX_DEBUG

#include<bits/stdc++.h>
using namespace std;

//#define endl '\n'
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
  ll n;cin>>n;
  ll cnt=0;
  auto ask=[&](ll x1,ll y1,ll x2,ll y2){
    cnt++;
    assert(cnt<=200);
    cout<<"?" spa x1 spa y1 spa x2 spa y2<<endl;
    ll k;cin>>k;
    return k;
  };
  vector<ll>xl(2),xr(2),yl(2),yr(2);
  {
    rep(i,0,2){
      ll ok=n,ng=0;
      while(abs(ok-ng)>=2){
        ll mid=(ok+ng)/2;
        ll k=ask(1,1,mid,n);
        if(k>i)ok=mid;
        else ng=mid;
      }
      xr[i]=ok;
      ok=n,ng=0;
      while(abs(ok-ng)>=2){
        ll mid=(ok+ng)/2;
        ll k=ask(n+1-mid,1,n,n);
        if(k>i)ok=mid;
        else ng=mid;
      }
      xl[1-i]=n+1-ok;
      ok=n,ng=0;
      while(abs(ok-ng)>=2){
        ll mid=(ok+ng)/2;
        ll k=ask(1,1,n,mid);
        if(k>i)ok=mid;
        else ng=mid;
      }
      yr[i]=ok;
      ok=n,ng=0;
      while(abs(ok-ng)>=2){
        ll mid=(ok+ng)/2;
        ll k=ask(1,n+1-mid,n,n);
        if(k>i)ok=mid;
        else ng=mid;
      }
      yl[1-i]=n+1-ok;
    }
  }
  if(xl[1]<=xr[0]&&ask(xl[1],1,xr[0],n)>=1){
    swap(xl[0],xl[1]);
  }
  if(yl[1]<=yr[0]&&ask(1,yl[1],n,yr[0])>=1){
    swap(yl[0],yl[1]);
  }
  if(ask(xl[0],yl[0],xr[0],yr[0])>=1&&ask(xl[1],yl[1],xr[1],yr[1])>=1){
    cout<<"!" spa xl[0] spa yl[0] spa xr[0] spa yr[0] spa xl[1] spa yl[1] spa xr[1] spa yr[1]<<endl;
  }
  else{
    cout<<"!" spa xl[0] spa yl[1] spa xr[0] spa yr[1] spa xl[1] spa yl[0] spa xr[1] spa yr[0]<<endl;
  }
  return 0;
}