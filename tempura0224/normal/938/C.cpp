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

void solve(ll x){
  if(x==0){cout<<"1 1"<<"\n";return;}
  REP(i,1,40000){
    ll li=(ll)i;
    if(li*li<=x)continue;
    if(3*li*li>4*x)break;
    ll left=0,right=i+1,mid;
    while(right-left>1){
      mid=(left+right)/2;
      ll y=i/mid;
      if(i*i-y*y>x)right=mid;
      else left=mid;
      }
    ll z=i/left;
    if(i*i-z*z==x){
      cout<<i<<" "<<left<<"\n";
      return ;
      }
    }
  cout<<-1<<"\n";
  return ;
  }
int main(){
  int n;
  cin>>n;
  rep(i,n){
    ll t;
    cin>>t;
    solve(t);
    }
  return 0;
  }