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
#define PB push_back
#define EB emplace_back
#define rep(i,n,m) for(ll i = n; i < (ll)(m); i++)
#define rrep(i,n,m) for(ll i = n - 1; i >= (ll)(m); i--)
typedef int ll;
typedef long double ld;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const ll INF = 2e9;
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
  F func = [](T a, T b){
    ll z;
    if(a.se!=INF&&b.se!=INF)z=a.se+b.se;
    else z=INF;
    ll x=min({a.fi,z,b.fi});
    ll y=min(a.se,b.se);
    return MP(x,y);
  };
  T iden = MP(INF,INF); //identity element
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
};

int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  ll res=0,res1=INF,res2=-INF,buf=0;
  bool judge = true;
  ll n,m;cin>>n>>m;
  auto v=vec(9,n,MP(INF,INF));
  rep(i,0,n){
    ll x;cin>>x;
    buf=x;
    rep(j,0,9){
      if(x%10!=0){
        v[j][i].se=buf;
      }
      x/=10;
    }
  }
  vector<SegmentTree<P>>segtree(9,vector<P>());
  rep(i,0,9)segtree[i]=SegmentTree<P>(v[i]);
  rep(i,0,m){
    ll x,y,z;cin>>x>>y>>z;
    if(x==1){
      buf=z;
      rep(j,0,9){
        if(z%10!=0){
          segtree[j].update(y-1,MP(INF,buf));
        }
        else{
          segtree[j].update(y-1,MP(INF,INF));
        }
        z/=10;
      }
    }
    else{
      ll ret=INF;
      rep(j,0,9){
        chmin(ret,segtree[j].query(y-1,z).fi);
        //cout<<j spa segtree[j].query(y-1,z).fi<<endl;
      }
      /*rep(j,0,8)cout<<segtree[1].data[j].fi<<" ";
      cout<<endl;
      rep(j,0,8)cout<<segtree[1].data[j].se<<" ";
      cout<<endl;*/
      if(ret==INF)cout<<-1<<'\n';
      else cout<<ret<<'\n';
    }
  }
  return 0;
}