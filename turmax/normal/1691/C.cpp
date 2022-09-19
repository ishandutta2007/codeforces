#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n,k;cin>>n>>k;string s;cin>>s;reverse(s.begin(),s.end());
        int ans=0;for(auto h:s) if(h=='1') {ans+=11;}
        int lz=(-1);for(int i=0;i<n;++i) if(s[i]=='1') {lz=i;break;}
        int rz=(-1);for(int i=n-1;i>=0;--i) if(s[i]=='1') {rz=(n-1-i);break;}
        if(lz==(-1))
        {
            cout<<ans<<'\n';continue;
        }
        if(lz+rz==(n-1))
        {
            if(k>=lz) {cout<<(ans-10)<<'\n';continue;}
            if(k>=rz) {cout<<(ans-1)<<'\n';continue;}
            cout<<ans<<'\n';continue;
        }
        if(k>=lz+rz) {cout<<ans-11<<'\n';continue;}
        if(k>=lz) {cout<<(ans-10)<<'\n';continue;}
        if(k>=rz) {cout<<(ans-1)<<'\n';continue;}
        cout<<ans<<'\n';continue;
    }
    return 0;
}