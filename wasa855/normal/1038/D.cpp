#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,minn=1e9,ans=0;
int a[500005];
bool pos=0,neg=0;
//eifchnisdhfhxlizg
signed main()
{
    cin>>n;
    if(n==1)
    {
        int k;
        cin>>k;
        cout<<k;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%I64d",&a[i]);
        minn=min(abs(a[i]),minn);
        pos|=(a[i]>=0);
        neg|=(a[i]<=0);
        ans+=abs(a[i]);
    }
    if(pos&&neg)
    {
        cout<<ans;
    }
    else
    {
        cout<<ans-2*minn;
    }
    return 0;
}
//dzaouejmrsoxziutrczrcy