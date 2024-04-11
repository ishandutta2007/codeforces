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
int solve(){
  ll res=0,buf=0;
  bool judge = true;
  ll n,s;cin>>n>>s;
  s+=n;
  if(s>n*(n+1)/2){
    cout<<"No"<<endl;
    return 0;
  }
  ll l=0,r=n-1;
  auto f=[&](ll x){
    ll now=n;
    ll tmp=1;
    ll ret=0;
    ll dep=1;
    while(now){
      ret+=min(tmp,now)*dep;
      now-=min(tmp,now);
      tmp*=x;
      dep++;
    }
    return ret;
  };
  if(f(n-1)>s){
    cout<<"No"<<endl;
    return 0;
  }
  
  while(r-l>=2){
    ll mid=(l+r)/2;
    if(f(mid)<=s)r=mid;
    else l=mid;
  }
  /*cout<<r spa f(1) spa f(2)<<endl;
  return 0;*/
  vector<ll>cnt(n);
  rep(i,0,n)cnt[i]=1;
  ll now=1;
  ll val=n*(n+1)/2-s;
  rrep(i,1,n){
    if(val<0)break;
    if(cnt[now]>=cnt[now-1]*r)now++;
    while(val>0&&cnt[i]>0){
      if(val>=i-now){
        val-=i-now;
        cnt[i]--;
        cnt[now]++;
      }
      else{
        cnt[i]--;
        cnt[i-val]++;
        val=0;
      }
    }
  }
  vector<ll>p(n-1);
  vector<ll>dim(n);
  vector<ll>dep(n);
  ll par_now=0;
  ll idx_now=1;
  rep(i,1,n){
    //debug(dep,n);
    //cout<<par_now<<endl;
    while(dep[par_now]!=i-1)par_now++;
    rep(j,0,cnt[i]){
      dep[idx_now]=i;
      if(dim[par_now]>=r)par_now++;
      dim[par_now]++;
      p[idx_now-1]=par_now+1;
      idx_now++;
    }
    if(idx_now==n)break;
  }
  if(r>=3){
    cout<<"No"<<endl;
    return 0;
  }
  cout<<"Yes"<<endl;
  debug(p,n-1);
  //debug(cnt,n);
  return 0;
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll t;cin>>t;
  while(t--){
    solve();
  }
  return 0;
}