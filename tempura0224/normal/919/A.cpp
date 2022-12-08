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
  int n,m;
  cin>>n>>m;
  int a[n],b[n];
  double ansa=1,ansb=0;
  rep(i,n){
    cin>>a[i]>>b[i];
    if(a[i]*ansb<b[i]*ansa){
      ansa=a[i];
      ansb=b[i];
      }
    }
  double ans=ansa*m/ansb;
  cout<<fixed<<setprecision(10)<<ans<<endl;
  return 0;
  }