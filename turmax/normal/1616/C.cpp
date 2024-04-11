#include <bits/stdc++.h>

using namespace std;
#define int long long
int sq(int x1,int x2,int x3,int y1,int y2,int y3)
{
    return (x1*y2+x2*y3+x3*y1-x2*y1-x3*y2-x1*y3);
}
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
        int res=1e18;if(n==1) res=0;
        for(int i=0;i<n;++i)
        {
            for(int j=(i+1);j<n;++j)
            {
                int ans=0;
                for(int k=0;k<n;++k)
                {
                    if(sq(a[i],a[j],a[k],i,j,k)!=0) ++ans;
                }
                res=min(res,ans);
            }
        }
        cout<<res<<'\n';
    }
    return 0;
}