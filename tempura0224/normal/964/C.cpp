#include <iostream>
#include <vector>
#include<algorithm>
#include<iomanip>
#include<queue>
#include<map>
#include<bitset>
#include<math.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
typedef pair<int,int> pint;
typedef long long ll;
const int inf   = 1e9+7;
const ll  longinf = 1LL<<60;
ll mod=1e9+9;
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};

ll pow(ll n,ll k){
  ll ret=1;
  while(k>0){
    if(k&1)ret=ret*n %mod;
    n=n*n %mod;
    k/=2;
    }
  return ret;
  }


int main(){
  ll n,a,b,k;
  cin>>n>>a>>b>>k;
  string s;cin>>s;
  ll ans=0;
  ll pos=pow(a,n);
  ll inv=pow(a,mod-2) ;
  inv=inv*b %mod;
  rep(i,k){
    if(s[i]=='+')ans+=pos;
    else ans+=mod-pos;
    ans%=mod;
    pos=pos*inv %mod;
    }
  if(pow(inv,k)%mod==1){
    ans*=(n+1)/k;
    ans%=mod;
    cout<< ans <<endl;
    return 0;
    }
  ans=ans*(pow(inv,n+1)+mod-1);
  ans%=mod;
  ans=ans*pow(pow(inv,k)+mod-1,mod-2);
  ans%=mod;
  cout<< ans <<endl;
  return 0;
  }