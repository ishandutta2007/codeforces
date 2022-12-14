#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const int inf=0x3f3f3f3f;

int arr[maxn],dp1[maxn],dp2[maxn];

int main()
{
    //freopen("in.txt","r",stdin);
    int n,m;
    ll ans=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&arr[i]);
    }
    if(n==1)
    {
        printf("0");
        return 0;
    }

    for(int i=m;i;i--)
    {
        int x=m-i+arr[i];
        dp1[x]=dp1[x-1]+1;
    }
    for(int i=m;i;i--)
    {
        int x=i+arr[i]-1;
        dp2[x]=dp2[x+1]+1;
    }

//    for(int i=1;i<m+n;i++)
//        cout<<dp1[i]<<' '<<dp2[i]<<endl;
//
//    cout<<endl<<endl;
    for(int i=1;i<=n;i++)
    {
        int l=max(1,i-m-1+dp2[i-1]);
        int r=min(n,i+m+1-dp1[i+m]);
        ans+=(ll)r-l+1;
//        cout<<l<<' '<<r<<endl;
    }
    printf("%lld",ans);
    return 0;
}