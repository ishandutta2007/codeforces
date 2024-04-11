#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int r;
    int n;
    int k;
    vector <int> b,c,d;
    int u,v;
    cin>>n;
    int a[n+1][10];
    for(int j=0;j<(n+1);++j)
    {
    for(int i=0;i<10;++i)
    {
        if(i==0)
        {
        a[j][i]=0;
        }
        else
        {
        a[j][i]=(-1e18);
        }
    }
    }
    for(int i=0;i<n;++i)
    {
        b.clear();
        c.clear();
        d.clear();
        cin>>k;
        for(int j=0;j<k;++j)
        {
            cin>>u>>v;
            if(u==1)
            {
                b.push_back(v);
            }
            if(u==2)
            {
                c.push_back(v);
            }
            else
            {
                d.push_back(v);
            }
        }
        sort(b.begin(),b.end());
        reverse(b.begin(),b.end());
        sort(c.begin(),c.end());
        reverse(c.begin(),c.end());
        sort(d.begin(),d.end());
        reverse(d.begin(),d.end());
        for(int j=0;j<10;++j)
        {
            if(b.size()>=3)
            {
                r=a[i][(j+7)%10]+b[0]+b[1]+b[2];
                if(j<=2)
                {
                    r+=b[0];
                }
                a[i+1][j]=max(a[i+1][j],r);
            }
            if(b.size()>=2)
            {
                r=a[i][(j+8)%10]+b[0]+b[1];
                if(j<=1)
                {
                    r+=b[0];
                }
                a[i+1][j]=max(a[i+1][j],r);
            }
            if(b.size()>=1)
            {
                r=a[i][(j+9)%10]+b[0];
                if(j==0)
                {
                    r+=b[0];
                }
                a[i+1][j]=max(a[i+1][j],r);
            }
            if(b.size()>=1 && c.size()>=1)
            {
                r=a[i][(j+8)%10]+b[0]+c[0];
                if(j<=1)
                {
                    r+=max(b[0],c[0]);
                }
                a[i+1][j]=max(a[i+1][j],r);
            }
            if(c.size()>=1)
            {
                r=a[i][(j+9)%10]+c[0];
                if(j==0)
                {
                    r+=c[0];
                }
                a[i+1][j]=max(a[i+1][j],r);
            }
            if(d.size()>=1)
            {
                r=a[i][(j+9)%10]+d[0];
                if(j==0)
                {
                    r+=d[0];
                }
                a[i+1][j]=max(a[i+1][j],r);
            }
            a[i+1][j]=max(a[i][j],a[i+1][j]);
        }
    }
    int ma=0;
    for(int i=0;i<10;++i)
    {
        ma=max(ma,a[n][i]);
    }
    cout<<ma;
    return 0;
}