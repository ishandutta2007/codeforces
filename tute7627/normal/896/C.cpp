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
ll modpow(ll x,ll k,ll m){
  x%=m;
  ll now=x,ret=1;
  while(k){
    if(k&1)ret=(ret*now)%m;
    now=(now*now)%m;
	k>>=1;
  }
  return ret;
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n,m,seed,vmax;cin>>n>>m>>seed>>vmax;
  auto rnd=[&](){
    ll ret=seed;
    seed=(seed*7+13)%MOD1;
    return ret;
  };
  vector<ll>a(n);
  rep(i,0,n)a[i]=rnd()%vmax+1;
  map<P,ll>mp;
  rep(i,0,n)mp[MP(i,i+1)]=a[i];
  //debug(a,n);
  while(m--){
    ll op=rnd()%4+1;
    ll l=rnd()%n+1;
    ll r=rnd()%n+1;
    if(l>r)swap(l,r);
    ll x;
    if(op==3)x=(rnd()%(r-l+1))+1;
    else x=(rnd()%vmax)+1;
    ll y=-1;
    if(op==4)y=(rnd()%vmax)+1;
    l--;
    //if(m==0)op=3,l=0,r=9,x=8;
    auto itr=mp.lower_bound(MP(l,l));
    if(itr==mp.end()||itr->fi.fi>l)itr--;
    //cout<<itr->fi spa itr->se spa l<<endl;
    //cout<<op spa l spa r spa x spa y<<endl;
    if(op==1){
      if(itr->fi.fi<l){
        ll nl=itr->fi.fi;
        ll nr=itr->fi.se;
        ll v=itr->se;
        mp.erase(itr);
        mp[MP(nl,l)]=v;
        mp[MP(l,nr)]=v;
        itr=mp.find(MP(l,nr));
      }
      while(itr!=mp.end()&&itr->fi.se<=r){
        itr->se+=x;
        itr++;
      }
      if(itr!=mp.end()&&itr->fi.fi<r){
        ll nl=itr->fi.fi;
        ll nr=itr->fi.se;
        ll v=itr->se;
        mp.erase(itr);
        mp[MP(nl,r)]=v+x;
        mp[MP(r,nr)]=v;
      }
    }
    else if(op==2){
      if(itr->fi.fi<l){
        ll nl=itr->fi.fi;
        ll nr=itr->fi.se;
        ll v=itr->se;
        mp.erase(itr);
        mp[MP(nl,l)]=v;
        mp[MP(l,nr)]=v;
        itr=mp.find(MP(l,nr));
      }
      while(itr!=mp.end()&&itr->fi.se<=r){
        itr=mp.erase(itr);
      }
      if(itr!=mp.end()&&itr->fi.fi<r){
        ll nl=itr->fi.fi;
        ll nr=itr->fi.se;
        ll v=itr->se;
        mp.erase(itr);
        mp[MP(r,nr)]=v;
      }
      mp[MP(l,r)]=x;
    }
    else if(op==3){
      vector<P>ret;
      while(itr!=mp.end()&&itr->fi.fi<r){
        ll nl=itr->fi.fi;
        ll nr=itr->fi.se;
        ll v=itr->se;
        chmax(nl,l);
        chmin(nr,r);
        ret.EB(v,nr-nl);
        //cout<<v spa nr-nl<<endl;
        itr++;
      }
      sort(ALL(ret));
      for(auto z:ret){
        if(x<=z.se){
          cout<<z.fi<<endl;
          break;
        }
        x-=z.se;
      }
    }
    else{
      ll ret=0;
      while(itr!=mp.end()&&itr->fi.fi<r){
        ll nl=itr->fi.fi;
        ll nr=itr->fi.se;
        ll v=itr->se;
        chmax(nl,l);
        chmin(nr,r);
        ret+=(modpow(v,x,y)%y)*(nr-nl);
        ret%=y;
        itr++;
      }
      cout<<ret<<endl;
    }
    //for(auto z:mp)cout<<z.fi spa z.se<<"|";cout<<endl;
  }
  return 0;
}