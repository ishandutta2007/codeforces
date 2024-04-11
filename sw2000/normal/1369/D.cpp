#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int>vi;
const int maxn=2e6+10;
const ll mod=1e9+7;
const double PI=acos(0)*2;

ll dp[maxn];

int main()
{
//    freopen("in.txt","r",stdin);
//    ios::sync_with_stdio(false);cin.tie(0);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<maxn;i++)
    {
        dp[i]=dp[i-1]+dp[i-2]*2;
        dp[i]%=mod;
    }
    for(int i=3;i<maxn;i++)
    {
        dp[i]+=dp[i-3];
        dp[i]%=mod;
    }
    int _;cin>>_;
    while(_--)
    {
        int n;
        scanf("%d",&n);
        if(n==1)puts("0");
        else printf("%lld\n",dp[n-2]*4%mod);
    }
}