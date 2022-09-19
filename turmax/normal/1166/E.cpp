#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    int x,n;
    cin>>x>>n;
    int a[x][n];
    for(int i=0;i<x;++i)
    {
        for(int j=0;j<n;++j)
        {
            a[i][j]=0;
        }
    }
    int t;
    int u;
    for(int i=0;i<x;++i)
    {
        cin>>t;
        for(int j=0;j<t;++j)
        {
            cin>>u;
            a[i][u]=1;
        }
    }
    string s="possible";
    int v;
    for(int i=0;i<x;++i)
    {
        for(int j=0;j<i;++j)
        {
            v=0;
            for(int k=0;k<n;++k)
            {
                if(a[i][k]==1 && a[j][k]==1)
                {
                    v=1;
                }
            }
            if(v==0)
            {
                s="impossible";
            }
        }
    }
    cout<<s;
    return 0;
}