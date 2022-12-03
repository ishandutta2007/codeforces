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
int l[1005],r[1005];
int ans[1005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int i;
    for (i=0;i<n;i++)
    {
        scanf("%d",&l[i]);
    }
    for (i=0;i<n;i++)
    {
        scanf("%d",&r[i]);
    }
    int cnt=n;
    memset(ans,-1,sizeof(ans));
    for (;cnt>=1;cnt--)
    {
        for (i=0;i<n;i++)
        {
            if (ans[i]!=-1)
            {
                continue;
            }
            if ((l[i]==0)&&(r[i]==0))
            {
                ans[i]=cnt;
            }
        }
        for (i=0;i<n;i++)
        {
            if (ans[i]==cnt)
            {
                int j;
                for (j=0;j<i;j++)
                {
                    r[j]--;
                    if ((ans[j]==-1)&&(r[j]<0))
                    {
                        puts("NO");
                        return 0;
                    }
                }
                for (j=i+1;j<n;j++)
                {
                    l[j]--;
                    if ((ans[j]==-1)&&(l[j]<0))
                    {
                        puts("NO");
                        return 0;
                    }
                }
            }
        }
    }
    for (i=0;i<n;i++)
    {
        if (ans[i]==-1)
        {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    for (i=0;i<n;i++)
    {
        printf("%d ",ans[i]);
    }
    return 0;
}