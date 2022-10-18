#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

int a[N],dp[N][2];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int lo=1,hi=2e9;
    while(lo<hi)
    {
        int mi=(lo+hi)/2;
        dp[0][0]=dp[0][1]=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]<=mi)
                dp[i][0]=max(dp[i-1][0],dp[i-1][1]+1);
            else
                dp[i][0]=dp[i-1][0];
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]+1);
        }
        if(max(dp[n][0],dp[n][1])>=k)
            hi=mi;
        else
            lo=mi+1;
    }
    cout<<lo;
}