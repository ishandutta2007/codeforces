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

int bi=1000000000, m[20005], sum[20005];


int main()
{   
    int n, i, j, ans=-bi, mod;
    scanf("%d", &n);
    for(i=0; i<n; i++)
        scanf("%d", &m[i]);
    for(i=3; i<=n; i++)
        if (!(n%i))
        {
            mod=n/i;
            for(j=0; j<mod; j++) sum[j]=0;
            for(j=0; j<n; j++)
                sum[j%mod]+=m[j];
            for(j=0; j<mod; j++)
                if (ans<sum[j]) ans=sum[j];
        }
    printf("%d", ans);
}