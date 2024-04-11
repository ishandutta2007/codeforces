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
    int a[n];
    for(int i=0;i<n;++i) cin>>a[i];
    int ans1=0;
    int ans2=0;
    for(int i=0;i<n;++i)
    {
        if((a[i]%2)!=(i%2))
        {
            if(i%2)
            {
                ++ans2;
            }
            else
            {
                ++ans1;
            }
        }
    }
    if(ans1==ans2)
    {
        cout<<ans1<<endl;
    }
    else
    {
        cout<<(-1)<<endl;
    }
    }
    return 0;
}