#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int m[105][105], bd[105], l[105], r[105];

int main()
{   
    int n, cur,mn,  i, j, j1, t, k, m, v, cx, cy, f, curx, cury, bx, by, bi=100000000;
    scanf("%d %d", &n, &k);
    cx=cy=k/2;
    for(t=0; t<n; t++)
    {
        scanf("%d", &v);
        mn=bi;
        for(i=1; i<=k; i++)
        {
            if (!bd[i])
            {
                curx=k/2+1-v/2;
                cury=curx+v-1;
                cur=0;
                for(j=curx; j<=cury; j++)
                    cur+=abs(k/2+1-i)+abs(k/2+1-j);
                if (cur<mn)
                {
                    mn=cur; bx=i; by=curx;
                }
            }
            else
            {
                cury=l[i]-1;
                curx=cury-v+1;
                if (curx>=1)
                {
                    cur=0;
                    for(j=curx; j<=cury; j++)
                        cur+=abs(k/2+1-i)+abs(k/2+1-j);
                    if (cur<mn)
                    {
                        mn=cur; bx=i; by=curx;
                    }
                }
                curx=r[i]+1;
                cury=curx+v-1;
                if (cury<=k)
                {
                    cur=0;
                    for(j=curx; j<=cury; j++)
                        cur+=abs(k/2+1-i)+abs(k/2+1-j);
                    if (cur<mn)
                    {
                        mn=cur; bx=i; by=curx;
                    }
                }
            }           
        }
        if (mn!=bi)
        {
            printf("%d %d %d\n", bx, by, by+v-1);
            if (!bd[bx])
            {
                bd[bx]=1;
                l[bx]=by;
                r[bx]=by+v-1;
            }
            else
            {
                if (by<l[bx]) l[bx]=by;
                else r[bx]=by+v-1;
            }
        }
        else printf("-1\n");
    }
}