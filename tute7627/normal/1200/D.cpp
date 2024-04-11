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
void debug(vector<vector<ll>>v,ll h,ll w){for(ll i=0;i<h;i++)
{cout<<v[i][0];for(ll j=1;j<w;j++)cout spa v[i][j];cout<<endl;}};
void debug(vector<string>v,ll h,ll w){for(ll i=0;i<h;i++)
{for(ll j=0;j<w;j++)cout<<v[i][j];cout<<endl;}};
void debug(vector<ll>v,ll n){cout<<v[0];
for(ll i=1;i<n;i++)cout spa v[i];cout<<endl;};
vector<vector<ll>>vec(ll x, ll y, ll w){
  vector<vector<ll>>v(x,vector<ll>(y,w));return v;}
ll gcd(ll x,ll y){ll r;while((r=x%y)!=0){x=y;y=r;}return y;}
//m.emplace(x,0).fi->se++;

int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  ll res=0,res1=INF,res2=-INF,buf=0;
  bool judge = true;
  ll n,k;cin>>n>>k;
  vector<string>s(n);
  auto v=vec(n+1,n+1,0);
  rep(i,0,n)cin>>s[i];
  rep(i,0,n){
    ll l=-1,r=-1;
    rep(j,0,n){
      if(s[i][j]=='B'){
        if(l==-1)l=j;
        r=j;
      }
    }
    if(l==-1){
      buf++;
    }
    else if(r-l+1<=k){
      v[max(0LL,i-k+1)][max(0LL,r-k+1)]++;
      v[min(n,i+1)][max(0LL,r-k+1)]--;
      v[max(0LL,i-k+1)][min(n,l+1)]--;
      v[min(n,i+1)][min(n,l+1)]++;
    }
    //debug(v,n,n);
    //cout<<i<<endl;
  }
  rep(i,0,n){
    ll l=-1,r=-1;
    rep(j,0,n){
      if(s[j][i]=='B'){
        if(l==-1)l=j;
        r=j;
      }
    }
    if(l==-1){
      buf++;
    }
    else if(r-l+1<=k){
      v[max(0LL,r-k+1)][max(0LL,i-k+1)]++;
      v[max(0LL,r-k+1)][min(n,i+1)]--;
      v[min(n,l+1)][max(0LL,i-k+1)]--;
      v[min(n,l+1)][min(n,i+1)]++;
    }
    //debug(v,n,n);
    //cout<<i<<endl;
  }
  res=v[0][0];
  rep(i,0,n){
    v[i+1][0]+=v[i][0];
    chmax(res,v[i+1][0]);
  }
  rep(i,0,n){
    v[0][i+1]+=v[0][i];
    chmax(res,v[0][i+1]);
  }
  rep(i,1,n-k+1)rep(j,1,n-k+1){
    v[i][j]+=v[i][j-1]+v[i-1][j]-v[i-1][j-1];
    chmax(res,v[i][j]);
  }
  cout<<res+buf<<endl;
  //debug(v,n-k+1,n-k+1);
  return 0;
}