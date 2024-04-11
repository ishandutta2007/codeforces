#pragma GCC optimize("O3","Ofast","unroll-loops")
#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    int a[n][m];
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<k;++i)
    {
        int c;
        cin>>c;
        int x=0;int y=(c-1);
        while(x<n)
        {
            int x1=x;int y1=y;
            if(a[x][y]==1)
            {
                ++y;
            }
            else if(a[x][y]==2)
            {
                ++x;
            }
            else
            {
                --y;
            }
            a[x1][y1]=2;
        }
        cout<<y+1<<' ';
    }
    return 0;
}