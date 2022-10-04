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
template<typename T>void rearrange(vector<ll>&ord, vector<T>&v){
  auto tmp = v;
  for(int i=0;i<tmp.size();i++)v[i] = tmp[ord[i]];
}
template<typename Head, typename... Tail>void rearrange(vector<ll>&ord,Head&& head, Tail&&... tail){
  rearrange(ord, head);
  rearrange(ord, tail...);
}
//mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
int popcount(ll x){return __builtin_popcountll(x);};
int poplow(ll x){return __builtin_ctzll(x);};
int pophigh(ll x){return 63 - __builtin_clzll(x);};
using ul = unsigned long long;
template<ll mod>
struct RollingHash{
  vector<ul> hash,p;
  const ul positivizer = mod * 4;
  ul base;
  RollingHash(string s, ul b){
    ul n = (ul)s.size();
    base = b;
    hash.assign(n+1,0);
    p.assign(n+1,1);
    for(ll i=0;i<n;i++){
      hash[i+1]=calcmod(mul(hash[i],base)+s[i]);
      p[i+1]=mul(p[i],base);
    }
  }
  ul get(ll l, ll r){ //[l,r]
    return calcmod(hash[r+1] + positivizer - mul(hash[l],p[r-l+1]));
  }
  ul mul(ul a, ul b){
    ul au = a >> 31;
    ul ad = a & (1UL << 31) - 1;
    ul bu = b >> 31;
    ul bd = b & (1UL << 31) - 1;
    ul mid = ad * bu + au * bd;
    ul midu = mid >> 30;
    ul midd = mid & (1UL << 30) - 1;
    return calcmod(au * bu * 2 + midu + (midd << 31) + ad * bd);
  }
  ul calcmod(ul val){
    val = (val & mod) + (val >> 61);
    if(val >= mod) val -= mod;
    return val;
  }
  ul merge(ul x,ul y, ll len){
    return calcmod(mul(x,len)+y);
  }
};
struct RandomNumberGenerator {
  mt19937_64 mt;

  RandomNumberGenerator() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}

  ll operator()(ll a, ll b) { // [a, b)
    uniform_int_distribution< long long > dist(a, b - 1);
    return dist(mt);
  }

  ll operator()(ll b) { // [0, b)
    return (*this)(0, b);
  }
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n;cin>>n;
  vector<string>s(n),t(n);
  rep(i,0,n)cin>>s[i];
  rep(i,0,n)cin>>t[i];
  vector<ll>l(n,0),r(n,0);
  vector<bool>ok(n);
  rep(i,0,n){
    if(s[i]==t[i]){
      ok[i]=true;
      continue;
    }
    ll sn=s[i].size(),tn=t[i].size();
    while(l[i]<min(sn,tn)&&s[i][l[i]]==t[i][l[i]])l[i]++;
    while(r[i]<min(sn,tn)&&s[i][sn-r[i]-1]==t[i][tn-r[i]-1])r[i]++;
  }
  string x,y;
  rep(i,0,n){
    if(!ok[i]){
      x=s[i].substr(l[i],(ll)s[i].size()-l[i]-r[i]);
      y=t[i].substr(l[i],(ll)t[i].size()-l[i]-r[i]);
    }
  }
  rep(i,0,n){
    if(!ok[i]){
      if(x!=s[i].substr(l[i],(ll)s[i].size()-l[i]-r[i]))judge=false;
      if(y!=t[i].substr(l[i],(ll)t[i].size()-l[i]-r[i]))judge=false;
    }
  }
  while(1){
    set<char>st;
    bool sw=true;
    rep(i,0,n){
      if(ok[i])continue;
      if(l[i]==0)sw=false;
      else st.insert(s[i][l[i]-1]);
    }
    if(sw&&st.size()==1){
      rep(i,0,n)if(!ok[i])l[i]--;
      x=*st.begin()+x;
      y=*st.begin()+y;
    }
    else break;
  }
  while(1){
    set<char>st;
    bool sw=true;
    rep(i,0,n){
      if(ok[i])continue;
      if(r[i]==0)sw=false;
      else st.insert(s[i][s[i].size()-r[i]]);
    }
    if(sw&&st.size()==1){
      rep(i,0,n)if(!ok[i])r[i]--;
      x+=*st.begin();
      y+=*st.begin();
    }
    else break;
  }
  if(x.size()==0||y.size()==0)judge=false;
  else{
    const unsigned long long tmp_mod = (1ULL << 61) - 1;
    RandomNumberGenerator rng;
    unsigned long long base = rng(100000,1000000);
    //unsigned long long base = 100000;
    using RH = RollingHash<tmp_mod>;
    RH rhx(x,base);
    ll len=x.size();
    ll hash=rhx.get(0,x.size()-1);
    rep(i,0,n){
      RH rhs(s[i],base);
      if(ok[i])l[i]=s[i].size();
      rep(j,0,l[i]){
        if(j+x.size()>s[i].size())break;
        //cout<<s[i] spa j spa hash spa rhs.get(j,j+x.size()-1)<<endl;
        if(hash==rhs.get(j,j+x.size()-1))judge=false;
      }
    }
  }
  ans2(judge);
  if(judge){
    cout<<x<<endl;
    cout<<y<<endl;
  }
  return 0;
}