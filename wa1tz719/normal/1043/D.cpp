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
#define next d190
int a[15][100005];
int b[15][100005];
int next[100005];
int size[100005];
int dfs(int x)
{
    if (size[x]!=0)
    {
        return size[x];
    }
    if (next[x]==-1)
    {
        size[x]=1;
        return 1;
    }
    size[x]=dfs(next[x])+1;
    return size[x];
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n,m;
    scanf("%d%d",&n,&m);
    int i;
    for (i=0;i<m;i++)
    {
        int j;
        for (j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
            a[i][j]--;
            b[i][a[i][j]]=j;
        }
        a[i][n]=n;
        b[i][n]=n+1;
    }
    for (i=0;i<n;i++)
    {
        int j;
        int k=a[0][b[0][i]+1];
        if (k==n)
        {
            next[i]=-1;
            continue;
        }
        for (j=1;j<m;j++)
        {
            if (a[j][b[j][i]+1]!=k)
            {
                next[i]=-1;
                break;
            }
        }
        if (j==m)
        {
            next[i]=k;
        }
    }
    long long ma=0;
    for (i=0;i<n;i++)
    {
        ma=ma+dfs(i);
    }
    cout<<ma<<endl;
    return 0;
}