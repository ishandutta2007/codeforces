#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;

int main()
{
//    freopen("in.txt","r",stdin);
    int t;
    for(scanf("%d",&t);t--;)
    {
        int a[3];
        for(int i=0;i<3;i++)cin>>a[i];
        sort(a,a+3);
        int ans=a[2]-a[0];
        ans=max(0,ans-2);
        printf("%d\n",ans<<1);
    }
    return 0;
}