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
        int m;
        cin>>m;
        int b[m];
        for(int i=0;i<m;++i)
        {
            cin>>b[i];
        }
        int ans[n+m];
        int la=0;int lb=0;
        for(int i=0;i<(n+m);++i)
        {
            if(la>=n)
            {
                ans[i]=b[lb];
                ++lb;
            }
            else if(lb>=m)
            {
                ans[i]=a[la];
                ++la;
            }
            else
            {
                if(a[la]<=b[lb])
                {
                    ans[i]=b[lb];
                    ++lb;
                }
                else
                {
                    ans[i]=a[la];
                    ++la;
                }
            }
        }
        int res1=0;
        int sum1=0;
        for(int i=0;i<m;++i)
        {
            sum1+=b[i];
            res1=max(res1,sum1);
        }
        int res2=0;
        int sum2=0;
        for(int i=0;i<n;++i)
        {
            sum2+=a[i];
            res2=max(res2,sum2);
        }
        cout<<res1+res2<<endl;
    }
    return 0;
}