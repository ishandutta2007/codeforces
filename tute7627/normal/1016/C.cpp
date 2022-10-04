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
#define rrep(i,n,m) for(ll i = (m) - 1; i >= (ll)(n); i--)
using ll = long long;
using ld = long double;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const ll INF = 1e18;
using P = pair<ll, ll>;
template<typename T>
bool chmin(T &a,T b){if(a>b){a=b;return true;}else return false;}
template<typename T>
bool chmax(T &a,T b){if(a<b){a=b;return true;}else return false;}
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
  ll res=0,buf=0;
  bool judge = true;
  ll n;cin>>n;
  vector<ll>a1(n),a2(n);
  rep(i,0,n)cin>>a1[i];
  rep(i,0,n)cin>>a2[i];
  vector<ll>b1(n);
  vector<ll>sum(n+1);
  rrep(i,0,n)sum[i]=sum[i+1]+a1[i]+a2[i];
  rep(i,0,n)b1[0]+=a1[i]*i;
  rep(i,0,n)b1[0]+=a2[n-i-1]*(i+n);
  rep(i,1,n){
    b1[i]=b1[i-1];
    b1[i]-=a1[i-1]*2*(i-1);
    b1[i]-=a2[i-1]*(2*n-1);
    b1[i]+=sum[i];
  }
  vector<ll>b2(n);
  rep(i,0,n)b2[0]+=a2[i]*i;
  rep(i,0,n)b2[0]+=a1[n-i-1]*(i+n);
  rep(i,1,n){
    b2[i]=b2[i-1];
    b2[i]-=a2[i-1]*2*(i-1);
    b2[i]-=a1[i-1]*(2*n-1);
    b2[i]+=sum[i];
  }
  ll now=0;
  rep(i,0,n){
    if(i%2==0){
      chmax(res,now+b1[i]);
      now+=2*i*a1[i]+(2*i+1)*a2[i];
    }
    else{
      chmax(res,now+b2[i]);
      now+=2*i*a2[i]+(2*i+1)*a1[i];
    } 
  }
  cout<<res<<endl;
  return 0;
}