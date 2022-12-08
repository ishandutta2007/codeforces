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
  int n;cin>>n;
  ll s[n+1];
  ll t[n+1];
  ll sum[n+1];
  rep(i,n)cin>>s[i+1];
  rep(i,n)cin>>t[i+1];
  t[0]=0;
  sum[0]=t[0];
  rep(i,n)sum[i+1]=sum[i]+t[i+1];
  ll cnt[n+1];
  rep(i,n+1)cnt[i]=1;
  cnt[0]=0;
  ll mod[n+1];
  rep(i,n+1)mod[i]=0;
  REP(i,1,n+1){
    s[i]+=sum[i-1];
    int k=upper_bound(sum,sum+n+1,s[i])-sum;
    cnt[k]--;
    mod[k]+=s[i]-sum[k-1];
    }
  rep(i,n+1){
    cnt[i+1]+=cnt[i];
    }
  rep(i,n)cout<<cnt[i+1]*t[i+1]+mod[i+1]<<" ";
  cout<<endl;
  return 0;
  
  }