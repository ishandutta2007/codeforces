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

int l[5005], r[5005], good[5005];

int main()
{   
   /* freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    int i, j, n, a, b, f=0, ans=0;
    cin >> n;
    for(i=0; i<n; i++)
        cin >> l[i] >> r[i];
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            if (j==i) 
                continue;
            if (l[i]<=l[j] && l[j]<r[i])
            {
                if (!f)
                {
                    a=i;
                    b=j;
                    good[i]=good[j]=1;
                    f=1;
                }
                else
                {
                    if (i!=a && j!=a)
                        good[a]=0;
                    if (i!=b && j!=b)
                        good[b]=0;
                }
            }
        }
    if (!f)
    {
        printf("%d\n", n);
        for(i=1; i<=n; i++)
            printf("%d ", i);
        return 0;
    }
    for(i=0; i<n; i++)
        ans+=good[i];
    printf("%d\n", ans);
    for(i=0; i<n; i++)
        if (good[i])
            printf("%d ", i+1);
}