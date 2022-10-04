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
//m.emplace(x,0).fi->se++;

  

int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  ll res=0,res1=INF,res2=-INF,buf=0;
  bool judge = true;
  ll n;cin>>n;
  ll MAX_V=n;
  vector<string>inp(n);
  rep(i,0,n)cin>>inp[i];
  vector<vector<ll>> matrix(MAX_V,vector<ll>(MAX_V,INF));
  for(ll i=0;i<MAX_V;i++)matrix[i][i]=0;
  for(ll i=0;i<MAX_V;i++){
    for(ll j=0;j<MAX_V;j++){
      if(inp[i][j]=='1')matrix[i][j]=1;
    }
  }
  ll m;cin>>m;
  vector<ll>s(m);
  rep(i,0,m)cin>>s[i];

  for(ll j=0;j<MAX_V;j++){
    for(ll i=0;i<MAX_V;i++){
      for(ll o=0;o<MAX_V;o++){
        chmin(matrix[i][o],matrix[i][j]+matrix[j][o]);
      }
    }
  }
  vector<ll>dp(m,INF);
  vector<ll>prev(m,-1);
  dp[0]=1;
  rep(i,0,m-1){
    ll j=1;
    while(1){
      if(matrix[s[i]-1][s[i+j]-1]==j){
        if(dp[i+j]>dp[i]+1){
          dp[i+j]=dp[i]+1;
          prev[i+j]=i;
        }
        //cout<<i spa j<<endl;
        j++;
      }
      else break;
      if(i+j>=m)break;
    }
  }
  buf=m-1;
  vector<ll>ret;
  ret.push_back(s[m-1]);
  while(buf!=0){
    ret.push_back(s[prev[buf]]);
    buf=prev[buf];
  }
  reverse(ALL(ret));
  cout<<dp[m-1]<<endl;
  debug(ret,dp[m-1]);
  return 0;
}