#include <iostream>
#include <vector>
#include<algorithm>
#include<iomanip>
#include<queue>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
typedef pair<int,int> pint;
typedef long long ll;
const int inf   = 1<<29;
const ll  longinf = 1LL<<60;
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};

int main(){
  int t;
  cin>>t;
  rep(j,t){
    int n,k;
    cin>>n>>k;
    int a[k];
    rep(i,k)cin>>a[i];
    int ma=0;
    rep(i,k-1)
      ma=max(a[i+1]-a[i]-1,ma);
    ma=(ma+1)/2;
    int ans=0;
    ans=max(ma,a[0]-1);
    ans=max(ans,n-a[k-1]);
    cout<<ans+1<<endl;
    }
  return 0;    
  }