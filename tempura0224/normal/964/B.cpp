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
const int mod=1e9+7;
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};




int main(){
  ll n,a,b,c,t;
  cin>>n>>a>>b>>c>>t;
  ll x[n];
  rep(i,n)cin>>x[i];
  ll ans=0;
  if(b>=c)ans=a*n;
  else{
    rep(i,n)ans+=a+(t-x[i])*(c-b);
    }
  cout<<ans<<endl;

  return 0;
  }