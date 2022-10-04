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

int main(){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  ll res=0,res1=INF,res2=-INF,buf=0;
  bool judge = true;
  ll t;cin>>t;
  rep(i,0,t){
    ll n,m;cin>>n>>m;
    vector<string>s(n);
    rep(i,0,n)cin>>s[i];
    vector<pair<P,P>>ret;
    judge=true;
    rrep(j,26,0){
      char c='a'+j;
      ll r1=-1,c1=-1,r2=-1,c2=-1;
      rep(p,0,n)rep(q,0,m){
        if(s[p][q]==c){
          if(r1==-1)r1=p,c1=q;
          else{
            if(r1!=p&&c1!=q)judge=false;
            if(q<c2)judge=false;
          }
          r2=p;
          c2=q;
        }
      }
      if(r1==-1){
        if(ret.size()!=0){
          ll x=ret.size();
          ret.push_back(ret[x-1]);
        }
      }
      else if(r1==r2){
        rep(o,c1,c2+1){
          if(s[r1][o]<c||s[r1][o]=='.')judge=false;
        }
      }
      else{
        rep(o,r1,r2+1){
          if(s[o][c1]<c||s[o][c1]=='.')judge=false;
        }
      }
      if(r1!=-1)ret.emplace_back(MP(r1+1,c1+1),MP(r2+1,c2+1));
    }
    ans2(judge);
    if(judge){
      ll x=ret.size();
      cout<<x<<endl;
      reverse(ALL(ret));
      rep(j,0,x){
        cout<<ret[j].fi.fi spa ret[j].fi.se spa 
        ret[j].se.fi spa ret[j].se.se<<endl; 
      }
    }
  }
  return 0;
}