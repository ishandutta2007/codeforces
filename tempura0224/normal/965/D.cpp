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
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
typedef pair<int,int> pint;
typedef long long ll;
const int inf   = 1e9+7;
const ll  longinf = 1LL<<60;
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};

int main(){
  int n;cin>>n;
  int w;cin>>w;
  ll a[n+1];
  a[n-1]=longinf;
  rep(i,n-1)cin>>a[i];
  ll res=0,ans=longinf;
  rep(i,w)res+=a[i];
  ans=min(ans,res);
  rep(i,n-w){
    res+=a[w+i]-a[i];
    ans=min(res,ans);
    }
  cout<<ans<<endl;
  return 0;
  }