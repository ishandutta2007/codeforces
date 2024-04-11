#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int ans1=0,ans2=0;int n;cin>>n;int a[n];for(int i=0;i<n;++i) {cin>>a[i];if(a[i]%2==0) ans1++; else ans2++;} cout<<min(ans1,ans2)<<'\n';
    }
    return 0;
}