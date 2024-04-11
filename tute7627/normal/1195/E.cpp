#pragma GCC optimize("Ofast")
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
//const ll MOD = 1e9+7;
const ll MOD = 998244353;
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
//m.emplace(x,0).fi->se++;

template<class T>
vector<T> slidemin(vector<T>x, ll len){
  ll n=x.size();
  vector<T>ret(n-len+1);
  deque<T> deq;
  for(ll i=0;i<len;i++){
    while(!deq.empty()&&x[deq.back()]>=x[i])deq.pop_back();
    deq.push_back(i);
  }
  ret[0]=x[deq.front()];

  for(ll i=0;i<n-len;i++){
    if(deq.front()==i)deq.pop_front();
    while(!deq.empty()&&x[deq.back()]>=x[i+len])deq.pop_back();
    deq.push_back(i+len);
    ret[i+1]=x[deq.front()];
  }
  return ret;
}

int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  ll res=0,res1=INF,res2=-INF,buf=0;
  bool judge = true;
  ll n,m,a,b;cin>>n>>m>>a>>b;
  vector<ll>g(n*m);
  ll x,y,z;cin>>g[0]>>x>>y>>z;
  rep(i,1,n*m){
    g[i]=(g[i-1]*x+y)%z;
  }
  auto v=vec(n,m-b+1,0);
  rep(i,0,n){
    vector<ll>tmp(m);
    rep(j,0,m)tmp[j]=g[i*m+j];
    auto k=slidemin(tmp,b);
    rep(j,0,m-b+1)v[i][j]=k[j];
  }
  rep(i,0,m-b+1){
    vector<ll>tmp(n);
    rep(j,0,n)tmp[j]=v[j][i];
    auto k=slidemin(tmp,a);
    rep(j,0,n-a+1)res+=k[j];
  }
  cout<<res<<endl;
}