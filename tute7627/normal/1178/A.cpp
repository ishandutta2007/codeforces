#include<bits/stdc++.h>
using namespace std;

#define ALL(a)  (a).begin(),(a).end()
#define ALLR(a)  (a).rbegin(),(a).rend()
#define spa << " " <<
#define MP make_pair
#define test cout<<"test"<<endl;
#define fi first
#define se second
typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const ll INF = 1e18;
using P = pair<ll, ll>;
void chmin(ll &a,ll b){if(a>b)a=b;}
void chmax(ll &a,ll b){if(a<b)a=b;}
void pmod(ll &a,ll b){a=(a+b)%MOD;}
void pmod(ll &a,ll b,ll c){a=(b+c)%MOD;}
void qmod(ll &a,ll b){a=(a*b)%MOD;}
void qmod(ll &a,ll b,ll c){a=(b*c)%MOD;}
ll median(ll a,ll b, ll c){return a+b+c-max({a,b,c})-min({a,b,c});}
void ans1(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}
void ans2(bool x){if(x) cout<<"YES"<<endl;else cout<<"NO"<<endl;}
void ans3(bool x){if(x) cout<<"Yay!"<<endl;else cout<<":("<<endl;}
void ans(bool x,ll y,ll z){if(x)cout<<y<<endl;else cout<<z<<endl;}
void ans(bool x,string y,string z){if(x)cout<<y<<endl;else cout<<z<<endl;}   
void debug(vector<vector<ll>>v,ll h,ll w){for(ll i=0;i<h;i++)
{for(ll j=0;j<w;j++)cout<<v[i][j]<<" ";cout<<endl;}};
ll gcd(ll x,ll y){ll r;while((r=x%y)!=0){x=y;y=r;}return y;}
//m.emplace(x,0).fi->second++;

int main(){
  ll i,j,o;
  ll res=0,res1=INF,res2=-INF,buf=0;
  bool judge = true;
  ll n;cin>>n;
  vector<ll>a(n);
  for(i=0;i<n;i++)cin>>a[i];
  ll sumbuf=a[0];
  res=a[0];
  vector<ll>p;
  p.push_back(1);
  for(i=1;i<n;i++){
    sumbuf+=a[i];
    if(a[i]*2<=a[0]){
      p.push_back(i+1);
      res+=a[i];
    }
  }
  if(res*2>sumbuf){
    cout<<p.size()<<endl;
    cout<<1;
    for(auto z:p){
      if(z!=1)cout<<" "<<z;
    }
    cout<<endl;
  }
  else cout<<0<<endl;

  return 0;
}