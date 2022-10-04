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
vector<pair<char,ll>>compress(string &s){
  vector<pair<char,ll>>ret;
  ll cnt=1;
  for(ll i=0;i<s.size();i++){
    if(i==(ll)s.size()-1||s[i]!=s[i+1]){
      ret.emplace_back(s[i],cnt);
      cnt=1;
    }
    else cnt++;
  }
  return ret;
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n;cin>>n;
  string s;cin>>s;
  {
    ll idx=0;
    while(idx<n&&s[idx]=='?')idx++;
    if(idx==n)rep(i,0,idx)s[i]='0';
    else rep(i,0,idx)s[i]=s[idx];
  }
  map<ll,P>mp;
  {
    auto com=compress(s);
    char pre='2';
    ll now=-1;
    for(auto c:com){
      if(c.fi=='?'){
        mp[now].se=c.se;
      }
      else if(c.fi==pre){
        mp[now].fi+=mp[now].se+c.se;
        mp[now].se=0;
      }
      else{
        now++;
        pre=c.fi;
        mp[now].fi=c.se;
      }
    }
  }
  vector<ll>ret(n);
  rep(i,1,n+1){
    auto itr=mp.begin();
    ll add=0;
    ll preadd=0;
    ll cnt=0;
    while(itr!=mp.end()){
      auto v=itr->se;
      //cout<<i spa add spa preadd spa v spa cnt spa mp.size()<<endl;
      if(preadd+v.fi+v.se<i){
        if(itr!=mp.begin()){
          auto pr=prev(itr);
          pr->se.fi+=pr->se.se;
          pr->se.se=0;
        }
        if(itr!=mp.end()){
          auto pr=next(itr);
          pr->se.fi+=v.se;
        }
        preadd=0;
        add=0;
        itr=mp.erase(itr);
      }
      else{
        ll k=(add+v.fi+v.se)/i;
        ll rem=add+v.fi+v.se-k*i;
        cnt+=k;
        add=min(v.se,rem);
        preadd=v.se;
        itr++;
      }
    }
    ret[i-1]=cnt;
  }
  debug(ret,n);
  return 0;
}