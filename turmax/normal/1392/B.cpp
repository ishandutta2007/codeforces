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
    if(k>=7) {k%=2;k+=4;}
    while(k--)
    {
    int d=(-1e18);
    for(int i=0;i<n;++i) d=max(d,a[i]);
    for(int i=0;i<n;++i) a[i]=d-a[i];
    }
    for(int i=0;i<n;++i) cout<<a[i]<<' ';
    cout<<endl;
    }
    return 0;
}