#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double lb;
const int N=5e5+10;
const ll mod=998244353;
int t,n;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        vector<ll>dp1(n+2);
        vector<ll>dp2(n+2);
        dp1[0]=1;
        for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            dp1[x+1]=(dp1[x+1]+dp1[x]+dp1[x+1])%mod;
            if(x)dp2[x-1]=(dp2[x-1]+dp2[x-1]+dp1[x-1])%mod;
            dp2[x+1]=(dp2[x+1]+dp2[x+1])%mod;
        }
        ll ans=-1;
        for(int i=0;i<=n+1;i++)ans=(ans+dp1[i]+dp2[i])%mod;
        printf("%lld\n",ans);
    }
    return  0;
}