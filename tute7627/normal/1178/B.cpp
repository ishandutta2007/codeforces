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
  string s;cin>>s;
  vector<vector<ll>>dp(s.size()+1,vector<ll>(3));
  for(i=1;i<=s.size();i++){
    if(i>=2&&s[i-2]=='v'&&s[i-1]=='v'){
      dp[i][0]=dp[i-1][0]+1;
      dp[i][1]=dp[i-1][1];
      dp[i][2]=dp[i-1][1]+dp[i-1][2];
    }
    else if(s[i-1]=='o'){
      dp[i][0]=dp[i-1][0];
      dp[i][1]=dp[i-1][1]+dp[i-1][0];
      dp[i][2]=dp[i-1][2];
    }
    else{
      dp[i][0]=dp[i-1][0];
      dp[i][1]=dp[i-1][1];
      dp[i][2]=dp[i-1][2];
    }
  }
  //debug(dp,s.size()+1,3);
  cout<<dp[s.size()][2]<<endl;

  return 0;
}