#include <bits/stdc++.h>
using namespace std;
int q,x,y;
bool pos1[57],pos2[57];
bool solve(int x,int y)
{
    memset(pos1,false,sizeof(pos1));
    memset(pos2,false,sizeof(pos2));
    for (int i=0;i<30;i++)
    {
        if (((1<<i)&x)>0) pos1[i]=true;
        if (((1<<i)&y)>0) pos2[i]=true;
    }
    int lx=0,rx=0;
    for (int i=0;i<=30;i++)
    {
        if (!pos2[i])
        {
            if (pos1[i])
            {
                ++lx;
                ++rx;
            }
        }
        else
        {
            if (pos1[i])
            {
                lx=min(lx,1);
            }
            else
            {
                if (rx==0) return false;
                --rx;
                lx=0;
            }
        }
    }
    if (lx>0) return false;
    return true;
}
int main()
{
    scanf("%d",&q);
    while (q--)
    {
        scanf("%d%d",&x,&y);
        bool flag=solve(x,y);
        if (flag) printf("YES\n"); else printf("NO\n");
    }
    return 0;
}