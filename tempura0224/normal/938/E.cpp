#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
typedef pair<long long,long long> pint;
typedef long long ll;
const int inf   = 1<<30;
const ll mod=1000000007;

ll fact[1000001];
ll calc(ll i){
  if(fact[i]!=0) return fact[i];
  return fact[i]=i*calc(i-1) %mod;
  }
ll pow(ll n,ll k){
  ll ret=1;
  while(k>0){
    if(k&1)ret=ret*n %mod;
    n=n*n %mod;
    k/=2;
    }
  return ret;
  }

ll inv(ll i){
  return pow(i,mod-2);
  }  

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
  ll n;
  cin>>n;
  rep(i,n)fact[i+1]=0; 
  fact[0]=1;
  ll a[n];
  rep(i,n)cin>>a[i];
  sort(a,a+n);
  vector<pint> v;
  ll now=a[0],cnt=1;
  rep(i,n-1){
    if(a[i+1]==now)cnt++;
    else{
      v.push_back(pint(now,cnt));
      now=a[i+1];
      cnt=1;
      }
    }
  v.push_back(pint(now,cnt));
  int m=v.size();
  ll left[m],right[m];
  left[0]=0;
  rep(i,m-1)left[i+1]=left[i]+v[i].second;
  rep(i,m)right[i]=n-left[i]-1;
  ll ans=0;
  rep(i,m-1){
    ll ret=calc(n)*inv(right[i]+1) %mod;
    ret=ret*v[i].first %mod;
    ans=(ans+ret*v[i].second)%mod;
    }
  cout<<ans<<endl;    
  return 0;
  }