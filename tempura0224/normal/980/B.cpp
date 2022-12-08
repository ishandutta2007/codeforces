#include <iostream>
#include <vector>
#include<algorithm>
#include<iomanip>
#include<queue>
#include<deque>
#include<map>
#include<bitset>
#include<math.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define REP(i,m,n) for(ll i=m;i<(ll)(n);i++)
typedef pair<int,long long> pint;
typedef long long ll;
const ll mod= 1e9+7;
const ll  longinf = 1LL<<60;
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};

int main(){
  int n,k;cin>>n>>k;
  cout<<"YES"<<endl;
  rep(i,n)cout<<".";
  cout<<endl;
  if(k%2==0){
    k/=2;
    rep(i,2){
      cout<<".";
      rep(i,k)cout<<"#";
      rep(i,n-k-1)cout<<".";
      cout<<endl;
      }
    }
  else{
    if(k<=n-2){
      rep(i,n)cout<<".";
      cout<<endl;
      }
    else{
      k-=n-2;
      k/=2;
      cout<<".";
      rep(i,k)cout<<"#";
      rep(i,n-2*k-2)cout<<".";
      rep(i,k)cout<<"#";
      cout<<".";
      cout<<endl;
      k=n-2;
      }
    k/=2;
    int m=n/2;
    rep(i,m-k)cout<<".";
    rep(i,2*k+1)cout<<"#";
    rep(i,m-k)cout<<".";
    cout<<endl;
    }
  rep(i,n)cout<<".";
  cout<<endl;
    
  return 0;
  }