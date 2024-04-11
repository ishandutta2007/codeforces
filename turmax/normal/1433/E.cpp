#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int ans=1;
    for(int i=1;i<=n;++i) ans*=i;
    ans*=2;
    ans/=n;ans/=n;
    cout<<ans;
    return 0;
}