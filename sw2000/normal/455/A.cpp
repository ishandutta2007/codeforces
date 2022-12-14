#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
typedef long long ll;

ll arr[maxn],dp[maxn];

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        arr[a]+=a;
    }
    dp[1]=arr[1];
    for(int i=2;i<maxn;i++)
    {
        dp[i]=max(dp[i-1],dp[i-2]+arr[i]);
    }
    cout<<dp[maxn-1];
}