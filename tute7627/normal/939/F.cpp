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
template<typename T> 
struct SWAG{
  stack<pair<T,T>>st_front,st_back;
  T func(T x, T y){return min(x,y);}
  void push(T x){
    if(st_back.empty())st_back.emplace(x,x);
    else st_back.emplace(x,func(st_back.top().second,x));
  }
  void pop(){
    if(st_front.empty()){
      while(!st_back.empty()){
       if(st_front.empty())st_front.emplace(st_back.top().first,st_back.top().first);
       else st_front.emplace(st_back.top().first,func(st_back.top().first, st_front.top().second));
       st_back.pop();
      }
    }
    st_front.pop();
  }
  T query(){
    if(st_front.empty())return st_back.top().second;
    else if(st_back.empty())return st_front.top().second;
    else return func(st_front.top().second, st_back.top().second);
  }
  bool empty(){
    return st_front.empty() && st_back.empty();
  }
  int size(){
    return st_front.size() + st_back.size();
  }
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n,k;cin>>n>>k;
  vector<ll>l(k+1),r(k+1);
  rep(i,0,k)cin>>l[i]>>r[i];
  l[k]=2*n;
  auto dp=make_v(k+1,n+1,2,INF);
  dp[0][0][0]=0;
  //dp[i][j][o]    
  //j:
  //o0:,1:,
  //:(+0,0flip)/(+0~r-l,2flip)/(+0~r-l,1flip)
  //:(+n,0flip)/(+0~r-l,2flip)/(+0~r-l,1flip)
  rep(i,0,k){
    ll dif=r[i]-l[i];
    //cout<<dif<<endl;
      vector<deque<ll>>deq(2);
    rep(j,0,n+1){
      chmin(dp[i+1][j][0],dp[i][j][0]);
      if(j+dif<=n)chmin(dp[i+1][j+dif][1],dp[i][j][1]);
      rep(o,0,2){
        while(!deq[o].empty()&&dp[i][deq[o].back()][o]>=dp[i][j][o])deq[o].pop_back();
        deq[o].push_back(j);
      }
      //cout<<j spa dif spa swag[0].size() spa swag[1].size()<<endl;
      rep(o,0,2)chmin(dp[i+1][j][o],min(dp[i][deq[o][0]][o]+2,dp[i][deq[o^1][0]][o^1]+1));
      rep(o,0,2)if(deq[o][0]==j-dif)deq[o].pop_front();
    }
    dif=l[i+1]-r[i];
    //cout<<i<<endl;debug(dp[i+1],n+1,2);
    rrep(j,0,n+1){
      ll tmp=dp[i+1][j][1];
      dp[i+1][j][1]=INF;
      if(j+dif<=n)chmin(dp[i+1][j+dif][1],tmp);
    }
    //cout<<i<<endl;debug(dp[i+1],n+1,2);
  }
  res=min(dp[k][n][0],dp[k][n][1]);
  if(res==INF)cout<<"Hungry"<<endl;
  else{
    cout<<"Full"<<endl;
    cout<<res<<endl;
  }
  return 0;
}