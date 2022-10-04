#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define lfs cout<<fixed<<setprecision(10)
#define ALL(a)  (a).begin(),(a).end()
#define ALLR(a)  (a).rbegin(),(a).rend()
#define spa << " " <<
#define test cout<<"test"<<endl;
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
ll MAX_V = 3e3 + 5;
vector<ll>t(MAX_V);
vector<vector<ll>>num(MAX_V,vector<ll>(MAX_V,0LL));
ll N;
ll dfs(ll k,vector<vector<ll>>&g,ll par){
  t[k]=1;
  ll ret=0;
  for(ll i=0;i<g[k].size();i++){
    if(t[g[k][i]]==0){
      num[k][g[k][i]]=dfs(g[k][i],g,k);
      ret+=num[k][g[k][i]];
    }
  }
  if(par!=-1)num[k][par]=N-1-ret;
  return ret+1;
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n;cin>>n;N=n;
  vector<vector<ll>>g(n);
  rep(i,0,n-1){
    ll u,v;cin>>u>>v;u--;v--;
    g[u].PB(v);
    g[v].PB(u);
  }
  dfs(0,g,-1);
  auto dp=vec(n,n,MT(-1LL,-1LL,-1LL));
  queue<P>que;
  rep(i,0,n){
    for(auto to:g[i]){
      if(i>to)continue;
      dp[i][to]=MT(num[i][to]*num[to][i],to,i);
      que.emplace(i,to);
      //cout<<i spa to spa get<0>(dp[i][to])<<endl;
    }
  }
  while(!que.empty()){
    ll u,v;
    tie(u,v)=que.front();
    ll val,ux,vx;
    tie(val,ux,vx)=dp[u][v];
    que.pop();
    //cout<<val spa ux spa vx<<endl;
    for(auto to:g[u]){
      if(to==ux)continue;
      if(get<0>(dp[min(v,to)][max(v,to)])==-1)que.emplace(min(v,to),max(v,to));
      ll tmpx=u,tmpy=vx;if(to>v)swap(tmpx,tmpy);
      chmax(dp[min(v,to)][max(v,to)],MT(val+num[u][to]*num[vx][v],tmpx,tmpy));
    }
    for(auto to:g[v]){
      if(to==vx)continue;
      ll tmpx=ux,tmpy=v;if(to<u)swap(tmpx,tmpy);
      if(get<0>(dp[min(u,to)][max(u,to)])==-1)que.emplace(min(u,to),max(u,to));
      chmax(dp[min(u,to)][max(u,to)],MT(val+num[v][to]*num[ux][u],tmpx,tmpy));
    }
  }
  //debug(num,n,n);
  rep(i,0,n)rep(j,i+1,n){
    chmax(res,get<0>(dp[i][j]));
    //cout<<i spa j spa get<0>(dp[i][j])<<endl;
  }
  cout<<res<<endl;
  return 0;
}