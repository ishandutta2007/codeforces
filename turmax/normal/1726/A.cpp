#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;int a[2*n];for(int i=0;i<n;++i) {cin>>a[i];a[n+i]=a[i];}
        int ans=0;for(int i=0;i<n;++i) {ans=max(ans,a[i+n-1]-a[i]);}
        ans=max(ans,a[n-1]-*min_element(a,a+n));ans=max(ans,*max_element(a,a+n)-a[0]);
        cout<<ans<<'\n';
    }
    return 0;
}