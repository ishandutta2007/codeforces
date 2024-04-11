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
int dp[1<<20];
bool vis[35];
map<int,int> dp2;
int a[105];
map<int,int> ma;
int find_ans(int x)
{
    if (x<(1<<20)) return dp[x];
    if (dp2.find(x)!=dp2.end()) return dp2[x];
    bool vis[35];
    memset(vis,0,sizeof(vis));
    int i;
    for (i=1;i<=30;i++)
    {
        vis[find_ans((x>>i)|(((1<<(i-1))-1)&x))]=true;
        if ((1<<i)>x) break;
    }
    for (i=0;i<=30;i++)
    {
        if (vis[i]) continue;
        break;
    }
    dp2[x]=i;
    return i;
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int i;
    dp[0]=0;
    for (i=1;i<(1<<20);i++)
    {
        int j;
        memset(vis,0,sizeof(vis));
        for (j=1;j<=20;j++)
        {
            vis[dp[(i>>j)|(((1<<(j-1))-1)&i)]]=true;
            if ((1<<j)>i) break;
        }
        for (j=0;j<=20;j++)
        {
            if (vis[j]) continue;
            break;
        }
        dp[i]=j;
    }
    int p=0;
    for (i=0;i<n;i++)
    {
        memset(vis,0,sizeof(vis));
        scanf("%d",&a[i]);
        int j;
        for (j=0;;j++)
        {
            if (a[i]%2!=0) break;
            a[i]/=2;
        }
        if (j==0) continue;
        vis[j]=true;
        p|=(1<<(j-1));
    }
    int now_ans=find_ans(p);
    for (i=0;i<n;i++)
    {
        int j;
        for (j=3;j*j<=a[i];j++)
        {
            if (a[i]%j==0)
            {
                int sum=0;
                for (;;)
                {
                    if (a[i]%j!=0) break;
                    a[i]/=j;
                    sum++;
                }
                ma[j]|=(1<<(sum-1));
            }
        }
        if (a[i]!=1) ma[a[i]]|=1;
    }
    map<int,int>::iterator ii;
    for (ii=ma.begin();ii!=ma.end();ii++)
    {
        now_ans^=dp[ii->second];
    }
    if (now_ans==0)
    {
        puts("Arpa");
    }
    else
    {
        puts("Mojtaba");
    }
    return 0;
}