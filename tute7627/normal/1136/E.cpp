#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ALL(a)  (a).begin(),(a).end()
#define ALLR(a)  (a).rbegin(),(a).rend()
#define spa << " " <<
#define lfs <<fixed<<setprecision(10)<<
#define test cout<<"test"<<endl;
#define fi first
#define se second
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define rep(i,n,m) for(ll i = n; i < (ll)(m); i++)
#define rrep(i,n,m) for(ll i = n - 1; i >= (ll)(m); i--)
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
void debug(vector<vector<T>>v,ll h,ll w){for(ll i=0;i<h;i++)
{cout<<v[i][0];for(ll j=1;j<w;j++)cout spa v[i][j];cout<<endl;}};
void debug(vector<string>v,ll h,ll w){for(ll i=0;i<h;i++)
{for(ll j=0;j<w;j++)cout<<v[i][j];cout<<endl;}};
template<typename T>
void debug(vector<T>v,ll n){if(n!=0)cout<<v[0];
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
template<typename T>
struct LazySegmentTree{
  using F = function<T(T,T)>;
  vector<T> data, lazy; 
  ll n,lastlen = 1;
  F func = [](T a, T b){return a+b;};
  T iden = 0; //identity element
  F f_lazy = [](T a, T b){return a+b;};
  T iden_l = 0;
  F f_trans = [](T a, ll range){return a*(ll)range;};
  LazySegmentTree(vector<T> v){
    n = (ll)v.size();
    while(lastlen < n)lastlen *= 2;
    data.assign(lastlen*2-1,iden);
    lazy.assign(lastlen*2-1,iden_l);
    for(ll i=0;i<n;i++)data[i+lastlen-1] = v[i];
    for(ll i=lastlen-2;i>=0;i--){
      data[i] = func(data[2*i+1], data[2*i+2]);
    }
  }
  void eval(ll k, ll left, ll right){
    if(lazy[k] != iden_l){
      data[k] = f_lazy(data[k],
      f_trans(lazy[k],right-left));
      if(k <= lastlen - 2){
        lazy[2*k+1] = f_lazy(lazy[2*k+1],lazy[k]);
        lazy[2*k+2] = f_lazy(lazy[2*k+2],lazy[k]);
      }
      lazy[k] = iden_l;
    }
  }
  void update(ll a,ll b,T x,ll point=0LL,
  ll left=0LL,ll right=-1LL){
    if(right<0)right=lastlen;
    eval(point,left,right);
    if(b <= left || right <= a);
    else if(a <= left && right <= b ){
      lazy[point] = x;
      eval(point,left,right);
    }
    else{
      update(a,b,x,point*2+1, left, (left+right)/2);
      update(a,b,x,point*2+2, (left+right)/2, right);
      data[point] = func(data[2*point+1], data[2*point+2]);
    }      
  }
  T query(ll a,ll b,ll point=0LL,ll left=0LL,ll right=-1LL){
    if(right<0)right=lastlen;
    T ret = iden;
    eval(point,left,right);
    if(b <= left || right <= a);
    else if(a <= left && right <= b ){
      ret = func(ret,data[point]);
    }
    else{
      T p=query(a,b,point*2+1, left, (left+right)/2);
      T q=query(a,b,point*2+2, (left+right)/2, right);
      data[point] = func(data[2*point+1], data[2*point+2]);
      ret = func(ret,p);
      ret = func(ret,q);
    }      
    return ret;
  }
  void print(){
    ll num=0;
    for(ll i=lastlen;i>0;i/=2)num++;
    ll tmp=1;
    for(ll i=0;i<num;i++,tmp*=2){
      for(ll j=0;j<tmp;j++){
        if(data[tmp-1+j]==iden)cout<<"x"<<" ";
        else cout<<data[tmp-1+j]<<" ";
      };
      cout<<"|";
    }
    cout<<endl;
    tmp=1;
    for(ll i=0;i<num;i++,tmp*=2){
      for(ll j=0;j<tmp;j++){
        if(lazy[tmp-1+j]==iden_l)cout<<"x"<<" ";
        else cout<<lazy[tmp-1+j]<<" ";
      }
      cout<<"|";
    }
    cout<<endl;
  }
};
int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  ll res=0,res1=INF,res2=-INF,buf=0;
  bool judge = true;
  ll n;cin>>n;
  vector<ll>a(n);
  rep(i,0,n)cin>>a[i];
  LazySegmentTree<ll>seg(a);
  vector<ll>k(n-1);
  rep(i,0,n-1)cin>>k[i];
  set<ll>st;
  rep(i,0,n-1){
    if(k[i]!=a[i+1]-a[i])st.insert(i);
  }
  st.insert(n-1);
  ll q;cin>>q;
  while(q--){
    char c;cin>>c;
    ll x,y;cin>>x>>y;
    if(c=='s'){
      cout<<seg.query(x-1,y)<<endl;
    }
    else{
      if(y==0)continue;
      x--;
      ll tmp=x;
      while(1){
        ll idx=*st.lower_bound(x);
        seg.update(x,idx+1,y);
        if(idx==n-1)break;
        ll val=seg.query(idx+1,idx+2)-seg.query(idx,idx+1);
        y=k[idx]-val;
        if(y==0){
          st.erase(idx);
          break;
        }
        else if(y<0)break;
        else{
          x=idx+1;
          st.erase(idx);
        }
        //cout<<idx spa val spa x spa y<<endl;
      }
      if(tmp>=1)st.insert(tmp-1);
    }
    //rep(i,0,n)cout<<seg.query(i,i+1)<<" ";
    //cout<<endl;
  }
  return 0;
}