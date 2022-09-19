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
        int a,b,n;
        cin>>a>>b>>n;
        int c1[n];
        int c2[n];
        int deq1[a];
        for(int i=0;i<a;++i) deq1[i]=0;
        int deq2[b];
        for(int i=0;i<b;++i) deq2[i]=0;
        int ans=n*(n-1)/2;
        for(int i=0;i<n;++i) {cin>>c1[i];deq1[c1[i]-1]++;}
        for(int i=0;i<n;++i) {cin>>c2[i];deq2[c2[i]-1]++;}
        for(int i=0;i<a;++i) ans-=(deq1[i]*(deq1[i]-1))/2;
        for(int i=0;i<b;++i) ans-=(deq2[i]*(deq2[i]-1))/2;
        cout<<ans<<'\n';
    }
    return 0;
}