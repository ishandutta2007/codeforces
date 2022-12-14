#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
typedef long long ll;

ll arr[maxn],dp[maxn];

int main()
{
    int n,cnt=0,ans=-1;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        if(arr[i]<arr[i-1])cnt=1;
        else cnt++;
        ans=max(ans,cnt);
    }
    cout<<ans;
}