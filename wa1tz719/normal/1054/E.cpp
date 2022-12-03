#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
string c[305][305];
string d[305][305];
vector<pair<pair<int,int>,pair<int,int> > > ans;
void record(int x,int y,int z,int w)
{
    ans.push_back(make_pair(make_pair(x,y),make_pair(z,w)));
}
int sum1[305],sum2[305];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n,m;
    scanf("%d%d",&n,&m);
    int i;
    for (i=0;i<n;i++)
    {
        int j;
        for (j=0;j<m;j++)
        {
            static char a[100005];
            scanf("%s",a);
            reverse(a,a+strlen(a));
            c[i][j]=a;
        }
    }
    for (i=0;i<n;i++)
    {
        int j;
        for (j=0;j<m;j++)
        {
            static char a[100005];
            scanf("%s",a);
            reverse(a,a+strlen(a));
            d[i][j]=a;
        }
    }
    int j;
    for (i=1;i<n-1;i++)
    {
        for (j=0;j<m;j++)
        {
            int k;
            for (k=0;k<(int)c[i][j].length();k++)
            {
                if (c[i][j][k]=='0')
                {
                    record(i+1,j+1,1,j+1);
                    sum1[j]++;
                }
                else
                {
                    record(i+1,j+1,n,j+1);
                    sum2[j]++;
                }
            }
        }
    }
    for (j=1;j<m;j++)
    {
        int k;
        for (k=0;k<(int)c[0][j].length();k++)
        {
            if (c[0][j][k]=='0')
            {
                record(1,j+1,1,1);
            }
            else
            {
                record(1,j+1,n,j+1);
                sum2[j]++;
            }
        }
    }
    for (j=0;j<m-1;j++)
    {
        int k;
        for (k=0;k<(int)c[n-1][j].length();k++)
        {
            if (c[n-1][j][k]=='0')
            {
                record(n,j+1,1,j+1);
                sum1[j]++;
            }
            else
            {
                record(n,j+1,n,m);
            }
        }
    }
    for (j=1;j<m;j++)
    {
        int k;
        for (k=0;k<sum1[j];k++)
        {
            record(1,j+1,1,1);
        }
    }
    for (j=0;j<m-1;j++)
    {
        int k;
        for (k=0;k<sum2[j];k++)
        {
            record(n,j+1,n,m);
        }
    }
    for (i=0;i<(int)c[0][0].length();i++)
    {
        if (c[0][0][i]=='0')
        {
            record(1,1,1,m);
            record(1,m,1,1);
        }
        else
        {
            record(1,1,1,m);
            record(1,m,n,m);
        }
    }
    for (i=0;i<(int)c[n-1][m-1].length();i++)
    {
        if (c[n-1][m-1][i]=='0')
        {
            record(n,m,1,m);
            record(1,m,1,1);
        }
        else
        {
            record(n,m,1,m);
            record(1,m,n,m);
        }
    }
    for (i=1;i<n-1;i++)
    {
        for (j=0;j<m;j++)
        {
            int k;
            for (k=0;k<(int)d[i][j].size();k++)
            {
                if (d[i][j][k]=='0')
                {
                    if (j!=0)
                    {
                        record(1,1,1,j+1);
                    }
                    record(1,j+1,i+1,j+1);
                }
                else
                {
                    if (j!=m-1)
                    {
                        record(n,m,n,j+1);
                    }
                    record(n,j+1,i+1,j+1);
                }
            }
        }
    }
    for (j=1;j<m-1;j++)
    {
        int k;
        for (k=0;k<(int)d[0][j].size();k++)
        {
            if (d[0][j][k]=='0')
            {
                record(1,1,1,j+1);
            }
            else
            {
                record(n,m,1,m);
                record(1,m,1,j+1);
            }
        }
    }
    for (j=1;j<m-1;j++)
    {
        int k;
        for (k=0;k<(int)d[n-1][j].size();k++)
        {
            if (d[n-1][j][k]=='0')
            {
                record(1,1,n,1);
                record(n,1,n,j+1);
            }
            else
            {
                record(n,m,n,j+1);
            }
        }
    }
    int k;
    for (k=0;k<(int)d[0][0].size();k++)
    {
        if (d[0][0][k]=='0')
        {
            record(1,1,n,1);
            record(n,1,1,1);
        }
        else
        {
            record(n,m,n,1);
            record(n,1,1,1);
        }
    }
    for (k=0;k<(int)d[n-1][m-1].size();k++)
    {
        if (d[n-1][m-1][k]=='0')
        {
            record(1,1,n,1);
            record(n,1,n,m);
        }
        else
        {
            record(n,m,n,1);
            record(n,1,n,m);
        }
    }
    for (k=0;k<(int)d[n-1][0].size();k++)
    {
        if (d[n-1][0][k]=='0')
        {
            record(1,1,n,1);
        }
        else
        {
            record(n,m,n,1);
        }
    }
    for (k=0;k<(int)d[0][m-1].size();k++)
    {
        if (d[0][m-1][k]=='0')
        {
            record(1,1,1,m);
        }
        else
        {
            record(n,m,1,m);
        }
    }
    printf("%d\n",ans.size());
    for (i=0;i<(int)ans.size();i++)
    {
        printf("%d %d %d %d\n",ans[i].first.first,ans[i].first.second,ans[i].second.first,ans[i].second.second);
    }
    return 0;
}