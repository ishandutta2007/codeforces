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

char c[1000005];
int sum[1000005];

int main()
{   

    long long ans=0;
    int i, j, n, k, c1, c2;
    scanf("%d %s", &k, &c);
    n=strlen(c);
    if (k)
    {
        for(i=1; i<=n; i++)
            sum[i]=sum[i-1]+c[i-1]-'0';
        for(j=1; j<=n && sum[j]<k; j++);
        if (j>n) {printf("0"); return 0;}
        for(i=0; j<=n; )
        {
            for(c1=i; i<=n && sum[c1]==sum[i]; c1++);
            for(c2=j; j<=n && sum[c2]==sum[j]; c2++);
            ans+=(long long)(c1-i)*(long long)(c2-j);
            i=c1; j=c2;
        }
    }
    else 
    {
        for(i=0; i<n; )
            if (c[i]=='0')
            {
                for(j=i+1; j<n && c[j]=='0'; j++);
                ans+=(long long)(j-i)*(long long)(j-i+1)/2;
                i=j;
            }
            else i++;

    }
    printf("%I64d", ans);
}