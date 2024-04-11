#include<bits/stdc++.h>
using namespace std;

#define ALL(a)  (a).begin(),(a).end()
#define ALLR(a)  (a).rbegin(),(a).rend()
#define spa << " " <<
#define test cout<<"test"<<endl;
#define fi first
#define se second
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
void debug(vector<vector<P>>v,ll h,ll w){for(ll i=0;i<h;i++)
{cout<<v[i][0].fi;for(ll j=1;j<w;j++)cout spa v[i][j].fi;cout<<endl;}};
void debugs(vector<vector<P>>v,ll h,ll w){for(ll i=0;i<h;i++)
{cout<<v[i][0].se;for(ll j=1;j<w;j++)cout spa v[i][j].se;cout<<endl;}};
void debug(vector<string>v,ll h,ll w){for(ll i=0;i<h;i++)
{for(ll j=0;j<w;j++)cout<<v[i][j];cout<<endl;}};
void debug(vector<ll>v,ll n){cout<<v[0];
for(ll i=1;i<n;i++)cout spa v[i];cout<<endl;};
ll gcd(ll x,ll y){ll r;while((r=x%y)!=0){x=y;y=r;}return y;}
//m.emplace(x,0).fi->se++;

int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  ll res=0,res1=INF,res2=-INF,buf=0;
  bool judge = true;
  ll n,m,k,q;cin>>n>>m>>k>>q;
  vector<P>t(k);
  vector<ll>p(n);
  vector<ll>b(q);
  rep(i,0,k)cin>>t[i].fi>>t[i].se;
  rep(i,0,q)cin>>b[i];
  sort(ALL(b));
  vector<ll>l(n+1,INF),r(n+1,-1);
  rep(i,0,k){
    chmin(l[t[i].fi-1],t[i].se);
    chmax(r[t[i].fi-1],t[i].se);
    p[t[i].fi-1]++;
  }
  vector<vector<P>>dp(n+1,vector<P>(4,{INF,INF}));
  dp[0][0]={1,-1};//column,minlength
  ll countbuf=0;
  rep(i,0,n){
    countbuf+=p[i];
    if(l[i]!=INF){
      auto itr=lower_bound(ALL(b),l[i]);
      if(itr!=b.end())dp[i+1][1].fi=*itr;
      if(itr!=b.begin()){
        itr--;
        dp[i+1][0].fi=*itr;
      }
      itr=lower_bound(ALL(b),r[i]);
      if(itr!=b.end())dp[i+1][3].fi=*itr;
      if(itr!=b.begin()){
        itr--;
        dp[i+1][2].fi=*itr;
      }
      rep(j,0,4){
        rep(o,0,4){
          if(dp[i+1][o].fi!=INF&&dp[i][j].fi!=INF){
            if(o<=1){
              chmin(dp[i+1][o].se,
              dp[i][j].se+abs(r[i]-dp[i][j].fi)+1+
              abs(r[i]-l[i])+abs(l[i]-dp[i+1][o].fi));
            }
            if(o>=2){
              chmin(dp[i+1][o].se,
              dp[i][j].se+abs(l[i]-dp[i][j].fi)+1+
              abs(r[i]-l[i])+abs(r[i]-dp[i+1][o].fi));
            }
          }
        }
      }
    }
    else{
        if(i!=0){
          rep(j,0,4){
            dp[i+1][j].fi=dp[i][j].fi;
            dp[i+1][j].se=dp[i][j].se+1;
          }
        }
        else{
          dp[i+1][0].fi=b[0];
          dp[i+1][0].se=dp[i][0].se+1+(b[0]-1);
          rep(j,1,4){
            dp[i+1][j].fi=dp[i][j].fi;
            dp[i+1][j].se=dp[i][j].se+1;
          }
        }
    }
    
    if(countbuf==k){
      rep(j,0,4){
      if(j<=1&&dp[i+1][j].fi!=INF)
      chmin(res1,dp[i+1][j].se-abs(dp[i+1][j].fi-l[i]));
      if(j>=2&&dp[i+1][j].fi!=INF)
      chmin(res1,dp[i+1][j].se-abs(dp[i+1][j].fi-r[i]));      
      }
      cout<<res1<<endl;
      break;
    }

  }
  /*debug(dp,n+1,4);
  cout<<endl;
  debugs(dp,n+1,4);*/
  
  //debug(l,n);
  //debug(r,n);
  return 0;
}