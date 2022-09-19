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
        int n,k;cin>>n>>k;int a[n];for(int i=0;i<n;++i) cin>>a[i];
        map <int,int> u;for(auto h:a) u[h]=1;
        bool ok=false;
        for(int i=0;i<n;++i) if(u.count(a[i]+k)) ok=true;
        cout<<(ok ? "YES" : "NO")<<'\n';
    }
    return 0;
}