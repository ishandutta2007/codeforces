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
ostream &operator<<(ostream &os, pair<ll, ll>&p){
  return os << p.first << " " << p.second;
}  
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  //cout<<fixed<<setprecision(10);
  ll res=0,buf=0;
  bool judge = true;
  string s,t;cin>>s>>t;
  ll n=s.size(),m=t.size();
  s.PB('$');t.PB('$');
  ll lim=401;
  auto dp=make_v(lim,m+1,lim,-1);
  dp[0][0][0]=0;
  auto pre=make_v(lim,m+1,lim,MP(0,0));
  rep(i,0,lim-1)rep(j,0,m+1){
    rep(o,0,lim){
      if(dp[i][j][o]==-1)continue;
      if(o!=0){
        if(dp[i+1][j+(t[j]==')')][o-1]
           <dp[i][j][o]+(s[dp[i][j][o]]==')')){
          dp[i+1][j+(t[j]==')')][o-1]
           =dp[i][j][o]+(s[dp[i][j][o]]==')');
          pre[i+1][j+(t[j]==')')][o-1]=MP(j,o);
        }
      }
      if(o!=lim-1){
        if(dp[i+1][j+(t[j]=='(')][o+1]
           <dp[i][j][o]+(s[dp[i][j][o]]=='(')){
          dp[i+1][j+(t[j]=='(')][o+1]
           =dp[i][j][o]+(s[dp[i][j][o]]=='(');
          pre[i+1][j+(t[j]=='(')][o+1]=MP(j,o);
        }
      }
    }
  }
  rep(i,0,lim){
    //cout<<i<<endl;
    //debug(dp[i],m+1,10);
    if(dp[i][m][0]==n){
      string ret;
      ll p=i,q=m,r=0;
      while(p!=0){
        if(pre[p][q][r].se<r)ret.PB('(');
        else ret.PB(')');
        P tmp=pre[p][q][r];
        p=p-1;q=tmp.fi;r=tmp.se;
      }
      reverse(ALL(ret));
      cout<<ret<<endl;
      break;
    }
  }
  return 0;
}