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
int a[1005];
int n;
bool checks()
{
    int i;
    if (a[1]==-1) return false;
    for (i=2;i<=n;i++)
    {
        if (a[i]<a[i-1]) return false;
        if (a[i]==-1) return false;
    }
    return true;
}
int main()
{
    #ifdef absi2011
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    #endif
    int c,m;
    scanf("%d%d%d",&n,&m,&c);
    memset(a,-1,sizeof(a));
    for (;;)
    {
        int x;
        scanf("%d",&x);
        if (x>c/2)
        {
            int i;
            for (i=n;i>=1;i--)
            {
                if (a[i]==-1) break;
                if (a[i]<x) break;
            }
            printf("%d\n",i);
            a[i]=x;
        }
        else
        {
            int i;
            for (i=1;i<=n;i++)
            {
                if (a[i]==-1) break;
                if (a[i]>x) break;
            }
            printf("%d\n",i);
            a[i]=x;
        }
        fflush(stdout);
        if (checks()) return 0;
    }
    return 0;
}