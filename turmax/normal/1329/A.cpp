#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    int a[m];
    int s=0;
    for(int i=0;i<m;++i)
    {
        cin>>a[i];
        s+=a[i];
    }
    if(s<n)
    {
        cout<<(-1);
        return 0;
    }
    int res[n];
    for(int i=0;i<m;++i)
    {
        if(a[i]>=(n-i+1))
        {
            cout<<(-1);
            return 0;
        }
        res[i]=max(i,n-s);
        s-=a[i];
    }
    for(int i=0;i<m;++i)
    {
        cout<<res[i]+1<<" ";
    }
    return 0;
}