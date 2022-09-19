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
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;++i) cin>>a[i];
        int sum=0;
        for(int i=0;i<(n-1);++i)
        {
            if(a[i]!=a[i+1])
            {
                ++sum;
            }
        }
        if(k!=1)
        cout<<max(1LL,(sum+k-2)/(k-1))<<endl;
        else
        {
            if(sum==0) cout<<1<<endl;
            else cout<<(-1)<<endl;
        }
    }
    return 0;
}