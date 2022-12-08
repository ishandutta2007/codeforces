#include <iostream>
#include <vector>
#include<algorithm>
#include<iomanip>
#include<queue>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
typedef pair<int,int> pint;
typedef pair<long long,long long> pll;
typedef long long ll;
const int inf   = 1<<30-1;
const ll  longinf = 1LL<<60;
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};

int main(){
  ll a,b,p,x;
  cin>>a>>b>>p>>x;
  rep(i,p){
    if((a*i)%p==1){
      a=i;
      break;
      }
    }
  ll n=b,ans[p];
  rep(i,p-1){
    ans[i]=n%p;
    n*=a;
    n%=p;
    }
  ll kotae=0;
  rep(i,p-1){
    ll y=(p-1)*(i-ans[i])+i;
    if(y<=0)y+=p*(p-1);
    if(y<=x)kotae+=1+(x-y)/p/(p-1);
    }
  cout<<kotae<<endl;
  return 0;
  }