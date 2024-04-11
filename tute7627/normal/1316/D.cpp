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
#define rrep(i,n,m) for(ll i = (m) - 1; i >= (ll)(n); i--)
using ll = long long;
using ld = long double;
constexpr ll MOD1 = 1e9+7;
constexpr ll MOD9 = 998244353;
constexpr ll INF = 1e18;
using P = pair<ll, ll>;
template<typename T>
bool chmin(T &a,T b){if(a>b){a=b;return true;}else return false;}
template<typename T>
bool chmax(T &a,T b){if(a<b){a=b;return true;}else return false;}
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

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n;cin>>n;
  vector<string>ret(n,string(n,'-'));
  auto p=vec(n,n,MP(0LL,0LL));
  rep(i,0,n)rep(j,0,n){
    cin>>p[i][j].fi>>p[i][j].se;
    if(p[i][j].fi!=-1){
      p[i][j].fi--;p[i][j].se--;
    }
  }
  string c="DRUL";
  queue<pair<P,P>>que;
  rep(i,0,n)rep(j,0,n){
    if(p[i][j]==MP(i,j)){
      ret[i][j]='X';
      que.emplace(MP(i,j),MP(i,j));
      continue;
    }
    bool sw=false;
    if(p[i][j].fi!=-1)continue;
    rep(o,0,4){
      ll x=i+dx[o],y=j+dy[o];
      if(x<0||y<0||x>=n||y>=n)continue;
      if(p[i][j]==p[x][y]){
        sw=true;
        ret[i][j]=c[o];
      }
    }
    if(!sw){
      judge=false;
      break;
    }
  }
  string c2="ULDR";
  while(!que.empty()){
    auto q=que.front();
    que.pop();
    rep(i,0,4){
      ll x=q.fi.fi+dx[i],y=q.fi.se+dy[i];
      if(x<0||x>=n||y<0||y>=n)continue;
      if(ret[x][y]!='-'||p[x][y]!=q.se)continue;
      ret[x][y]=c2[i];
      que.emplace(MP(x,y),q.se);
    }
  }
  rep(i,0,n)rep(j,0,n)if(ret[i][j]=='-')judge=false;
  if(!judge)cout<<"INVALID"<<endl;
  else{
    cout<<"VALID"<<endl;
    debug(ret,n,n);
  }
  return 0;
}