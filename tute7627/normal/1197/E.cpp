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
  vector<P> a(n);
  rep(i,0,n){
    ll p,q;
    cin>>p>>q;
    a[i]=MP(q,p);
  }
  sort(ALL(a));
  map<ll,P>dp;
  rep(i,0,n){
    dp.emplace(a[i].fi,MP(INF,0));
    dp.emplace(a[i].se,MP(INF,0));
  }
  dp[0]=MP(0,1);
  priority_queue<ll,vector<ll>,greater<ll>>p;
  p.push(0);
  rep(i,0,n){
    ll l=a[i].fi;
    ll r=a[i].se;
    while(!p.empty()&&p.top()<l){
      buf=p.top();
      if(dp[l].fi>dp[buf].fi+(l-buf)){
        dp[l].fi=dp[buf].fi+l-buf;
        dp[l].se=dp[buf].se;
      }
      else if(dp[l].fi==dp[buf].fi+(l-buf)){
        pmod(dp[l].se,dp[buf].se);
      }
      while(!p.empty()&&p.top()==buf)p.pop();
    }
    if(dp[l].fi<dp[r].fi){
      dp[r].fi=dp[l].fi;
      dp[r].se=dp[l].se;
    }
    else if(dp[l].fi==dp[r].fi){
      pmod(dp[r].se,dp[l].se);
    }
    //cout<<l spa r<<endl; 
    p.push(l);
    p.push(r); 
    buf=l;
  }
  auto itr=dp.upper_bound(buf);
  ll minbuf=INF;
  for(;itr!=dp.end();itr++){
    if(minbuf>itr->se.fi){
      res=itr->se.se;
      minbuf=itr->se.fi;
    }
    else if(minbuf==itr->se.fi){
      pmod(res,itr->se.se);
    }
  }
  //cout<<dp[4].fi spa dp[4].se<<endl;
  cout<<res<<endl;
  //for(auto z:dp)cout<<z.fi spa z.se.fi spa z.se.se<<endl;

  
}