#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int ans=0;
    for(int sum=(c+1);sum<=(b+c);++sum)
    {
        int u1=max(sum-c,a);int u2=min(sum-b,b);
        if(u1>u2)
        {
            continue;
        }
        int ans1=(u2-u1+1);
        int ans2=min(sum-c,d-c+1);
        ans+=(ans1*ans2);
    }
    cout<<ans;
    return 0;
}