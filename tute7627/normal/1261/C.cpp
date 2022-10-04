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
#define rep(i,n,m) for(ll i = (n); i < (ll)(m); i++)
#define rrep(i,n,m) for(ll i = (m) - 1; i >= (ll)(n); i--)
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
struct z{
  ll x,y,d;
  z(ll a,ll b,ll c):x(a),y(b),d(c){};
};
void bfs(ll h,ll w,vector<string>&a,vector<vector<ll>>&dist){
  rep(i,0,h)rep(j,0,w)dist[i][j]=INF;
  queue<struct z>que;
  rep(i,0,h)rep(j,0,w)if(a[i][j]=='X')que.emplace(i,j,0);
  while(!que.empty()){
    auto pos = que.front();
    que.pop();
    if(dist[pos.x][pos.y]!=INF)continue;
    dist[pos.x][pos.y]=pos.d;
    for(ll i=0;i<8;i++){
      ll x=pos.x+dx[i],y=pos.y+dy[i],d=pos.d+1;
      if(x<0||x>=h||y<0||y>=w)continue;
      que.emplace(x,y,d);
    }
  }
}
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
    if(x1>x2)swap(x1,x2);
    if(y1>y2)swap(y1,y2);
    if(x1<0||x2>=h||y1<0||y2>=w)return -1;
    else return data[x2+1][y2+1]-data[x2+1][y1]-data[x1][y2+1]+data[x1][y1];
  }
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  //cout<<fixed<<setprecision(10);
  ll res=0,buf=0;
  bool judge = true;
  ll h,w;cin>>h>>w;
  vector<string>a(h);
  rep(i,0,h)cin>>a[i];
  auto b=vec(h,w,0LL);
  rep(i,0,h)rep(j,0,w)b[i][j]=(a[i][j]=='X');
  Sum2D<ll>f(b);
  auto mx=vec(h,w,0LL);
  rep(i,0,h)rep(j,0,w){
    if(a[i][j]=='.'){
      mx[i][j]=0;continue;
    }
    ll l=0,r=(ll)1e6;
    while(r-l>=2){
      ll mid=(l+r)/2;
      bool tmp=false;
      if(f.query(i-mid,j-mid,i,j)==(mid+1)*(mid+1))
      if(f.query(i,j,i+mid,j+mid)==(mid+1)*(mid+1))
      if(f.query(i,j,i-mid,j+mid)==(mid+1)*(mid+1))
      if(f.query(i,j,i+mid,j-mid)==(mid+1)*(mid+1))
      tmp=true;
      if(tmp)l=mid;
      else r=mid;
    }
    mx[i][j]=l;
  }
  //debug(mx,h,w);
  //debug(b,h+1,w+1);
  ll l=0,r=(ll)1e6;
  vector<string>start=a;
  vector<vector<ll>>dist(h,vector<ll>(w,0));
  while(r-l>=2){
    ll mid=(l+r)/2;
    rep(i,0,h)rep(j,0,w){
      if(mx[i][j]>=mid&&a[i][j]=='X')start[i][j]='X';
      else start[i][j]='.'; 
    }
    bfs(h,w,start,dist);
    bool judge=true;
    rep(i,0,h)rep(j,0,w){
      if((a[i][j]=='X')^(dist[i][j]<=mid))judge=false;
    }
    if(judge)l=mid;
    else r=mid;
  }
  rep(i,0,h)rep(j,0,w){
    if(mx[i][j]>=l&&a[i][j]=='X')start[i][j]='X';
    else start[i][j]='.';
  }
  cout<<l<<endl;
  rep(i,0,h)cout<<start[i]<<endl;
  return 0;
}