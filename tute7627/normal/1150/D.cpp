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

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  //cout<<fixed<<setprecision(10);
  ll res=0,buf=0;
  bool judge = true;
  ll n,q;cin>>n>>q;
  string s;cin>>s;
  vector<vector<ll>>next(n+1,vector<ll>(26));
  vector<ll> p(26,INF);
  rrep(i,0,n){
    rep(j,0,26)next[i+1][j]=p[j];
    p[s[i]-'a']=i;
  }
  rep(i,0,26)next[0][i]=p[i];
  auto v=make_v(251,251,251,INF);
  vector<string>t(3);
  v[0][0][0]=0;
  while(q--){
    char c;cin>>c;
    if(c=='+'){
      ll x;char y;
      cin>>x>>y;
      x--;
      t[x].PB(y);
      vector<ll>l(3,0);
      l[x]=t[x].size()-1;
      rep(i,l[0],t[0].size()+1)rep(j,l[1],t[1].size()+1)rep(o,l[2],t[2].size()+1){
        //cout<<q spa i spa j spa o spa v[i][j][o]<<endl;
        if(v[i][j][o]==INF)continue;
        if(i<t[0].size())chmin(v[i+1][j][o],next[v[i][j][o]][t[0][i]-'a']+1);
        if(j<t[1].size())chmin(v[i][j+1][o],next[v[i][j][o]][t[1][j]-'a']+1);
        if(o<t[2].size())chmin(v[i][j][o+1],next[v[i][j][o]][t[2][o]-'a']+1);
      }
    }
    else{
      ll x;cin>>x;
      x--;
      t[x].pop_back();
      vector<ll>l(3,0);
      //l[x]=max(1LL,(ll)t[x].size())-1;
      if(x==0)rep(i,0,t[1].size()+1)rep(j,0,t[2].size()+1)v[t[x].size()+1][i][j]=INF;
      if(x==1)rep(i,0,t[0].size()+1)rep(j,0,t[2].size()+1)v[i][t[x].size()+1][j]=INF;
      if(x==2)rep(i,0,t[0].size()+1)rep(j,0,t[1].size()+1)v[i][j][t[x].size()+1]=INF;
      /*rep(i,l[0],t[0].size()+1)rep(j,l[1],t[1].size()+1)rep(o,l[2],t[2].size()+1){
        if(v[i][j][o]==INF)continue;
        if(i<t[0].size())chmin(v[i+1][j][o],next[v[i][j][o]][t[0][i]-'a']+1);
        if(j<t[1].size())chmin(v[i][j+1][o],next[v[i][j][o]][t[1][j]-'a']+1);
        if(o<t[2].size())chmin(v[i][j][o+1],next[v[i][j][o]][t[2][o]-'a']+1);
      }*/
    }
    ans2(v[t[0].size()][t[1].size()][t[2].size()]!=INF);
  }
  return 0;
}