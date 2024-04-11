#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e3+10;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;
int n,m,arr[maxn],brr[maxn];

int solve()
{
    int ret=(m+brr[0]-arr[0])%m;
    for(int i=1;i<n;i++)
    {
        if(ret!=(m+brr[i]-arr[i])%m)return inf;
    }
    return ret;
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)scanf("%d",arr+i);
    for(int i=0;i<n;i++)scanf("%d",brr+i);
    sort(arr,arr+n);
    sort(brr,brr+n);
    int ans=inf;
    for(int j=0;j<n;j++)
    {
        ans=min(ans,solve());

        for(int i=n-1;i;i--)
            swap(arr[i],arr[i-1]);
    }
    cout<<ans;
    return 0;
}