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
template<typename T>
struct BIT{
  ll n;
  ll k=1;
  vector<T>data;
  BIT(ll size):n(size){
    data.assign(n,0);
    while(k*2<=n)k*=2;
  }
  void add(ll a,T w){
    for(ll i=a+1;i<=n;i+=i&-i)data[i-1]+=w;
  }
  T sum(ll a){
    T ret = 0;
    for(ll i=a+1;i>0;i-=i&-i)ret+=data[i-1];
    return ret;
  }
  T sum(ll a,ll b){return a>b?0:sum(b)-sum(a-1);}
  ll lower_bound(ll x){
    ll ret=0;    
    for(ll i=k;i>0;i/=2){
      if(ret+i<=n&&data[ret+i-1]<x){
        x-=data[ret+i-1];
        ret+=i;
      }
    }
    return ret;
  }
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  //cout<<fixed<<setprecision(10);
  ll res=0,buf=0;
  bool judge = true;
  ll n;cin>>n;
  vector<P>a(n);
  rep(i,0,n)cin>>a[i].fi;
  rep(i,0,n)a[i].se=-i;
  auto b=a;
  sort(ALLR(a));
  ll m;cin>>m;
  vector<pair<P,ll>>q(m);
  rep(i,0,m)cin>>q[i].fi.fi>>q[i].fi.se;
  rep(i,0,m)q[i].se=i;
  sort(ALL(q));
  vector<ll>ret(m);
  BIT<ll>bit(n);
  ll idx=0;
  rep(i,0,n){
    //cout<<a[i].fi spa -a[i].se<<endl;
    bit.add(-a[i].se,1);
    while(idx<m&&q[idx].fi.fi==i+1){
      ret[q[idx].se]=b[bit.lower_bound(q[idx].fi.se)].fi;
      //cout<<bit.lower_bound(q[idx].fi.se) spa ret[q[idx].se]<<endl;
      //cout<<q[idx].se spa q[idx].fi.fi spa q[idx].fi.se<<endl;
      idx++;
    }
  }
  rep(i,0,m)cout<<ret[i]<<endl;
  return 0;
}