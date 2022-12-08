#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=998244353 ;
int dx[4]={1,0,-1,0} , dy[4]={0,1,0,-1} ;

ll dp[555][555];
ll cnt[555];
ll rec(int n,int k){
    if(dp[n][k]!=0)return dp[n][k];
    if(k==0)return 0;
    if(n==0)return 1;
    ll ret=0;
    REP(i,1,k+1){
        if(i>n)break;
        (ret+=rec(n-i,k))%=mod;
    }
    return dp[n][k]=ret;
}
int main(){
   int n,k;
   cin>>n>>k;
   --k;
   rep(i,n)cnt[i+1]=(rec(n,i+1)-rec(n,i))%mod;
   ll ans=0;
   rep(i,n){
       ll ret=cnt[i+1];
       int ma=k/(i+1);
       ma=min(n,ma);
       ret*=rec(n,ma);
       ret%=mod;
       ans=(ans+ret)%mod;
   }
   ans=2*ans%mod;
   cout<<ans<<endl;
   return 0;
}