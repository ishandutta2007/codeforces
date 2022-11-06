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

int main()
{   

    long long a, b, k, d, ans=0, i, n;
    scanf("%I64d %I64d", &n, &d);
    scanf("%I64d", &a);
    for(i=1; i<n; i++)
    {
        scanf("%I64d", &b);
        if (b<=a)
        {
            k=(a-b)/d+1;
            ans+=k;
            b+=k*d;
        }
        a=b;
    }
    printf("%I64d", ans);
}