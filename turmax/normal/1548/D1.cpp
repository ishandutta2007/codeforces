#pragma GCC optimize("O3","Ofast","unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    pair <int,int> a[n];int c[2][2];for(int i=0;i<2;++i) for(int j=0;j<2;++j) c[i][j]=0;
    for(int i=0;i<n;++i) {cin>>a[i].first>>a[i].second;c[(a[i].first/2)%2][(a[i].second/2)%2]++;}
    int ans=n*(n-1)*(n-2)/6;
    for(int i=0;i<2;++i)
    {
        for(int j=0;j<2;++j)
        {
            int x=c[i][j];
            ans-=(x*(x-1)*(x-2)/6);
            ans-=(x*(x-1)/2)*(n-x);
        }
    }
    cout<<n*(n-1)*(n-2)/6-ans;
    return 0;
}