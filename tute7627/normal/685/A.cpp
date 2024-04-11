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
string convert(ll n,ll bit){
  string ret(bit,'0');
  for(ll i=0;i<bit;i++)if(n&1LL<<bit-1-i)ret[i]='1';
  return ret;
}
string convert(ll n){
  ll bit=0;
  while(n>=1<<bit)bit++;
  return convert(n,max(1LL,bit));
}
ll convert(string s){
  ll ret=0;
  ll n=s.size();
  for(ll i=0;i<n;i++)if(s[i]=='1')ret|=1LL<<n-i-1;
  return ret;
}
vector<ll> convert_base(ll n,ll m,ll base){
	vector<ll>ret(m,0);
	for(ll i=0;i<m;i++){
		ret[i]=n%base;
		n/=base;
	}
	return ret;
}
ll convert_base(vector<ll>v,ll base){
  ll tmp=1,ret=0;
  for(ll i=0;i<v.size();i++){
    ret+=v[i]*tmp;
    tmp*=base;
  }
  return ret;
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n,m;cin>>n>>m;
  ll s=7;
  ll a=1,b=1;
  {
    ll tmp=7;
    while(tmp<n){
      tmp*=7;a++;
    }
    tmp=7;
    while(tmp<m){
      tmp*=7;
      b++;
    }
  }
  if(a+b>=8){
    cout<<0<<endl;
    return 0;
  }
  //cout<<a spa b<<endl;
  rep(i,0,n)rep(j,0,m){
    auto v1=convert_base(i,a,7);
    auto v2=convert_base(j,b,7);
    for(auto z:v2)v1.PB(z);
    set<ll>st;
    bool sw=true;
    for(auto z:v1){
      //cout<<i spa j spa z<<endl;
      if(st.count(z)){
        sw=false;
        break;
      }
      st.insert(z);
    }
    //cout<<sw<<endl;
    res+=sw;
  }
  cout<<res<<endl;
  return 0;
}