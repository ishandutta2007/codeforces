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
template<typename T1, typename T2>
bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
template<typename T1, typename T2>
bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
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
vector<ll>dx={1,-1,0,0,1,1,-1,-1};
vector<ll>dy={0,0,1,-1,1,-1,1,-1};
template<typename T>
vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
template<typename... Ts>
auto make_v(size_t a,Ts... ts){
  return vector<decltype(make_v(ts...))>(a,make_v(ts...));
}
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2>&p){
  return os << p.first << " " << p.second;
}
//mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
// mod. m  a  a^{-1} 
// 
//MOD
ll MOD;
ll modinv(ll a) {ll b=MOD,u=1,v=0;
    while(b){ll t=a/b;a-=t*b;swap(a,b);u-=t*v;swap(u,v);}
    u%=MOD;if(u<0)u+=MOD;return u;}
ll Modinv(ll a,ll b){return ((a%MOD)*modinv(b))%MOD;}    
ll modinv(ll a,ll m) {ll b=m,u=1,v=0;
    while(b){ll t=a/b;a-=t*b;swap(a,b);u-=t*v;swap(u,v);}
    u%=m;if(u<0)u+=m;return u;}

inline long long mod(long long a, long long m) {
    long long res = a % m;
    if (res < 0) res += m;
    return res;
}

long long Garner(vector<long long> b, vector<long long> m, long long MOD) {
    m.push_back(MOD); // banpei
    vector<long long> coeffs((int)m.size(), 1);
    vector<long long> constants((int)m.size(), 0);
    for (int k = 0; k < (int)b.size(); ++k) {
        long long t = mod((b[k] - constants[k]) * modinv(coeffs[k], m[k]), m[k]);
        for (int i = k+1; i < (int)m.size(); ++i) {
            (constants[i] += t * coeffs[i]) %= m[i];
            (coeffs[i] *= m[k]) %= m[i];
        }
    }
    return constants.back();
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll a,b,p,x;cin>>a>>b>>p>>x;MOD=p;
  ll now=1;
  ll tmp=p*(p-1);
  rep(i,0,p-1){
    if(now==0){
      if(b==0){
        if(i==0)res+=x/(p-1)-1;
        else res+=(x+(p-1-i))/(p-1);
      }
    }
    else{
      ll d=Modinv(b,now);
      //mod(p-1)i,modpd
      vector<ll>v1={i,d};
      vector<ll>v2={p-1,p};
      ll k=Garner(v1,v2,p*(p-1));
      //cout<<now spa i spa d spa k<<endl;
      if(k==0)res+=x/((p-1)*p)-1;
      else res+=(x+(tmp-k))/((p-1)*p);
    }
    now=(now*a)%p;
  }
  cout<<res<<endl;
  return 0;
}