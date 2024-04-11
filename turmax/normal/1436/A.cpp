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
        int n,m;
        cin>>n>>m;
        int a[n];
        int sum=0;
        for(int i=0;i<n;++i) {cin>>a[i];sum+=a[i];}
        if(sum==m) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}