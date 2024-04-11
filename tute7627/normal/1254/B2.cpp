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
map<ll,ll> factoring(ll n){ 
  ll buf=n;
  map<ll,ll>ret;
  ll i,j;
  for(i=2;buf!=1&&i*i<=n;i++){
    for(j=0;buf%i==0;j++){
      buf/=i;
    }
    if(j>0)ret.emplace(i,j);
  }
  if(buf!=1)ret.emplace(buf,1);
  return ret;
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  //cout<<fixed<<setprecision(10);
  ll res=0,buf=0;
  ll n;cin>>n;
  vector<ll>a(n);
  rep(i,0,n)cin>>a[i];
  ll sumbuf=0;
  res=INF;
  rep(i,0,n)sumbuf+=a[i];
  auto mp=factoring(sumbuf);
  for(auto z:mp){
    ll x=z.fi;
    ll q,preq=a[0]%z.fi;
    ll psum=preq,l=0;
    ll minsum=0;
    rep(i,1,n){
      q=min(a[i],x-psum);
      psum+=q;
      if(psum==x){
        //cout<<i spa q spa preq<<endl;
        ll ret=0;
        ll minbuf=INF;
        rep(j,l,i+1){
          ret+=(j-l)*(j==l?preq:(j==i?q:a[j]));
        }
        ll le_cnt=0;
        rep(j,l,i+1){
          chmin(minbuf,ret);
          le_cnt+=(j==l?preq:(j==i?q:a[j]));
          ret+=le_cnt;
          ret-=x-le_cnt;
        }
        minsum+=minbuf;
        l=i;
        preq=(a[i]-q)%x;
        psum=preq;
      }
    }
    //cout<<sumbuf spa z.fi spa minsum<<endl;
    chmin(res,minsum);
  }
  if(sumbuf==1)cout<<-1<<endl;
  else cout<<res<<endl;
  return 0;
}