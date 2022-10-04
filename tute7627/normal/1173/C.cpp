#include<bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define ALL(a)  (a).begin(),(a).end()
#define ALLR(a)  (a).rbegin(),(a).rend()
#define spa << " " <<
#define MP make_pair
ll MOD = 1e9+7;
//ll MOD = 998244353;
ll INF = 1e18;
void chmin(ll &a,ll b){if(a>b)a=b;}
void chmax(ll &a,ll b){if(a<b)a=b;}
void pmod(ll &a,ll b){a=(a+b)%MOD;}
void qmod(ll &a,ll b){a=(a*b)%MOD;}
void ans1(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}
void ans2(bool x){if(x) cout<<"YES"<<endl;else cout<<"NO"<<endl;}
void ans3(bool x){if(x) cout<<"Yay!"<<endl;else cout<<":("<<endl;}
void ans(bool x, ll y, ll z){if(x)cout<<y<<endl;else cout<<z<<endl;}   


int main(){
  ll i,j,o;
  ll result=INF,buf=0,buf1=0,buf2=0,buf3=0,buf4=0;
  bool judge = true;
  ll n;cin>>n;
  vector<ll>a(n),b(n),d(n+1);
  for(i=0;i<n;i++)cin>>a[i];
  for(i=0;i<n;i++)cin>>b[i];

  for(i=0;i<n;i++){
    if(b[i]!=0)d[b[i]]=i+1;
  }
  buf3=b[n-1];
  if(buf3!=0){
  for(i=0;i<n;i++){
    //cout<<i spa b[n-i-1] spa buf<<endl;
    if(b[n-i-1]==buf3-i&&buf3!=i)buf++;
    else break;
  }
  if(buf==n)result=0;
  }
  //cout<<buf<<endl;
  if(buf>0){
    for(i=buf+1;i<=n;i++){
      if(d[i]>=i-buf)break;
      else if(i==n)result=n-buf;
    }
  }
  // cout<<result<<endl;

  for(i=1;i<=n;i++){
    chmax(buf2,d[i]+1-i);
  }
  chmin(result,buf2+n);
  cout<<result<<endl;


  return 0;
}