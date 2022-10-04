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
P plus2(P x,P y){
  return MP(x.fi+y.fi,x.se+y.se);
}
template<typename T>
vector<vector<T>>WarshallFloyd(vector<vector<T>>matrix){
  vector<vector<T>>ret=matrix;
  ll sz=ret[0].size();
  for(ll i=0;i<sz;i++)ret[i][i]=MP(0,0);
  for(ll j=0;j<sz;j++){
    for(ll i=0;i<sz;i++){
      for(ll o=0;o<sz;o++){
        if(ret[i][j]!=MP(INF,INF)&&ret[j][o]!=MP(INF,INF)){
          T tmp=MP(ret[i][j].fi+ret[j][o].fi,ret[i][j].se+ret[j][o].se);
          chmin(ret[i][o],tmp);
        }
      }
    }
  }
  return ret;
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n;cin>>n;
  vector<ll>idx(n*n);
  rep(i,0,n*n){
    ll x;cin>>x;
    idx[x-1]=i;
  }
  auto mat=vec(3*n*n,3*n*n,MP(INF,INF));
  vector<P>moves;
  auto f=[&](ll x,ll y){
    return x>=0&&x<n&&y>=0&&y<n;
  };
  rep(i,0,n)rep(j,0,n){
    rep(p,4,8)rep(q,4,8){
      ll x=i+dx[p],y=j+dy[q]*2;
      if(f(x,y)){
        mat[x*n+y][i*n+j]=MP(1,0);
        mat[i*n+j][x*n+y]=MP(1,0);
      }
      x=i+dx[p]*2,y=j+dy[q];
      if(f(x,y)){
        mat[x*n+y][i*n+j]=MP(1,0);
        mat[i*n+j][x*n+y]=MP(1,0);
      }
    }
    rep(p,0,n)rep(q,0,n){
      bool judge1=(abs(p-i)==abs(q-j)&&i!=p);
      bool judge2=((i==p)^(j==q));
      if(judge1){
        mat[p*n+q+n*n][i*n+j+n*n]=MP(1,0);
        mat[i*n+j+n*n][p*n+q+n*n]=MP(1,0);
      }
      if(judge2){
        mat[p*n+q+n*n*2][i*n+j+n*n*2]=MP(1,0);
        mat[i*n+j+n*n*2][p*n+q+n*n*2]=MP(1,0);
      }
    }
    rep(p,0,3)rep(q,p+1,3){
      mat[i*n+j+n*n*p][i*n+j+n*n*q]=MP(1,1);
      mat[i*n+j+n*n*q][i*n+j+n*n*p]=MP(1,1);
    }
  }
  auto d=WarshallFloyd(mat);
  auto dp=vec(n*n,3,MP(INF,INF));
  dp[0]={MP(0,0),MP(0,0),MP(0,0)};
  rep(i,0,n*n-1){
    rep(p,0,3)rep(q,0,3){
      chmin(dp[i+1][q],plus2(dp[i][p],d[idx[i]+p*n*n][idx[i+1]+q*n*n]));
    }
  }
  //debug(dp,n*n,3);
  cout<<*min_element(ALL(dp[n*n-1]))<<endl;
  return 0;
}