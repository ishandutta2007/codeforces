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
vector<ll>dx={1,0,-1,0,1,1,-1,-1};
vector<ll>dy={0,1,0,-1,1,-1,1,-1};
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
vector<vector<ll>>mp(65);
ll pow_t(ll x,ll y,bool t=false){
  if(!t&&y>=4){
    if(x<mp[y].size())return mp[y][x];
    else return 2*INF;
  }
  if(x==0)return 0;
  ll tmp=1;
  rep(i,0,y){
    if(LLONG_MAX/tmp<=x)return 2*INF;
    tmp*=x;
  }
  return tmp;
}
ll solve(ll lim,ll num){
  ll ret=0;
  ll l=0,r=1e9+1;
  while(r-l>=2){
    ll mid=(l+r)/2;
    if(pow_t(mid,num)>lim)r=mid;
    else l=mid;
  }
  return l;
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
  ll res=0,buf=0;
  bool judge = true;
  ll q;cin>>q;
  ll sz=61;
  vector<ll>t(sz);
  rep(i,2,sz){
    auto mp=factoring(i);
    ll cnt=0;
    for(auto z:mp){
      if(z.se>=2)cnt=-INF;
      cnt++;
    }
    if(cnt<0)continue;
    if(cnt&1)t[i]=1;
    else t[i]=-1;
  }
  rep(i,4,sz){
    for(ll j=0;pow_t(j,i,true)<=INF;j++){
      mp[i].PB(pow_t(j,i,true));
    }
    //debug(mp[i],mp[i].size());
  }
  while(q--){
    ll l,r;cin>>l>>r;
    ll ret=0;
    rep(i,2,sz)if(t[i]!=0)ret+=t[i]*(solve(r,i)-solve(l-1,i));
    cout<<ret-(l==1)<<endl;
  }
  return 0;
}