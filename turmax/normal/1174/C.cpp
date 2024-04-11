#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    bool used[n+1];
    int a[n+1];
    for(int i=0;i<(n+1);++i)
    {
        used[i]=false;
    }
    int curr=1;
    int x;
    for(int i=2;i<=n;++i)
    {
        x=0;
        for(int j=1;j<=(n/i);++j)
        {
            if(used[i*j]==false)
            {
                used[i*j]=true;
                a[i*j]=curr;
                x=1;
            }
        }
        curr+=x;
    }
    for(int i=2;i<=n;++i)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}