#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int cyc=0;cyc<t;++cyc)
    {
    int n;
    cin>>n;
    int ans=0;
    int z;
    while(n>=10)
    {
        ans+=(n/10)*10;
        z=n%10;
        n/=10;
        n+=z;
    }
    cout<<ans+n<<endl;
    }
    return 0;
}