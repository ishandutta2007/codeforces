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
typedef long long ll;
typedef pair<int,int> pint;
const ll mod= 1e9+7;
const int inf=1e9+7;
const ll  longinf = 1LL<<60;
int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};

int main(){
  int n;
  cin>>n;
  ll a[n],c[n];
  rep(i,n)cin>>a[i];
  rep(i,n)cin>>c[i];
  ll mi[n],mmi[n];
  rep(i,n)mi[i]=mmi[i]=longinf;
  rep(i,n){
    REP(j,i,n){
      if(a[i]<a[j])mi[i]=min(mi[i],c[i]+c[j]);
      }
    }
  rep(i,n){
    REP(j,i,n){
      if(a[i]<a[j])mmi[i]=min(mmi[i],c[i]+mi[j]);
      }
    }
  ll ans=longinf;
  rep(i,n)ans=min(ans,mmi[i]);
  if(ans==longinf)ans=-1;
  cout<<ans<<endl;
  return 0;
  }