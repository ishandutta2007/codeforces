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
        int n;
        cin>>n;
        int sum=0;
        for(int i=0;i<n;++i) {int x;cin>>x;sum+=x;}
        if((sum%n)==0) cout<<0<<'\n';
        else cout<<1<<'\n';
    }
    return 0;
}