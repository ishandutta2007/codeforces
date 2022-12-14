#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=4e5+10;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
const ll linf=0x3f3f3f3f3f3f3f3f;

ll arr[maxn];
int n;

int main()
{
    //freopen("in.txt","r",stdin);
    ll ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&arr[i]);
    bool flag=0;
    for(int i=n;i;i>>=1)
    {
        ll mi=inf;
        int id;
        for(int j=n;j>=i;j--)
        {
            if(arr[j]==-1)
            {
                flag=1;
                break;
            }
            if(arr[j]<mi)
            {
                mi=arr[j];
                id=j;
            }
        }
        if(flag)break;
        ans+=arr[id];
        arr[id]=inf;
    }
    printf("%lld",ans);
    return 0;
}