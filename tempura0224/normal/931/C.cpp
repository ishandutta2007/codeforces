#include <iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<map>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
typedef long long ll;
typedef pair<ll,ll> pint;
const int inf   = 510101010;
const int mod=1e9+7;
const ll longinf=1LL<<60;

int main(){
  int n;cin>>n;
  int x[n],ma=-inf,mi=inf;
  rep(i,n){
    cin>>x[i];
    ma=max(ma,x[i]);
    mi=min(mi,x[i]);
    }
  if(ma-mi<2){
    cout<<n<<endl;
    rep(i,n)cout<<x[i]<<" ";
    cout<<endl;
    return 0;
    }
  int cntma=0,cntmi=0;
  rep(i,n){
    if(x[i]==ma)cntma++;
    if(x[i]==mi)cntmi++;
    }
  if(cntma>=cntmi){
    int x=(n-cntma-cntmi)/2;
    int num=cntma-cntmi;
    if(cntmi>=x){
      cout<<n-2*cntmi<<endl;
      rep(i,num)cout<<ma<<" ";
      rep(i,n-num)cout<<ma-1<<" ";
      }
    else{
      cout<<cntma+cntmi+(n-cntma-cntmi)%2<<endl;
      if((n-cntma-cntmi)%2)cout<<mi+1<<" ";
      rep(i,cntma+x)cout<<ma<<" ";
      rep(i,cntmi+x)cout<<mi<<" ";
      }
    }
  else{
    int x=(n-cntma-cntmi)/2;
    int num=cntmi-cntma;
    if(cntma>=x){
      cout<<n-2*cntma<<endl;
      rep(i,num)cout<<mi<<" ";
      rep(i,n-num)cout<<ma-1<<" ";
      }
    else{
      cout<<cntma+cntmi+(n-cntma-cntmi)%2<<endl;
      if((n-cntma-cntmi)%2)cout<<mi+1<<" ";
      rep(i,cntma+x)cout<<ma<<" ";
      rep(i,cntmi+x)cout<<mi<<" ";
      }
    }
  cout<<endl;
  return 0;
  }