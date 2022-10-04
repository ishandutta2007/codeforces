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
  vector<ll>r(3);
  rep(i,0,3)cin>>r[i];
  ll d;cin>>d;
  vector<ll>a(n);
  rep(i,0,n)cin>>a[i];
  auto dp=make_v(n+1,2,3,3,INF);
  dp[0][0][0][0]=0;
  rep(i,0,n){
    rep(p,0,3)rep(q,0,3)rep(j,0,2){
      //if(dp[i][j][p][q]<=100)cout<<i spa j spa p spa q spa dp[i][j][p][q]<<endl;
      ll pos=i+j;
      if(pos>=n)continue;
      //c01=min((a[pos]+1)*r[0],r[1]);
      if(j==0){
        if(p==0){
          chmin(dp[i][j^1][1][q],dp[i][j][p][q]+min((a[pos]+1)*r[0],r[1])+d);
          chmin(dp[i][j][1][q],dp[i][j][p][q]+min((a[pos]+1)*r[0],r[1])+d*2);
          chmin(dp[i][j][2][q],dp[i][j][p][q]+a[pos]*r[0]+r[2]);
        }
        if(p==1){
          chmin(dp[i][j][2][q],dp[i][j][p][q]+r[0]);
        }
        if(p==2){
          chmin(dp[i+1][0][q][0],dp[i][j][p][q]+d);
        }
      }
      else{
        if(q==0){
          chmin(dp[i][j^1][p][1],dp[i][j][p][q]+min((a[pos]+1)*r[0],r[1])+d);
          chmin(dp[i][j][p][1],dp[i][j][p][q]+min((a[pos]+1)*r[0],r[1])+d*2);
          /*if(p==2)chmin(dp[i+1][0][2][0],dp[i][j][p][q]+a[pos]*r[0]+r[2]+d);
          else chmin(dp[i][j^1][p][2],dp[i][j][p][q]+a[pos]*r[0]+r[2]+d);*/
          chmin(dp[i][j^1][p][2],dp[i][j][p][q]+a[pos]*r[0]+r[2]+d);
        }
        if(q==1){
          chmin(dp[i][j][p][2],dp[i][j][p][q]+r[0]);
        }
        if(p==2)chmin(dp[i+1][0][q][0],dp[i][j][p][q]+d);
      }
    }
  }
  //debug(dp,n+1,2);
  cout<<min({dp[n-2][0][2][2],dp[n-2][1][2][2],dp[n-1][0][2][0]})<<endl;
  return 0;
}