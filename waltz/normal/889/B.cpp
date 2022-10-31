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
int next[205],last[205];
char a[100005];
bool vis[205];
bool tot_vis[205];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int i;
    memset(last,-1,sizeof(last));
    memset(next,-1,sizeof(next));
    for (i=0;i<n;i++)
    {
        scanf("%s",a);
        int j;
        for (j='a';j<='z';j++)
        {
            vis[j]=false;
        }
        for (j=0;a[j]!='\0';j++)
        {
            if (vis[a[j]])
            {
                puts("NO");
                return 0;
            }
            vis[a[j]]=true;
            tot_vis[a[j]]=true;
            if (j!=0)
            {
                if ((last[a[j]]!=-1)&&(last[a[j]]!=a[j-1]))
                {
                    puts("NO");
                    return 0;
                }
                last[a[j]]=a[j-1];
            }
            if (a[j+1]!='\0')
            {
                if ((next[a[j]]!=-1)&&(next[a[j]]!=a[j+1]))
                {
                    puts("NO");
                    return 0;
                }
                next[a[j]]=a[j+1];
            }
        }
    }
    for (i='a';i<='z';i++)
    {
        if (!tot_vis[i]) continue;
        char t=i;
        for (;;)
        {
            t=next[t];
            if (t==-1) break;
            if (t==i)
            {
                puts("NO");
                return 0;
            }
        }
    }
    for (i='a';i<='z';i++)
    {
        if (!tot_vis[i]) continue;
        if (last[i]==-1)
        {
            char t=i;
            for (;;)
            {
                putchar(t);
                t=next[t];
                if (t==-1) break;
            }
        }
    }
    putchar('\n');
    return 0;
}