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
    int b[n];
    set <int> h;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;++i)
    {
        cin>>b[i];
    }
    bool ans=true;
    for(int i=0;i<n;++i)
    {
        if(a[i]!=b[i])
        {
            if(a[i]<b[i])
            {
                ans=(ans && h.count(1));
            }
            else
            {
                ans=(ans && h.count(-1));
            }
        }
        h.insert(a[i]);
    }
    if(ans)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    }
    return 0;
}