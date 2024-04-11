#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n,k;cin>>n>>k;int a[n];for(int i=0;i<n;++i) cin>>a[i]; int cnt=0;for(int i=0;i<k;++i) {if(a[i]<=k) ++cnt;} cout<<k-cnt<<'\n';
    }
    return 0;
}