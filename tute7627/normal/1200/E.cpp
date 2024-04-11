#include<bits/stdc++.h>
using namespace std;

#define ALL(a)  (a).begin(),(a).end()
#define ALLR(a)  (a).rbegin(),(a).rend()
#define spa << " " <<
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
void debug(vector<vector<ll>>v,ll h,ll w){for(ll i=0;i<h;i++)
{cout<<v[i][0];for(ll j=1;j<w;j++)cout spa v[i][j];cout<<endl;}};
void debug(vector<string>v,ll h,ll w){for(ll i=0;i<h;i++)
{for(ll j=0;j<w;j++)cout<<v[i][j];cout<<endl;}};
void debug(vector<ll>v,ll n){cout<<v[0];
for(ll i=1;i<n;i++)cout spa v[i];cout<<endl;};
vector<vector<ll>>vec(ll x, ll y, ll w){
  vector<vector<ll>>v(x,vector<ll>(y,w));return v;}
ll gcd(ll x,ll y){ll r;while(y!=0&&(r=x%y)!=0){x=y;y=r;}return y==0?x:y;}
//m.emplace(x,0).fi->se++;

template<ll mod>
struct RollingHash{
  vector<ll> hash,p;
  ll base;
  RollingHash(string s, ll b){
    ll n = (ll)s.size();
    base = b;
    hash.assign(n+1,0);
    p.assign(n+1,1);
    for(ll i=0;i<n;i++){
      hash[i+1]=(hash[i]*base+s[i])%mod;
      p[i+1]=(p[i]*base)%mod;
    }
  }
  ll get(ll l, ll r){
    ll ret=hash[r+1]-(hash[l]*p[r-l+1])%mod;
    if(ret<0)ret+=mod;
    return ret;
  }
};


int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  ll res=0,res1=INF,res2=-INF,buf=0;
  bool judge = true;
  const ll tmp_mod=608396398;
  //const ll tmp_mod=979418779;
  //const ll tmp_mod=775791517;
  ll base=0;while(base<100000)base=(rand()*998244353)%tmp_mod;
  //ll base = 100000;
  using RH = RollingHash<tmp_mod>;
  ll n;cin>>n;
  vector<string>s(n);
  rep(i,0,n)cin>>s[i];
  string ans;
  ans+=s[0];
  rep(i,1,n){
    ll na=ans.size();
    ll ns=s[i].size();
    RH rh(ans.substr(max(0LL,na-ns)),base);
    RH rhs(s[i],base);
    //cout<<ans.substr(max(0LL,na-ns)) spa s[i]<<endl;
    ll point=0;
    ll q=min(na,ns);
    rep(j,0,min(na,ns)){
      if(rh.get(q-j-1,q-1)==rhs.get(0,j)){
        point=j+1;
      }
    }
    if(point!=ns){
      ans+=s[i].substr(point);
    }
  }
  cout<<ans<<endl;
  return 0;
}