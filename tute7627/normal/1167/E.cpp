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
template<typename T>
void emp(map<T,ll>&m, T x){m.emplace(x,0).first->second++;}



int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  ll res=0,res1=INF,res2=-INF,buf=0;
  bool judge = true;
  ll n,x;cin>>n>>x;
  vector<ll>a(n);
  rep(i,0,n)cin>>a[i];
  vector<P>b(x+2,{n,-1});
  rep(i,0,n){
    chmin(b[a[i]].fi,i);
    chmax(b[a[i]].se,i);
  }
  ll pl=n,pr=-1;
  ll ql=n,qr=-1;
  ll r=x+1;

  vector<P>y(x+2,{-1,n});
  while(r>0&&b[r].se<=ql){
      chmin(ql,b[r].fi);
      chmax(qr,b[r].se);
      y[r].fi=ql,y[r].se=qr;
      r--;
  }
  //rep(i,0,x+2)cout<<i spa b[i].fi spa b[i].se<<endl;
  //rep(i,0,x+2)cout<<y[i].fi spa y[i].se<<endl;
  r=2;
  rep(i,0,x){
    if(b[i].fi<pr)break;
    chmin(pl,b[i].fi);
    chmax(pr,b[i].se);
    while(r<x+2&&(y[r].fi<=pr||r<=i+1)){
      r++;
    }
    //cout<<i spa r<<endl;
    res+=x+2-r;
    //cout<<res<<endl;
  }
  cout<<res<<endl;
}