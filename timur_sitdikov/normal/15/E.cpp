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

long long mod=1000000009;

int main()
{   

    long long n, i, ans, a, m, v;
    scanf("%I64d", &n);
    a=1; v=1; m=2;
    for(ans=1, i=2; i<n; i+=2)
    {
        m=(m+(4*a)*v)%mod;
        v=(v*a)%mod;
        a=(2*a+3)%mod;
    }
    ans=(m*m)%mod;
    ans=(ans*2)%mod;
    ans=(ans+2)%mod;
    printf("%I64d", ans);
}