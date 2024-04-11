#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
const int maxn=200001;
int po[maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int u=1;
    for(int i=0;i<=maxn;++i)
    {
        po[i]=u;
        u*=10;
        u%=p;
    }
    for(int i=1;i<=n;++i)
    {
        if(i==n)
        {
            cout<<10<<" ";
            continue;
        }
        int x=(n-i-1);
        int y=9*9;
        int z=po[n-i-2];
        int ans=((x*y)%p)*z;
        ans%=p;
        x=2;
        y=9;
        z=po[n-i-1];
        ans+=((x*y)%p)*z;
        ans%=p;
        cout<<(ans*10)%p<<" ";
    }
    return 0;
}