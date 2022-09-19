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
        sort(a,a+n);
        int sum=0;
        for(auto h:a) sum+=h;
        if((sum%n)!=0)
        {
            cout<<(-1)<<'\n';
            continue;
        }
        int mid=(sum/n);
        int ans=0;
        for(int i=0;i<n;++i) if(a[i]>mid) ++ans;
        cout<<ans<<'\n';
    }
    return 0;
}