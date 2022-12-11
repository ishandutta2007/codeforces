#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int t,n,m,a[N];
long long dp[N][2];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        int s=0;
        for(int i=1;i<=m;i++){
            int x;
            scanf("%d",&x);
            s=__gcd(s,x);
        }
        for(int i=0;i<=n;i++)dp[i][0]=0,dp[i][1]=-1e18;
        for(int i=1;i<=n;i++){
            long long n1=dp[i%s][0],n2=dp[i%s][1];
            dp[i%s][0]=max(n1+a[i],n2-a[i]);
            dp[i%s][1]=max(n1-a[i],n2+a[i]);
        }
        long long ans1=0,ans2=0;
        for(int i=0;i<s;i++){
            ans1+=dp[i][0];
            ans2+=dp[i][1];
        }
        printf("%lld\n",max(ans1,ans2));
    }
    return  0;
}