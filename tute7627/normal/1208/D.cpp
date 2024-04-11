#include<bits/stdc++.h>
using namespace std;

#define ALL(a)  (a).begin(),(a).end()
#define ALLR(a)  (a).rbegin(),(a).rend()
#define spa << " " <<
#define lfs <<fixed<<setprecision(10)<<
#define test cout<<"test"<<endl;
#define fi first
#define se second
#define MP make_pair
#define rep(i,n,m) for(ll i = n; i < (ll)(m); i++)
#define rrep(i,n,m) for(ll i = n - 1; i >= (ll)(m); i--)
typedef long long ll;
typedef long double ld;
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
void debug(vector<vector<T>>v,ll h,ll w){for(ll i=0;i<h;i++)
{cout<<v[i][0];for(ll j=1;j<w;j++)cout spa v[i][j];cout<<endl;}};
void debug(vector<string>v,ll h,ll w){for(ll i=0;i<h;i++)
{for(ll j=0;j<w;j++)cout<<v[i][j];cout<<endl;}};
template<typename T>
void debug(vector<T>v,ll n){cout<<v[0];
for(ll i=1;i<n;i++)cout spa v[i];cout<<endl;};
template<typename T>
vector<vector<T>>vec(ll x, ll y, T w){
  vector<vector<T>>v(x,vector<T>(y,w));return v;}
ll gcd(ll x,ll y){ll r;while(y!=0&&(r=x%y)!=0){x=y;y=r;}return y==0?x:y;}
template<typename T>
void emp(map<T,ll>&m, T x){m.emplace(x,0).first->second++;}

template<typename T>
struct SegmentTree{
  using F = function<T(T,T)>;
  vector<T> data;
  ll n,lastlen = 1;
  F func = [](T a, T b){return a + b;};
  T iden = 0; //identity element
  SegmentTree(vector<T> v){
    n = (ll)v.size();
    while(lastlen < n)lastlen *= 2;
    data.assign(lastlen*2-1,iden);
    for(ll i=0;i<n;i++)data[i+lastlen-1] = v[i];
    for(ll i=lastlen-2;i>=0;i--){
      data[i] = func(data[2*i+1], data[2*i+2]);
    }
  }
  void add(ll point, T x){
    point+=lastlen-1;
    data[point] = x + data[point];
    while(point!=0){
      point=(point-1)/2;
      data[point]=func(data[2*point+1],data[2*point+2]);
    }
  }
  T query(ll a,ll b,ll point=0,ll left=0,ll right=-1){
    if(right<0)right=lastlen;
    T ret = iden;
    if(b <= left || right <= a);
    else if(a <= left && right <= b ){
      ret = func(ret, data[point]);
    }
    else{
      T p,q;
      p = query(a,b,point*2+1,left, (left+right)/2);
      q = query(a,b,point*2+2,(left+right)/2, right);
      ret = func(ret,p);
      ret = func(ret,q);
    }      
    return ret;
  }

  T lower_bound(ll p,ll x){
    ll sumbuf=iden, l=p,r=p+1;
    p = p + lastlen - 1;
    while(1){
      if(func(sumbuf,data[p]) < x){
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
      else if(func(sumbuf,data[2*p+1]) < x){
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
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  ll res=0,res1=INF,res2=-INF,buf=0;
  bool judge = true;
  ll n;cin>>n;
  vector<ll>s(n);
  rep(i,0,n)cin>>s[i];
  vector<ll>ret(n);
  SegmentTree<ll>segtree(vector<ll>(n,0LL));
  rep(i,0,n){
    segtree.add(i,i+1);
  }
  rrep(i,n,0){
    ll x=segtree.lower_bound(0,s[i]+1);
    segtree.add(x,-x-1);
    ret[i]=x+1;
  }
  debug(ret,n);
  return 0;
}