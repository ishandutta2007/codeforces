#include <iostream>
#include <vector>
#include<algorithm>
#include<iomanip>
#include<queue>
#include<map>
#include<bitset>
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
  int h,m;
  cin>>h>>m;
  int x,d,c,n;
  cin>>x>>d>>c>>n;
  int time=60*h+m;
  if(time>=1200){
    int num=(x+n-1)/n;
    double ans=1.0*num*c*0.8;
    cout<<fixed<<setprecision(5)<<ans<<endl;
    return 0;
    }
  int num=(x+n-1)/n;
  double ans=1.0*num*c;
  num=(x+(1200-time)*d+n-1)/n;
  double ret=1.0*num*c*0.8;
  ans=min(ans,ret);
  cout<<fixed<<setprecision(4)<<ans<<endl;
  return 0;
  }