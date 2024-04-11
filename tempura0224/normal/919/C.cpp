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
  int n,m,k;
  cin>>n>>m>>k;
  string s[n+1];
  rep(i,n){
    cin>>s[i];
    s[i]+='*';
    }
  rep(i,m)
    s[n]+='*';
  int ans=0;
  rep(i,n){
    int now=-1;
    rep(j,m+1){
      if(s[i][j]=='.')continue;
        if(j-now-1>=k)
          ans+=j-now-k;
        now=j;
      }
    }
  rep(j,m){
    int now=-1;
    rep(i,n+1){
      if(s[i][j]=='.')continue;
        if(i-now-1>=k)
          ans+=i-now-k;
        now=i;
      }
    }
  if(k==1)ans/=2;
  cout<<ans<<endl;
  return 0;
  }