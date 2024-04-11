#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int a[n][n];
    for(int i=0;i<n;++i) for(int j=0;j<n;++j) a[i][j]=(-1);
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        pair <int,int> curr={i,i};
        a[i][i]=x;
        for(int j=1;j<x;++j)
        {
            if(curr.second!=0 && a[curr.first][curr.second-1]==(-1))
            {
                a[curr.first][curr.second-1]=x;
                curr.second--;
            }
            else if(curr.first+1<n && a[curr.first+1][curr.second]==(-1))
            {
                a[curr.first+1][curr.second]=x;
                curr.first++;
            }
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<=i;++j)
        {
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}