#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
typedef pair<int,int> pint;
typedef long long ll;
const int inf   = 1<<30;

int main(){
  int n;cin>>n;
  int ans=0;
  rep(i,n){
    int a;
    cin>>a;
    int ret=min(a-1,1000000-a);
    ans=max(ans,ret);
    }
  cout<<ans<<endl;
  return 0;
  }