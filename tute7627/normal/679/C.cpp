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
using ll = int;
using ld = long double;
const ll MOD1 = 1e9+7;
const ll MOD9 = 998244353;
const ll INF = 1e9;
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
struct UnionFind {
  vector<ll> data;
  ll num;
  UnionFind(ll size) : data(size, -1) ,num(size){ }
  bool unite(ll x, ll y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
	  num--;
    }
    return x != y;
  }
  bool find(ll x, ll y) {
    return root(x) == root(y);
  }
  ll root(ll x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  ll size(ll x) {
    return -data[root(x)];
  }
};
template<typename T>
struct Sum2D{
  vector<vector<T>>data;
  ll h,w;
  Sum2D(vector<vector<T>>&a):h(a.size()),w(a[0].size()){
    data.assign(h+1,vector<T>(w+1,0));
    for(ll i=0;i<h;i++)for(ll j=0;j<w;j++){
      data[i+1][j+1]=a[i][j];
    }
    for(ll i=0;i<h;i++)for(ll j=0;j<w+1;j++)data[i+1][j]+=data[i][j];
    for(ll i=0;i<h+1;i++)for(ll j=0;j<w;j++)data[i][j+1]+=data[i][j];
  }
  T query(ll x1,ll y1,ll x2, ll y2){
    //if(x1>x2)swap(x1,x2);if(y1>y2)swap(y1,y2);
    if(x1<0||x2>=h||y1<0||y2>=w||x1>x2||y1>y2)return 0;
    else return data[x2+1][y2+1]-data[x2+1][y1]-data[x1][y2+1]+data[x1][y1];
  }
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n,k;cin>>n>>k;
  UnionFind uf(n*n);
  vector<string>s(n);
  rep(i,0,n)cin>>s[i];
  rep(i,0,n)rep(j,0,n-1)if(s[i][j]=='.'&&s[i][j+1]=='.')uf.unite(i*n+j,i*n+j+1);
  rep(i,0,n-1)rep(j,0,n)if(s[i][j]=='.'&&s[i+1][j]=='.')uf.unite(i*n+j,(i+1)*n+j);
  vector<ll>xl(n*n,INF);
  vector<ll>xr(n*n,-INF);
  vector<ll>yl(n*n,INF);
  vector<ll>yr(n*n,-INF);
  rep(i,0,n)rep(j,0,n){
    if(s[i][j]=='X')continue;
    chmin(xl[uf.root(i*n+j)],i);
    chmax(xr[uf.root(i*n+j)],i);
    chmin(yl[uf.root(i*n+j)],j);
    chmax(yr[uf.root(i*n+j)],j);
  }
  ll sz=n-k+1;
  auto cum=vec(sz+1,sz+1,0);
  rep(i,0,n*n){
    if(s[i/n][i%n]=='X')continue;
    if(uf.root(i)==i){
      ll x=max(0,xr[i]-k+1);
      ll y=max(0,yr[i]-k+1);
      ll xm=min(sz,xl[i]+1);
      ll ym=min(sz,yl[i]+1);
      if(x>=xm||y>=ym)continue;
      //cout<<i spa xl[i] spa yl[i] spa xr[i] spa yr[i]<<endl;
      ll szz=uf.size(i);
      cum[x][y]+=szz;
      cum[xm][y]-=szz;
      cum[x][ym]-=szz;
      cum[xm][ym]+=szz;
    }
  }
  rep(i,0,sz+1)rep(j,0,sz)cum[i][j+1]+=cum[i][j];
  rep(i,0,sz)rep(j,0,sz+1)cum[i+1][j]+=cum[i][j];
  //debug(cum,sz,sz);
  auto vx=vec(n,n,0);
  rep(i,0,n)rep(j,0,n)vx[i][j]=(s[i][j]=='X');
  auto cumx=Sum2D<int>(vx);
  vector<bool>t(n*n);
  queue<int>que;
  rep(i,0,sz)rep(j,0,sz){
    ll ret=0;
    auto f=[&](ll x,ll y){
      if(x<0||y<0||x>=n||y>=n||s[x][y]=='X')return;
      //cout<<i spa j spa x spa y<<endl;
      ll r=uf.root(x*n+y);
      if(!t[uf.root(r)]){
        ret+=uf.size(r);
        que.push(r);
        t[r]=true;
      }
    };
    rep(o,0,k){
      f(i-1,j+o);
      f(i+o,j+k);
      f(i+k,j+o);
      f(i+o,j-1);
    }
    while(!que.empty()){
      t[que.front()]=false;
      que.pop();
    }
    //cout<<i spa j spa ret spa cumx.query(i,j,i+k-1,j+k-1) spa cum[i][j]<<endl;
    chmax(res,ret+cumx.query(i,j,i+k-1,j+k-1)+cum[i][j]);
  }
  cout<<res<<endl;
  return 0;
}