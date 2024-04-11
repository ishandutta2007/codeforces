#include <iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<queue>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
typedef pair<int,int> pint;
typedef long long ll;
typedef pair<ll,ll> pll;
const int inf   = 510101010;
const ll longinf=1LL<<60;


int main(){
  ll k,d,t;
  cin>>k>>d>>t;
  t*=2;
  ll period=(k+d-1)/d*d;
  ll hot=k+period;
  ll turn=t/hot;
  ll mod=t%hot;
  ll ans=turn*period;
  ans*=2;
  if(mod<2*k){
    ans+=mod;
    }
  else{
    ans+=2*k;
    ans+=2*(mod-2*k);
    }
  cout<<ans/2;
  if(ans&1)cout<<".5";
  cout<<endl;
  return 0;    
  }