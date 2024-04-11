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
#include<functional>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int cnt[111];
ll dp[333][11111];
ll ndp[333][11111];
int main(){
    int n;cin>>n;
    int q=0;
    rep(i,n){
        int x;cin>>x;
        ++cnt[x];
        if(cnt[x]==1)++q;
    }
    if(q<=2){
        cout<<n<<endl;
        return 0;
    }
    dp[0][0]=1;
    int sum=0;
    rep(i,101){
        rep(j,111)rep(k,sum+2)ndp[j][k]=0;
        for(int key=0;key<=cnt[i];++key){
            for(int j=sum+2;j>=0;--j)for(int l=100;l>=0;--l){
                ndp[l+key][j+key*i]+=dp[l][j];
            }
        }
        sum+=cnt[i]*i;
        rep(j,111)rep(k,sum+2)dp[j][k]=ndp[j][k];
    }
    int ans=0;
    rep(i,101){
        rep(j,cnt[i]+1){
            if(dp[j][i*j]==1)ans=max(ans,j);
        }
    }
    cout<<ans<<endl;
    return 0;
}