#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=1e9+7;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int ans=(p+1)/2;
    int u=1;
    for(int i=0;i<n;++i)
    {
        ans*=2;
        ans%=p;
        u*=(i+1);
        u%=p;
    }
    cout<<((u-ans)%p+p)%p;
    return 0;
}