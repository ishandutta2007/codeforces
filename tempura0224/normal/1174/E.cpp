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
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

ll dp[2][22];
ll dp2[2][22][3];

int main(){
    int n;
    cin>>n;
    int d=0;
    while((1<<d)<=n)++d;
    --d;
    int c=0;
    while((1<<c)*3<=n)++c;
    vector<int> cnt(23);
    cnt[0]=n;
    rep(i,22)cnt[i+1]=cnt[i]/2;
    dp[1][d]=1;
    rep(i,n){
        if(i==0)continue;
        rep(j,d+1){
            dp[(i+1)%2][j]=0;
            if(cnt[j]>=i)dp[(i+1)%2][j]+=dp[i%2][j]*(cnt[j]-i)%mod;
            dp[(i+1)%2][j]+=dp[i%2][j+1]*(cnt[j]-cnt[j+1])%mod;
            dp[(i+1)%2][j]%=mod;
        }
    }
    if(c==d){
        vector<int> cnt2(23);
        cnt2[0]=n/3;
        rep(i,22)cnt2[i+1]=cnt2[i]/2;
        --c;
        dp2[1][c][1]=1;
        rep(i,n){
            if(i==0)continue;
            rep(j,c+1){
                dp2[(i+1)%2][j][0]=0;
                dp2[(i+1)%2][j][1]=0;
                if(cnt[j]>=i)dp2[(i+1)%2][j][0]+=dp2[i%2][j][0]*(cnt[j]-i)%mod;
                if(cnt2[j]>=i)dp2[(i+1)%2][j][1]+=dp2[i%2][j][1]*(cnt2[j]-i)%mod;
                dp2[(i+1)%2][j][1]+=dp2[i%2][j+1][1]*(cnt2[j]-cnt2[j+1])%mod;

                dp2[(i+1)%2][j][0]+=dp2[i%2][j+1][0]*(cnt[j]-cnt[j+1])%mod;
                dp2[(i+1)%2][j][0]+=dp2[i%2][j][1]*(cnt[j]-cnt2[j])%mod;

                dp2[(i+1)%2][j][0]%=mod;
                dp2[(i+1)%2][j][1]%=mod;
            }
        }
    }
    cout<<(dp[n%2][0]+dp2[n%2][0][0])%mod<<endl;
    return 0;
}