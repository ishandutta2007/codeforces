#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
typedef long long ll;

ll arr[N];
ll ans;

int main()
{
//    freopen("in.txt","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",arr+i);
        ans+=arr[i]-1;
    }
    sort(arr,arr+n);
    for(int i=2;i<1000000;i++)
    {
        ll base=1,cnt=arr[0]-1;
        for(int j=1;j<n;j++)
        {
            base*=i;
            if(base>100000000000)break;
            cnt+=abs(base-arr[j]);
            if(j==n-1)
            {
                ans=min(ans,cnt);
            }
        }
    }
    printf("%lld",ans);
    return 0;
}