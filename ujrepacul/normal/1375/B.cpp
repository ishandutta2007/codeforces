#include <bits/stdc++.h>
using namespace std;
int v[303][303];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long t,n,m,i,j;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=m;++j)
                cin>>v[i][j];
        }
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=m;++j)
            {
                int cnt=4;
                if(i==1 || i==n)
                    --cnt;
                if(j==1 || j==m)
                    --cnt;
                if(v[i][j]>cnt)
                {
                    cout<<"NO\n";
                    i=n+2;
                    break;
                }
                v[i][j]=cnt;
            }
        }
        if(i==n+3)
            continue;
        cout<<"Yes\n";
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=m;++j)
                cout<<v[i][j]<<' ';
            cout<<'\n';
        }
    }
    return 0;
}