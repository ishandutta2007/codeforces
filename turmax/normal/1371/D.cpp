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
    int n,k;
    cin>>n>>k;
    int res[n][n];
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            res[i][j]=0;
        }
    }
    int co=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            int sum=(i+j)%n;
            if(sum<(k/n))
            {
                res[i][j]=1;
            }
            else if(sum==(k/n))
            {
                if(co<(k%n))
                {
                    res[i][j]=1;
                    ++co;
                }
            }
        }
    }
    if(k%n==0) cout<<0<<endl;
    else cout<<2<<endl;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cout<<res[i][j];
        }
        cout<<endl;
    }
    }
    return 0;
}