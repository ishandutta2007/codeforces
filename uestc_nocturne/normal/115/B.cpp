#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
typedef long long LL;
const int V=210;
const int oo=1000000000;
char map[V][V];
int dp[V],l[V],r[V];
int n,m,i,j,last,p;
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(i=0;i<n;i++)
        scanf("%s",map[i]);
        for(i=0;i<n;i++)
        dp[i]=oo;
        for(i=0;i<n;i++)l[i]=m+1,r[i]=-1;
        int last=-1;
        for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        {
            if(map[i][j]=='W')
            {
                last=i;
                l[i]=min(l[i],j);
                r[i]=max(r[i],j);
            }
        }
        if(last==-1){puts("0");continue;}
        if(r[i]==-1){dp[0]=0;p=0;}
        else{dp[0]=r[0];p=r[0];}
        for(i=1;i<=last;i++)
        {
            int te;
            if(r[i]==-1)
            {
                dp[i]=dp[i-1]+1;
        //  printf("%d %d\n",i,dp[i]);
                continue;
            }
            if(i%2==1)
            {
                if(p<r[i])te=r[i]-p+r[i]-l[i]+1;
                else te=p-l[i]+1;
                dp[i]=dp[i-1]+te;p=l[i];
            }
            else
            {
                if(p>l[i])te=p-l[i]+r[i]-l[i]+1;
                else te=r[i]-p+1;
                dp[i]=dp[i-1]+te;p=r[i];
            }
        //  printf("%d %d\n",i,dp[i]);
        }
        printf("%d\n",dp[last]);
    }
}