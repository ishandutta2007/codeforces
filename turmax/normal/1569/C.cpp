#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
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
        sort(a,a+n);reverse(a,a+n);
        if(a[0]==a[1])
        {
            int ans=1;
            for(int i=1;i<=n;++i) {ans*=i;ans%=p;}
            cout<<ans<<endl;
            continue;
        }
        if(a[0]>a[1]+1)
        {
            cout<<0<<endl;
            continue;
        }
        int cnt1=0;
        for(int i=0;i<n;++i) if(a[i]==a[1]) ++cnt1;
        int ans=1;
        for(int i=1;i<=n;++i) {if(i!=(cnt1+1)) {ans*=i;ans%=p;}}
        ans*=cnt1;ans%=p;
        cout<<ans<<endl;
    }
    return 0;
}