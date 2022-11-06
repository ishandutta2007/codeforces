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
#include <complex>
using namespace std;
#define pb push_back

long long cubed(long long v)
{
    return v*v*v;
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    long long x[200][2], y[200][2], sum, sumx, sumy, i, j, k, n, m[200];
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> x[i][0] >> y[i][0] >> x[i][1] >> y[i][1];
        if (x[i][0]>x[i][1])
            swap(x[i][0], x[i][1]);
        if (y[i][0]>y[i][1])
            swap(y[i][0], y[i][1]);
        m[i]=cubed(x[i][1]-x[i][0]);
    }
    for(i=1; i<n; i++)
    {
        sum=m[i];
        sumx=m[i]*(x[i][0]+x[i][1]);
        sumy=m[i]*(y[i][0]+y[i][1]);
        for(j=i-1; j>=0; j--)
        {           
            if (sumx<2ll*x[j][0]*sum)
            {
                printf("%d", i);
                return 0;
            }
            if (sumx>2ll*x[j][1]*sum)
            {
                printf("%d", i);
                return 0;
            }
            if (sumy<2ll*y[j][0]*sum)
            {
                printf("%d", i);
                return 0;
            }
            if (sumy>2ll*y[j][1]*sum)
            {
                printf("%d", i);
                return 0;
            }
            sum+=m[j];
            sumx+=m[j]*(x[j][0]+x[j][1]);
            sumy+=m[j]*(y[j][0]+y[j][1]);
        }
    }
    printf("%d", n);
}