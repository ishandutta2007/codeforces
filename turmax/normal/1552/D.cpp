#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;++i) cin>>a[i];
        bool ok=0;
        for(int mask=1;mask<(1<<n);++mask)
        {
            for(int mask2=mask;;mask2=(mask2-1) & mask)
            {
                int sum=0;
                for(int i=0;i<n;++i)
                {
                    if(mask & (1<<i))
                    {
                        if(mask2 & (1<<i)) sum-=a[i];
                        else sum+=a[i];
                    }
                }
                ok=(ok || sum==0);
                if(mask2==0)
                {
                    break;
                }
            }
            if(ok) break;
        }
        if(ok) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
    return 0;
}