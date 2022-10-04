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
ll MAX_V = 2e5 + 5;
vector<vector<ll>> G(MAX_V);//()
vector<ll>t(MAX_V);//
bool judgebuf=true;
auto c=vec(3,MAX_V,0LL);
vector<ll>dp(3);
vector<ll>v;
void dfs(ll k,ll d){
  t[k]=1;
  v.PB(k);
  rep(i,0,3){
    dp[i]+=c[(i+d)%3][k];
  }
  for(ll i=0;i<G[k].size();i++){
    if(t[G[k][i]]==0){
      dfs(G[k][i],d+1);
    }
  }
}
void dfs2(ll k,ll d){
  t[k]=1;
  rep(i,0,3){
    dp[i]+=c[(i-(d%3)+3)%3][k];
  }
  for(ll i=0;i<G[k].size();i++){
    if(t[G[k][i]]==0){
      dfs2(G[k][i],d+1);
    }
  }
}

int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  ll res=0,res1=INF,res2=-INF,buf=0;
  bool judge = true;
  ll n;cin>>n;
  rep(i,0,3)rep(j,0,n)cin>>c[i][j];
  vector<ll>cnt(n);
  for(ll i=0;i<n-1;i++){
    ll p,q;
    cin>>p>>q;
    G[p-1].push_back(q-1);
    G[q-1].push_back(p-1);
    cnt[p-1]++;cnt[q-1]++;
  }
  ll start=0;
  rep(i,0,n){
    if(cnt[i]==1)start=i;
    if(cnt[i]>=3)judge=false;
  }
  if(!judge)cout<<-1<<endl;
  else{
    ll minbuf=INF;
    dfs(start,0);
    vector<ll>ret(n);
    rep(i,0,3){
      if(minbuf>dp[i]){
        rep(j,0,n){
          ret[v[j]]=(i+j)%3+1;
        }
        minbuf=dp[i];
      }
      dp[i]=0;
    }
    fill(ALL(t),0);
    dfs2(start,0);
    rep(i,0,3){
      if(minbuf>dp[i]){
        rep(j,0,n){
          ret[v[j]]=(i-(j%3)+3)%3+1;
        }
        minbuf=dp[i];
      }
      dp[i]=0;
    }
    cout<<minbuf<<endl;
    debug(ret,n);
  }
  return 0;
}