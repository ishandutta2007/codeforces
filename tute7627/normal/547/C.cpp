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
template<typename T1, typename T2>bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
template<typename T1, typename T2>bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
ll median(ll a,ll b, ll c){return a+b+c-max({a,b,c})-min({a,b,c});}
void ans1(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}
void ans2(bool x){if(x) cout<<"YES"<<endl;else cout<<"NO"<<endl;}
void ans3(bool x){if(x) cout<<"Yay!"<<endl;else cout<<":("<<endl;}
template<typename T1,typename T2>void ans(bool x,T1 y,T2 z){if(x)cout<<y<<endl;else cout<<z<<endl;}  
template<typename T>void debug(vector<vector<T>>&v,ll h,ll w){for(ll i=0;i<h;i++){cout<<v[i][0];for(ll j=1;j<w;j++)cout spa v[i][j];cout<<endl;}};
void debug(vector<string>&v,ll h,ll w){for(ll i=0;i<h;i++){for(ll j=0;j<w;j++)cout<<v[i][j];cout<<endl;}};
template<typename T>void debug(vector<T>&v,ll n){if(n!=0)cout<<v[0];for(ll i=1;i<n;i++)cout spa v[i];cout<<endl;};
template<typename T>vector<vector<T>>vec(ll x, ll y, T w){vector<vector<T>>v(x,vector<T>(y,w));return v;}
ll gcd(ll x,ll y){ll r;while(y!=0&&(r=x%y)!=0){x=y;y=r;}return y==0?x:y;}
vector<ll>dx={1,-1,0,0,1,1,-1,-1};vector<ll>dy={0,0,1,-1,1,-1,1,-1};
template<typename T>vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
template<typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v(ts...))>(a,make_v(ts...));}
template<typename T1, typename T2>ostream &operator<<(ostream &os, const pair<T1, T2>&p){return os << p.first << " " << p.second;}
template<typename T>ostream &operator<<(ostream &os, const vector<T> &v){for(auto &z:v)os << z << " ";cout<<"|"; return os;}
//mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
int popcount(ll x){return __builtin_popcountll(x);};
int poplow(ll x){return __builtin_ctzll(x);};
int pophigh(ll x){return 63 - __builtin_clzll(x);};
//maxa=10^7150ms,78MB10^81800ms,780MB
struct osa_k{
  ll maxa;
  vector<ll>data;//data[i]:i
  osa_k(ll a):maxa(a){
    data.assign(maxa+1,1LL);
    build();
  }
  void build(){
    for(ll i=0;i<=maxa;i++)data[i] = i;
    for(ll i=2;i*i<=maxa;i++){
      if(data[i] < i)continue;
      for(ll j=i*i;j<=maxa;j+=i){
        if(data[j] == j)data[j] = i;
      }
    }
  }
  bool isPrime(ll x){
    return (x >= 2)&&(data[x] == x);
  }
  map<ll,ll>factoring(ll x){
    map<ll,ll>ret;
    while(x > 1){
      ret[data[x]]++;
      x /= data[x];
    }
    return ret;
  }
  vector<ll>divisor_enum(ll x){
    auto v = factoring(x);
    vector<ll>ret;
    ret.push_back(1);
    for(auto z:v){
      ll sz = ret.size();
      ll tmp = z.fi;
      for(ll i=0;i<z.se;i++){
        for(ll j=0;j<sz;j++){
          ret.push_back(ret[j] * tmp);
        }
        tmp *= z.fi;
      }
    }
    sort(ret.begin(),ret.end());//ok
    return ret;
  }
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll lim=500005;
  //ll lim=15;cout<<"naosu"<<endl;
  osa_k osak(lim);
  ll n,q;cin>>n>>q;
  vector<ll>a(n);
  rep(i,0,n)cin>>a[i];
  vector<ll>cf(lim);
  vector<vector<int>>div(lim);
  rep(i,1,lim){
    cf[i]=1;
    auto mp=osak.factoring(i);
    for(auto z:mp){
      if(z.se!=1){
        cf[i]=0;
        break;
      }
      else cf[i]*=-1;
    }
    if(cf[i]!=0){
      for(ll j=i;j<lim;j+=i){
        div[j].PB(i);
      }
    }
  }
  ll ret=0;
  vector<ll>t(n);
  vector<ll>num(lim);
  //debug(cf,lim);
  while(q--){
    ll x;cin>>x;x--;
    if(!t[x]){
      for(auto d:div[a[x]]){
        ret+=num[d]*cf[d];
        num[d]++;
      }
    }
    else{
      for(auto d:div[a[x]]){
        num[d]--;
        ret-=num[d]*cf[d];
      }
    }
    t[x]^=1;
    //debug(div[a[x]])
    //debug(num,lim);
    cout<<ret<<endl;
  }
  return 0;
}