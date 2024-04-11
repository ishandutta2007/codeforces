#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=1e5+10;
ll a[maxn];
int main()
{
    ll n,cnt=1;
    scanf("%lld",&n);

    for(ll i=2;i<=n;i++)
    {
        if(!a[i])
        {
            a[i]=cnt++;
            for(ll j=i*i;j<=n;j+=i)
            {
                if(!a[j])a[j]=a[i];
            }
        }
    }

    for(ll i=2;i<=n;i++)
    {
        printf("%d ",a[i]);
    }

    return 0;
}