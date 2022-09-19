#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n,m;cin>>n>>m;
        if(m<n) {cout<<"No"<<'\n';continue;}
        if(n%2==0 && m%2==1) {cout<<"No"<<'\n';continue;}
        if(n%2==0)
        {
            cout<<"Yes"<<'\n';
            for(int i=0;i<n-2;++i) {cout<<1<<' ';}
            cout<<(m-n+2)/2<<' '<<(m-n+2)/2<<'\n';
            continue;
        }
        cout<<"Yes"<<'\n';
        for(int i=0;i<n-1;++i) cout<<1<<' '; cout<<m-n+1<<'\n';
    }
    return 0;
}