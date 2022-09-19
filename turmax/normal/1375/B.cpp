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
    int n,m;
    cin>>n>>m;
    int a[n][m];
    int b[n][m];
    bool h=true;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cin>>a[i][j];
            int curr=4;
            if(i==0) curr--;
            if(i==(n-1)) curr--;
            if(j==(m-1)) curr--;
            if(j==0) curr--;
            b[i][j]=curr;
            if(a[i][j]>curr) h=false;
        }
    }
    if(!h)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                cout<<b[i][j]<<' ';
            }
            cout<<endl;
        }
    }
    }
    return 0;
}