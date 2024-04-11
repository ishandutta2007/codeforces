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
    int n,x;
    cin>>n>>x;
    int a[n];
    for(int i=0;i<n;++i) cin>>a[i];
    int s=0;
    for(int i=0;i<n;++i) s+=a[i];
    if((s%x)!=0)
    {
        cout<<n<<endl;
        continue;
    }
    else
    {
        int l=0;
        for(int i=0;i<n;++i)
        {
            if(a[i]%x==0)
            {
                ++l;
            }
            else
            {
                break;
            }
        }
        if(l==n)
        {
            cout<<(-1)<<endl;
            continue;
        }
        int r=0;
        for(int i=(n-1);i>=0;--i)
        {
            if(a[i]%x==0)
            {
                ++r;
            }
            else
            {
                break;
            }
        }
        cout<<max(n-r-1,n-l-1)<<endl;
    }
    }
    return 0;
}