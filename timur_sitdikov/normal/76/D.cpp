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

char good[100];
unsigned long long st2(long long st)
{
    unsigned long long ans=1;
    for(int i=1; i<=st; i++)
        ans*=2;
    return ans;
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    unsigned long long a, b, x, y, i;
    scanf("%I64u %I64u", &a, &b);
    if (a<b)
    {
        printf("-1");
        return 0;
    }
    y=0;
    for(i=0; b; i++)
    {
        if (b&1)
        {
            good[i]=1;
            y+=st2(i);
        }
        b/=2;
    }
    a-=y;
    if ((a&1))
    {
        printf("-1");
        return 0;
    }
    a/=2;
    x=a;
    for(i=0; a; i++)
    {
        if ((a&1) && good[i])
        {
            printf("-1");
            return 0;
        }
        a/=2;
    }
    y|=x;
    cout << x << " " << y;
    //printf("%llu %llu", x, y);
}