#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    ll n,ans=0;
    scanf("%lld",&n);
    if(n%2==0)
    {
        if(n%4==0)
            ans+=4;
    }
    printf("%lld\n",ans);
    return 0;
}