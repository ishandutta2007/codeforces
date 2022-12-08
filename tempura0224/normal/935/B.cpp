#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
typedef pair<int,int> pint;
typedef long long ll;
const int inf   = 1<<30;
const int mod=1000000007;

  
int main(){
  int n;cin>>n;
  string s;
  cin>>s;
  ll a[n+2];
  a[0]=0;
  rep(i,n){
    if(s[i]=='U')a[i+1]=a[i]+1;
    else a[i+1]=a[i]-1;
    }
  int ans=0;
  rep(i,n-1)if(a[i]*a[i+2]<0)ans++;
  cout<<ans<<endl;
  return 0;
  }