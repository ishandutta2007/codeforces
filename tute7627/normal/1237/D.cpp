#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ALL(a)  (a).begin(),(a).end()
#define ALLR(a)  (a).rbegin(),(a).rend()
#define spa << " " <<
#define test cout<<"test"<<endl;
#define fi first
#define se second
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define rep(i,n,m) for(ll i = n; i < (ll)(m); i++)
#define rrep(i,n,m) for(ll i = m - 1; i >= (ll)(n); i--)
using ll = long long;
using ld = long double;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const ll INF = 1e18;
using P = pair<ll, ll>;
template<typename T>
void chmin(T &a,T b){if(a>b)a=b;}
template<typename T>
void chmax(T &a,T b){if(a<b)a=b;}
void pmod(ll &a,ll b){a=(a+b)%MOD;}
void pmod(ll &a,ll b,ll c){a=(b+c)%MOD;}
void qmod(ll &a,ll b){a=(a*b)%MOD;}
void qmod(ll &a,ll b,ll c){a=(b*c)%MOD;}
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
template<typename T>
struct SegmentTree{
  using F = function<T(T,T)>;
  vector<T> data;
  ll n,lastlen = 1;
  F func = [](T a, T b){return a < b ? a : b;};
  function<bool(T,T)> check = [](T a, T b){return a <= b;};
  T iden = INT_MAX; //identity element
  SegmentTree(vector<T> v){
    n = (ll)v.size();
    while(lastlen < n)lastlen *= 2;
    data.assign(lastlen*2-1,iden);
    for(ll i=0;i<n;i++)data[i+lastlen-1] = v[i];
    for(ll i=lastlen-2;i>=0;i--){
      data[i] = func(data[2*i+1], data[2*i+2]);
    }
  }
  void update(ll point, T x){
    point+=lastlen-1;
    data[point] = x;
    while(point!=0){
      point=(point-1)/2;
      data[point]=func(data[2*point+1],data[2*point+2]);
    }
  }
  T query(ll l,ll r){
    T left = iden, right = iden;
    l+=lastlen-1, r+=lastlen-1;
    while(l != r){
      if(~l&1)left = func(left, data[l++]);
      if(~r&1)right = func(data[--r], right);
      l >>= 1,r >>= 1;
    }
    return func(left, right);
  }
  T operator[](ll x){
    return data[lastlen-1+x];
  }
  void print(){
    for(ll i=0;i<n;i++){
      if(i!=0)cout<<" ";
      cout<<data[lastlen-1+i];
    }
    cout<<endl;
  }
  T lower_bound(ll p,T x){
    ll sumbuf=iden, l=p,r=p+1;
    p = p + lastlen - 1;
    while(1){
      if(!check(func(sumbuf,data[p]), x)){
        if(p%2==1){
          p = (p-1)/2;
          r = l + (r-l)*2;
        }
        else if(r>=n){
          return n;
        }
        else{
          func(sumbuf,data[p]);
          p >>= 1;
          ll x = r + (r-l)*2; 
          l = r; r = x;
        }
      }
      else if(p >= lastlen - 1)return r - 1;
      else if(!check(func(sumbuf,data[2*p+1]),x)){
        sumbuf = func(sumbuf, data[2*p+1]);
        p = 2*p+2; l = (r+l)/2;
      }
      else{
        p = 2*p+1; r = (r+l)/2;
      }
    }  
  }
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  //cout<<fixed<<setprecision(10);
  ll res=0,buf=0;
  bool judge = true;
  ll n;cin>>n;
  vector<ll>a(n);
  rep(i,0,n)cin>>a[i];
  SegmentTree<ll>seg(a);
  vector<ll>ret(n);
  rep(i,0,n){
    ll k=seg.lower_bound(i,(a[i]+1)/2-1);
    if(k==n)k=seg.lower_bound(0,(a[i]+1)/2-1);
    //cout<<k spa (a[i]+1)/2-1<<endl;
    ret[i]=k;
  }
  //debug(ret,n);
  ll minbuf=INF;
  vector<ll>x(n);
  rrep(i,0,n){
    ll len=INF;
    if(ret[i]==i)len=n;
    else if(ret[i]!=n)len=(ret[i]+n-i)%n;
    if(len<minbuf)minbuf=len;
    x[i]=minbuf;
    if(minbuf!=INF)minbuf++;
  }
  rrep(i,0,n){
    chmin(x[i],minbuf);
    if(minbuf!=INF)minbuf++;
  }
  //debug(ret,n);
  rep(i,0,n)if(x[i]==INF)x[i]=-1;
  debug(x,n);
  return 0;
}