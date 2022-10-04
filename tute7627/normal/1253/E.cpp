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
#define rep(i,n,m) for(ll i = (n); i < (ll)(m); i++)
#define rrep(i,n,m) for(ll i = (m) - 1; i >= (ll)(n); i--)
using ll = int;
using ld = long double;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
//const ll INF = 1e18;
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
  //cout<<fixed<<setprecision(10);
  ll res=0,buf=0;
  bool judge = true;
  ll n,m;cin>>n>>m;
  vector<P>x(n);
  rep(i,0,n){
    cin>>x[i].fi>>x[i].se;
    x[i].fi--;
  }
  sort(ALL(x));
  ll inf=1e9;
  auto dp=vec(n+1,m+1,inf);
  dp[0][0]=0;
  rep(i,0,n){
    //cout<<x[i].fi spa x[i].se<<endl;
    rep(j,0,m){
      if(dp[i][j]==inf)continue;
      chmin(dp[i+1][j],dp[i][j]);
      if(j>=x[i].fi-x[i].se){
        chmin(dp[i+1][min(m,max(x[i].fi+x[i].se+1,j))],dp[i][j]);
      }
      //if(x[i].fi<j)continue;
      chmin(dp[i+1][max(j,min(m,2*x[i].fi-j+1))],
        dp[i][j]+max(0,x[i].fi-x[i].se-j));
      chmin(dp[i+1][m],
        dp[i][j]+max(0,max(abs(x[i].fi-j),abs(m-1-x[i].fi))-x[i].se));
    }
    chmin(dp[i+1][m],dp[i][m]);
  }
  /*rep(i,0,n+1){
    cout<<i<<endl;
    rep(j,0,m+1)if(dp[i][j]!=INF)cout<<j spa dp[i][j]<<endl;
  }*/
  cout<<dp[n][m]<<endl;
  return 0;
}