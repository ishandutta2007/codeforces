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

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  //cout<<fixed<<setprecision(10);
  ll res=0,buf=0;
  bool judge = true;
  ll n,m;cin>>n>>m;
  vector<ll>a(m);
  rep(i,0,n){
    ll x;cin>>x;
    a[x-1]++;
  }
  rep(i,0,m){
    while(a[i]>=9){
      a[i]-=3;res++;
    }
  }
  auto dp=make_v(2,9,9,-1LL);
  dp[0][0][0]=0;
  rep(o,0,m){
    rrep(i,0,9)rrep(j,0,9){
      dp[1][i][j]=-1;
      if(dp[0][i][j]==-1)continue;
      if(i>=3)chmax(dp[0][i-3][j],dp[0][i][j]+1);
      if(j>=3)chmax(dp[0][i][j-3],dp[0][i][j]+1);
    }
    rep(i,0,9)rep(j,0,9){
      if(dp[0][i][j]==-1)continue;
      ll rm=min({a[o],i,j});
      rep(k,0,rm+1){
        chmax(dp[1][j-k][a[o]-k],dp[0][i][j]+k);
      }
    }
    dp[0]=dp[1];
    //cout<<o<<endl;
    //debug(dp[0],9,9);
    //debug(dp[1],9,9);
  }
  //cout<<res<<endl;
  ll ret=0;
  rep(i,0,9)rep(j,0,9){
    if(dp[0][i][j]!=-1){
      //cout<<i spa j spa dp[0][i][j] spa res+dp[0][i][j]+i/3+j/3<<endl;
      chmax(ret,res+dp[0][i][j]+i/3+j/3);
    }
  }
  cout<<ret<<endl;
  return 0;
}