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
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int ans=b;
    int x=(a-b);
    if(x<=0)
    {
        cout<<b<<endl;
        continue;
    }
    if(d>=c)
    {
        cout<<(-1)<<endl;
        continue;
    }
    int o=(x+c-d-1)/(c-d);
    ans+=(o*c);
    cout<<(ans)<<endl;
    }
    return 0;
}