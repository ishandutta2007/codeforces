#include <bits/stdc++.h>

using namespace std;
const int maxk=40;
const int maxn=1e3+5;
int c[maxk][maxk];
int b[maxn][maxn][maxk];
void floyd(int k)
{
    for(int i=0;i<k;++i)
    {
        for(int j=0;j<k;++j)
        {
            for(int l=0;l<k;++l)
            {
                c[j][l]=min(c[j][l],c[j][i]+c[i][l]);
            }
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i=0;i<maxk;++i)
    {
        for(int j=0;j<maxk;++j)
        {
            c[i][j]=1e9;
        }
    }
    int n,m,k;
    cin>>n>>m>>k;
    int a[n][m];
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cin>>a[i][j];
            a[i][j]--;
            for(int l=0;l<maxk;++l)
            {
                b[i][j][l]=1e9;
            }
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(i>=1)
            {
                c[a[i][j]][a[i-1][j]]=2;
            }
            if(j>=1)
            {
                c[a[i][j]][a[i][j-1]]=2;
            }
            if(i<(n-1))
            {
                c[a[i][j]][a[i+1][j]]=2;
            }
            if(j<(m-1))
            {
                c[a[i][j]][a[i][j+1]]=2;
            }
        }
    }
    for(int i=0;i<maxk;++i) c[i][i]=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            b[i][j][a[i][j]]=0;
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(i>=1)
            {
                for(int l=0;l<k;++l)
                {
                    b[i][j][l]=min(b[i][j][l],b[i-1][j][l]+1);
                }
            }
            if(j>=1)
            {
                for(int l=0;l<k;++l)
                {
                    b[i][j][l]=min(b[i][j][l],b[i][j-1][l]+1);
                }
            }
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=(m-1);j>=0;--j)
        {
            if(i>=1)
            {
                for(int l=0;l<k;++l)
                {
                    b[i][j][l]=min(b[i][j][l],b[i-1][j][l]+1);
                }
            }
            if(j<(m-1))
            {
                for(int l=0;l<k;++l)
                {
                    b[i][j][l]=min(b[i][j][l],b[i][j+1][l]+1);
                }
            }
        }
    }
    for(int i=(n-1);i>=0;--i)
    {
        for(int j=0;j<m;++j)
        {
            if(i<(n-1))
            {
                for(int l=0;l<k;++l)
                {
                    b[i][j][l]=min(b[i][j][l],b[i+1][j][l]+1);
                }
            }
            if(j>=1)
            {
                for(int l=0;l<k;++l)
                {
                    b[i][j][l]=min(b[i][j][l],b[i][j-1][l]+1);
                }
            }
        }
    }
    for(int i=(n-1);i>=0;--i)
    {
        for(int j=(m-1);j>=0;--j)
        {
            if(i<(n-1))
            {
                for(int l=0;l<k;++l)
                {
                    b[i][j][l]=min(b[i][j][l],b[i+1][j][l]+1);
                }
            }
            if(j<(m-1))
            {
                for(int l=0;l<k;++l)
                {
                    b[i][j][l]=min(b[i][j][l],b[i][j+1][l]+1);
                }
            }
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            for(int l=0;l<k;++l)
            {
                c[a[i][j]][l]=min(c[a[i][j]][l],b[i][j][l]+1);
            }
        }
    }
    floyd(k);
    int q;
    cin>>q;
    while(q--)
    {
        int r1,c1,r2,c2;
        cin>>r1>>c1>>r2>>c2;
        r1--;c1--;r2--;c2--;
        int ans=abs(r1-r2)+abs(c1-c2);
        for(int h1=0;h1<k;++h1)
        {
            ans=min(ans,b[r1][c1][h1]+b[r2][c2][h1]+1);
            for(int h2=0;h2<k;++h2)
            {
                ans=min(ans,b[r1][c1][h1]+b[r2][c2][h2]+c[h1][h2]+1);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}