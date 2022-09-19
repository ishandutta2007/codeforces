#include <bits/stdc++.h>

using namespace std;
#define int long long
int a[51][51];
int h[51][51][51][51];
int z1[51][51][51];
int z2[51][51][51];
int isempty1(int x,int y1,int y2)
{
    if(z1[x][y1][y2]!=1e9)
    {
        return z1[x][y1][y2];
    }
    for(int i=y1;i<y2;++i)
    {
        if(a[x][i]==1)
        {
            z1[x][y1][y2]=0;
            return 0;
        }
    }
    z1[x][y1][y2]=1;
    return 1;
}
int isempty2(int x,int y1,int y2)
{
    if(z2[x][y1][y2]!=1e9)
    {
        return z2[x][y1][y2];
    }
    for(int i=y1;i<y2;++i)
    {
        if(a[i][x]==1)
        {
            z2[x][y1][y2]=0;
            return 0;
        }
    }
    z2[x][y1][y2]=1;
    return 1;
}
int solve(int u1,int u2,int u3,int u4)
{
    int y=h[u1][u2][u3][u4];
    if(y!=1e9)
    {
        return y;
    }
    if(u1==u2 || u3==u4)
    {
        return 0;
    }
    else
    {
        int s;
        if((u4-u3)>=(u2-u1))
        {
            s=(u4-u3);
            int o;
            for(int i=u3;i<u4;++i)
            {
                if(isempty1(i,u1,u2)==1)
                {
                    s=min(s,solve(u1,u2,u3,i)+solve(u1,u2,i+1,u4));
                    if(i==u3)
                    {
                        break;
                    }
                }
            }
        }
        if((u4-u3)<(u2-u1))
        {
            s=(u2-u1);
            int o;
            for(int i=u1;i<u2;++i)
            {
                if(isempty2(i,u3,u4)==1)
                {
                    s=min(s,solve(u1,i,u3,u4)+solve(i+1,u2,u3,u4));
                    if(i==u1)
                    {
                        break;
                    }
                }
            }
        }
        h[u1][u2][u3][u4]=s;
        return s;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for(int i=0;i<51;++i)
    {
        for(int j=0;j<51;++j)
        {
            for(int k=0;k<51;++k)
            {
                for(int l=0;l<51;++l)
                {
                    h[i][j][k][l]=1e9;
                }
            }
        }
    }
    for(int i=0;i<51;++i)
    {
        for(int j=0;j<51;++j)
        {
            for(int k=0;k<51;++k)
            {
                z1[i][j][k]=1e9;
                z2[i][j][k]=1e9;
            }
        }
    }
    int n;
    cin>>n;
    char s;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cin>>s;
            if(s=='#')
            {
                a[i][j]=1;
            }
            else
            {
                a[i][j]=0;
            }
        }
    }
    cout<<solve(0,n,0,n);
    return 0;
}