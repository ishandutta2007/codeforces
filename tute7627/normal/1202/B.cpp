#include<bits/stdc++.h>
using namespace std;

#define ALL(a)  (a).begin(),(a).end()
#define ALLR(a)  (a).rbegin(),(a).rend()
#define spa << " " <<
#define test cout<<"test"<<endl;
#define fi first
#define se second
#define rep(i,n,m) for(ll i = n; i < (ll)(m); i++)
#define rrep(i,n,m) for(ll i = n - 1; i >= (ll)(m); i--)
typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const ll INF = 99;
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
void debug(vector<vector<ll>>v,ll h,ll w){for(ll i=0;i<h;i++)
{cout<<v[i][0];for(ll j=1;j<w;j++)cout spa v[i][j];cout<<endl;}};
void debug(vector<string>v,ll h,ll w){for(ll i=0;i<h;i++)
{for(ll j=0;j<w;j++)cout<<v[i][j];cout<<endl;}};
void debug(vector<ll>v,ll n){cout<<v[0];
for(ll i=1;i<n;i++)cout spa v[i];cout<<endl;};
vector<vector<ll>>vec(ll x, ll y, ll w){
  vector<vector<ll>>v(x,vector<ll>(y,w));return v;}
ll gcd(ll x,ll y){ll r;while((r=x%y)!=0){x=y;y=r;}return y;}
//m.emplace(x,0).fi->se++;

int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  ll res=0,res1=INF,res2=-INF,buf=0;
  bool judge = true;
  /*auto a=vec(10,10,INF);
  rep(i,0,10){
    rep(j,1,11){
      buf=(i*j)%10;
      chmin(a[i][buf%10],j);
    }
  }*/
  vector<ll>b(10);
  string s;cin>>s;
  rep(i,0,s.size()-1){
    b[(s[i+1]-s[i]+10)%10]++;
  }
  auto ret=vec(10,10,0);
  rep(i,0,10)rep(j,0,10){
    vector<ll>c(10,INF);
    rep(p,0,11)rep(q,0,11){
      if(p==0&&q==0)continue;
      ll tmp=((i*p)+(q*j))%10;
      chmin(c[tmp],p+q);
    }
    rep(o,0,10){
      if(c[o]==INF&&b[o]>=1){
        ret[i][j]=-1;
        break;
      }
      //if(i==0&&j==0&&o==6)cout<<c[o] spa INF spa b[o]<<endl;
      ret[i][j]+=(c[o]-1)*(b[o]);
    }
    //if(i==0&&j==0)cout<<ret[i][j]<<endl;
    //if(i==0&&j==0)debug(c,10);
  }
  //debug(a,10,10);
  debug(ret,10,10);
  //debug(b,10);

  return 0;
}