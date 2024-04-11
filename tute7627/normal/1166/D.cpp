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
#define PB push_back
#define EB emplace_back
#define rep(i,n,m) for(ll i = n; i < (ll)(m); i++)
#define rrep(i,n,m) for(ll i = n - 1; i >= (ll)(m); i--)
typedef long long ll;
typedef long double ld;
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
void debug(vector<T>v,ll n){cout<<v[0];
for(ll i=1;i<n;i++)cout spa v[i];cout<<endl;};
template<typename T>
vector<vector<T>>vec(ll x, ll y, T w){
  vector<vector<T>>v(x,vector<T>(y,w));return v;}
ll gcd(ll x,ll y){ll r;while(y!=0&&(r=x%y)!=0){x=y;y=r;}return y==0?x:y;}
template<typename T>
void emp(map<T,ll>&m, T x){m.emplace(x,0).first->second++;}
vector<ll>dx={1,0,-1,0,1,1,-1,-1};
vector<ll>dy={0,1,0,-1,1,-1,1,-1};

int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  ll res=0,res1=INF,res2=-INF,buf=0;
  bool judge = true;
  ll q;cin>>q;
  vector<ll>tw(60,1);
  rep(i,1,60)tw[i]=tw[i-1]*2;
  rep(i,0,q){
    ll a,b,m;cin>>a>>b>>m;
    ll sumbuf=a;
    m--;
    vector<ll>ret;
    ret.PB(a);
    if(a!=b){
      rep(j,1,50){
        ret.PB(sumbuf+1);
        sumbuf+=ret.back();
        if(b<ret.back()+m*tw[max(0LL,(ll)ret.size()-2)]||sumbuf>=b){
          break;
        }
      }
    }
    ll x=b-ret.back();
    ll y=ret.size();
    //cout<<x spa b spa ret.back()<<endl;
    if(x<=m*tw[max(0LL,y-2)]){
      ll y=ret.size();
      ll sumbuf=a;
      rep(i,1,y){
        ll p=min(m,x/tw[max(0LL,y-i-2)]);
        //cout<<x spa p<<endl;
        x-=p*tw[max(0LL,y-i-2)];
        ret[i]=sumbuf+p+1;
        sumbuf+=ret[i];
      }
      cout<<y<<" ";
      debug(ret,y);
    }
    else{
      cout<<-1<<endl;
    }
  }
  return 0;
}