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
template<typename T, typename F>
struct DisjointSparseTable{
  int n;
  vector<vector<T>>data;
  const F func;
  DisjointSparseTable(vector<T>&v, const F &f):func(f),n(v.size()){
    int num=0;
    while((1<<num)<v.size())num++;
    data.assign(num+5,vector<T>(n+1, T()));
    if(n>=1)data[0][n-1]=v[n-1];
    for(int i=1;i<n;i++){
      int k = __builtin_ctz(i);
      data[k][i-1]=v[i-1];
      if(i!=n)data[k][i]=v[i];
      int l=i-(1<<k),r=min(n,i+(1<<k));
      for(int j=i-2;j>=l;j--)data[k][j]=func(v[j],data[k][j+1]);
      for(int j=i+1;j<r;j++)data[k][j]=func(data[k][j-1],v[j]);
    }
  }
  T query(int l,int r){//[l,r)
    r--;
    if(l==r)return data[0][l];
    ll k=31-__builtin_clz(l^r);
    return func(data[k][l],data[k][r]);
  }
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  using real=double;
  ll n,q;cin>>n>>q;
  vector<ll>a(n);
  rep(i,0,n)cin>>a[i];
  auto fmx=[&](ll x,ll y){return max(x,y);};
  DisjointSparseTable<ll,decltype(fmx)>dst(a,fmx);
  q++;
  vector<ll>l(q),r(q);
  vector<real>p(q);
  vector<vector<real>>dp(q);
  vector<bool>used(q,false);
  vector<ll>init(q);
  rep(i,0,q){
    if(i+1<q)cin>>l[i]>>r[i]>>p[i],l[i]--;
    else l[i]=0,r[i]=n,p[i]=0;
  }
  //debug(init,q);
  {
    vector<ll>ord(q);
    iota(ALL(ord),0);
    sort(ALL(ord),[&](ll i,ll j){return r[i]-l[i]<r[j]-l[j];});
    auto nl=l,nr=r,ninit=init;
    auto np=p;
    rep(i,0,q){
      l[i]=nl[ord[i]];
      r[i]=nr[ord[i]];
      p[i]=np[ord[i]];
      init[i]=dst.query(l[i],r[i]);
    }
  }
  rep(i,0,q){
    dp[i]={1.0};
    rep(j,0,i){
      if(used[j])continue;
      if(l[j]<l[i]||r[j]>r[i])continue;
      //cout<<i spa j<<endl;
      used[j]=true;
      vector<real>ndp(dp[i].size()+dp[j].size()-1);
      ll base=max(init[i],init[j]);
      rep(x,0,dp[i].size())rep(y,0,dp[j].size()){
        ndp[max(init[i]+x,init[j]+y)-base]+=dp[i][x]*dp[j][y];
      }
      dp[i].swap(ndp);
      init[i]=base;
    }
    //debug(dp[i],dp[i].size());
    vector<real>ndp(dp[i].size()+1);
    rep(j,0,dp[i].size()){
      ndp[j+1]+=dp[i][j]*p[i];
      ndp[j]+=dp[i][j]*(1-p[i]);
    }
    dp[i].swap(ndp);
    //debug(dp[i],dp[i].size());
    //cout<<init[i] spa l[i] spa r[i] spa p[i]<<endl;
  }
  //debug(dp[q-1],dp[q-1].size());
  //cout<<init[q-1]<<endl;
  real ret=0;
  rep(i,0,dp[q-1].size()){
    ret+=(init[q-1]+i)*dp[q-1][i];
  }
  lfs<<ret<<endl;
  return 0;
}