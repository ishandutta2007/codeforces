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
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
        }
        int mi1[n];
        int u1[n];
        int u=0;
        int curr=1e18;
        for(int i=0;i<n;++i)
        {
            if(a[i]<curr)
            {
                curr=a[i];
                u=i;
            }
            mi1[i]=curr;
            u1[i]=u;
        }
        int mi2[n];
        int u2[n];
        curr=1e18;
        u=0;
        for(int i=(n-1);i>=0;--i)
        {
            if(a[i]<curr)
            {
                curr=a[i];
                u=i;
            }
            mi2[i]=curr;
            u2[i]=u;
        }
        bool h=false;
        for(int i=0;i<n;++i)
        {
            if(mi1[i]!=a[i] && mi2[i]!=a[i])
            {
                cout<<"YES"<<endl;
                cout<<u1[i]+1<<' '<<i+1<<' '<<u2[i]+1<<endl;
                h=true;
                break;
            }
        }
        if(!h)
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}