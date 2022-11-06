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

    long long mod=1000000007, n, m, k, i, ans=1, lim;
    scanf("%I64d %I64d %I64d", &n, &m, &k);
    if (k==1)
    {
        for(i=1; i<=n; i++)
            ans=(ans*m)%mod;
        printf("%I64d", ans);
        return 0;
    }
    if (k<n)
    {
        if (k&1) printf("%I64d", m*m); 
        else printf("%I64d", m); 
        return 0;
    }
    if (k==n) lim=(n+1)/2;
    else lim=n;
    for(i=1; i<=lim; i++)
        ans=(ans*m)%mod;
    printf("%I64d", ans);

}