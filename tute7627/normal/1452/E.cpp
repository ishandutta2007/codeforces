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

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n,m,k;cin>>n>>m>>k;
  vector<ll>l(m),r(m);
  rep(i,0,m){
    cin>>l[i]>>r[i];
    l[i]--;
  }
  auto cr=vec(m,n-k+1,0LL);
  auto cross=[](ll a,ll b,ll c,ll d){
    return max(0LL,min(b,d)-max(a,c));
  };
  rep(i,0,m){
    rep(j,0,n-k+1){
      cr[i][j]=cross(j,j+k,l[i],r[i]);
    }
  }
  rep(i,0,n-k+1){
    vector<ll>a(n-k+2);
    vector<ll>b(n-k+2);
    ll sz=n-k+1;
    rep(j,0,m){
      ll x=cr[j][i];
      chmax(x,0);
      ll lt=min(sz-1,l[j]),rt=min(sz-1,max(0LL,r[j]-k));
      ll k=cr[j][lt];
      //cout<<lt spa rt spa cr[j][lt] spa cr[j][rt]<<endl;
      if(k>=x){
        if(lt>rt)swap(lt,rt);
        b[lt]+=cr[j][lt];
        b[rt]-=cr[j][lt];
        ll lp=max(0LL,lt-(k-x));
        ll rp=min(sz,rt+(k-x));
        b[0]+=x;
        b[lp]-=x;
        a[lp]+=1;
        a[lt]-=1;
        b[lp]+=k-lt;
        b[lt]-=k-lt;
        a[rt]-=1;
        a[rp]+=1;
        b[rt]+=k+rt;
        b[rp]-=k+rt;
        b[rp]+=x;
      }
      else{
        b[0]+=x;
      }
    }
    rep(j,0,n-k+1){
      a[j+1]+=a[j];
      b[j+1]+=b[j];
      chmax(res,a[j]*j+b[j]);
    }
  }
  cout<<res<<endl;
  return 0;
}