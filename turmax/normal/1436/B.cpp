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
        int a[n][n];
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if((i+1)%n==j || i==j)
                {
                    a[i][j]=1;
                }
                else
                {
                    a[i][j]=0;
                }
            }
        }
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                 cout<<a[i][j]<<' ';
            }
            cout<<endl;
        }
    }
    return 0;
}