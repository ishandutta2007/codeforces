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
int a[2005];
bool inpair[2005];
int pairs[2005];
bool vis[2005];
int main()
{
    #ifdef absi2011
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int m;
    scanf("%d",&m);
    int i;
    for (i=1;i<=n+n;i++)
    {
        scanf("%d",&a[i]);
    }
    for (i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        inpair[x]=true;
        inpair[y]=true;
        pairs[x]=y;
        pairs[y]=x;
    }
    int t;
    scanf("%d",&t);
    int must_choose=-1;
    for (i=1;i<=n+n;i++)
    {
        if (i%2==t%2)
        {
            if (must_choose==-1)
            {
                int j;
                int max_val=-1;
                int ans=-1;
                for (j=1;j<=n+n;j++)
                {
                    if (vis[j])
                    {
                        continue;
                    }
                    if (inpair[j])
                    {
                        int k=pairs[j];
                        if (a[k]>a[j])
                        {
                            ans=k;
                        }
                        else
                        {
                            ans=j;
                        }
                        break;
                    }
                    if (a[j]>max_val)
                    {
                        max_val=a[j];
                        ans=j;
                    }
                }
                printf("%d\n",ans);
                vis[ans]=true;
                fflush(stdout);
            }
            else
            {
                printf("%d\n",must_choose);
                vis[must_choose]=true;
                fflush(stdout);
            }
        }
        else
        {
            int x;
            scanf("%d",&x);
            vis[x]=true;
            if ((!inpair[x])||(vis[pairs[x]]))
            {
                must_choose=-1;
            }
            else
            {
                must_choose=pairs[x];
            }
        }
    }
    return 0;
}