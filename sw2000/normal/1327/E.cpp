#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const ll mod=998244353;

ll ten[maxn];

int main()
{
    ten[0]=1;
    for(int i=1;i<maxn;i++)ten[i]=ten[i-1]*10%mod;
    int n;scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        ll ans=2*9*ten[n-i]+ten[n-i-1]*81*(n-i-1);
        ans%=mod;
        printf("%d ",ans);
    }
    printf("10");
	return 0;
}