#include<bits/stdc++.h>
using namespace std;

#define ALL(a)  (a).begin(),(a).end()
#define ALLR(a)  (a).rbegin(),(a).rend()
#define spa << " " <<
#define lfs <<fixed<<setprecision(10)<<
#define test cout<<"test"<<endl;
#define fi first
#define se second
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define rep(i,n,m) for(ll i = n; i < (ll)(m); i++)
#define rrep(i,n,m) for(ll i = n - 1; i >= (ll)(m); i--)
typedef long long ll;
typedef long double ld;
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
void debug(vector<vector<T>>v,ll h,ll w){for(ll i=0;i<h;i++)
{cout<<v[i][0];for(ll j=1;j<w;j++)cout spa v[i][j];cout<<endl;}};
void debug(vector<string>v,ll h,ll w){for(ll i=0;i<h;i++)
{for(ll j=0;j<w;j++)cout<<v[i][j];cout<<endl;}};
template<typename T>
void debug(vector<T>v,ll n){cout<<v[0];
for(ll i=1;i<n;i++)cout spa v[i];cout<<endl;};
template<typename T>
vector<vector<T>>vec(ll x, ll y, T w){
  vector<vector<T>>v(x,vector<T>(y,w));return v;}
ll gcd(ll x,ll y){ll r;while(y!=0&&(r=x%y)!=0){x=y;y=r;}return y==0?x:y;}
template<typename T>
void emp(map<T,ll>&m, T x){m.emplace(x,0).first->second++;}
vector<ll>dx={1,0,-1,0,1,1,-1,-1};
vector<ll>dy={0,1,0,-1,1,-1,1,-1};
template<typename T>
vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
template<typename... Ts>
auto make_v(size_t a,Ts... ts){
  return vector<decltype(make_v(ts...))>(a,make_v(ts...));
}



int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  ll res=0,res1=INF,res2=-INF,buf=0;
  bool judge = true;
  ll n;cin>>n;
  ll xl=-1,xr=-1,yl=-1,yr=-1;
  rep(i,0,n){
    cout<<"?" spa i+1 spa 1 spa i+1 spa n<<endl;
    ll x;cin>>x;
    if(x&1){
      if(xl==-1)xl=i+1;
      else xr=i+1;
    }
  }
  rep(i,0,n){
    cout<<"?" spa 1 spa i+1 spa n spa i+1<<endl;
    ll x;cin>>x;
    if(x&1){
      if(yl==-1)yl=i+1;
      else yr=i+1;
    }
  }
  //cout<<xl spa yl spa xr spa yr<<endl;
  if(xl!=-1&&yl!=-1){
    vector<P>ret;
    cout<<"?" spa xl spa yl spa xl spa yl<<endl;
    ll x;cin>>x;if(x==1)ret.EB(xl,yl);
    cout<<"?" spa xl spa yr spa xl spa yr<<endl;
    cin>>x;if(x==1)ret.EB(xl,yr);
    cout<<"?" spa xr spa yl spa xr spa yl<<endl;
    cin>>x;if(x==1)ret.EB(xr,yl);
    cout<<"?" spa xr spa yr spa xr spa yr<<endl;
    cin>>x;if(x==1)ret.EB(xr,yr);
    cout<<"!" spa ret[0].fi spa ret[0].se spa ret[1].fi spa ret[1].se<<endl;
  }
  else if(yl!=-1){
    ll l=0,r=n;
    while(r-l>=2){
      ll mid=(l+r)/2;
      cout<<"?" spa 1 spa yl spa mid spa yl<<endl;
      ll x;cin>>x;
      if(x&1)r=mid;
      else l=mid;
    }
    cout<<"!" spa r spa yl spa r spa yr<<endl; 
  }
  else{
    ll l=0,r=n;
    while(r-l>=2){
      ll mid=(l+r)/2;
      cout<<"?" spa xl spa 1 spa xl spa mid<<endl;
      ll x;cin>>x;
      if(x&1)r=mid;
      else l=mid;
    }
    cout<<"!" spa xl spa r spa xr spa r<<endl; 
  }
  return 0;
}