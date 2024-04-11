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
using State = string::iterator;
template<typename T>
struct Parsing{
  Parsing(bool minus,ll sz):minus(minus),sz(sz){};
  bool minus=false;//minustrue
  ll sz;
  T solve(string &s){
    State itr = s.begin();
    return expr(itr);
  }
  T expr(State &itr){
    T val = term(itr);
    while(1){
      if(*itr == '?'){
        auto tmp=term(++itr);
        if(minus){
          for(auto &t:tmp){
            swap(t.fi,t.se);t.fi*=-1;t.se*=-1;
          }
        }
        T ret(min(sz+1,(ll)tmp.size()+(ll)val.size()),MP(-INF,INF));
        rep(i,0,val.size())rep(j,0,tmp.size()){
          if(i+j>=ret.size())continue;
          chmax(ret[i+j].fi,val[i].fi+tmp[j].fi);
          chmin(ret[i+j].se,val[i].se+tmp[j].se);
          if(i+j+1>=ret.size())continue;
          chmax(ret[i+j+1].fi,val[i].fi-tmp[j].se);
          chmin(ret[i+j+1].se,val[i].se-tmp[j].fi);
        }
        val=ret;
        //debug(val,val.size());
      }
      else break;
    }
    return val;
  }
  T term(State &itr){
    T val = fact(itr);
    return val;
  }
  T fact(State &itr){
    if(isdigit(*itr))return number(itr);
    assert(*itr == '(');
    itr++;
    T val = expr(itr);
    assert(*itr == ')');
    itr++;
    return val;
  }
  T number(State &itr){
    ll num = 0;
    while(isdigit(*itr)){
      num *= 10;
      num += *itr - '0';
      itr++;
    }
    T v(1,MP(num,num));
    return v;
  }
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  string s;cin>>s;
  ll p,m;cin>>p>>m;
  bool minus=false;
  if(p<m){
    swap(p,m);
    minus=true;
  }
  Parsing<vector<P>>par(minus,m);
  auto v=par.solve(s);
  //debug(v,m+1);
  cout<<v[m].fi<<endl;
  return 0;
}