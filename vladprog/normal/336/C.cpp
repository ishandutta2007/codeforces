#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N=1e5+100;

int a[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int ans=-2;
    for(int v=0;v<=30;v++)
    {
        int res=~0ll;
        for(int i=1;i<=n;i++)
            if(a[i]&(1ll<<v))
                res&=a[i];
        //cout<<v<<" -> "<<res<<" -> "<<((1<<v)-1)<<" -> "<<(res&((1<<v)-1))<<"\n";
        if((res&((1<<v)-1))==0)
            ans=max(ans,v);
    }
    //cout<<ans<<"\n";
    int cnt=0;
    int v=ans;
    for(int i=1;i<=n;i++)
        if(a[i]&(1ll<<v))
            cnt++;
    cout<<cnt<<"\n";
    for(int i=1;i<=n;i++)
        if(a[i]&(1ll<<v))
            cout<<a[i]<<" ";
}