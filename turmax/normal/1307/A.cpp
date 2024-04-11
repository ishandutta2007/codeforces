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
    int n,d;
    cin>>n>>d;
    vector <int> a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int ans=0;
    for(int i=0;i<n;++i)
    {
        while(a[i])
        {
            if(d>=i)
            {
                d-=i;
                a[i]--;
                ans++;
            }
            else
            {
                break;
            }
        }
    }
    cout<<ans<<endl;
    }
    return 0;
}