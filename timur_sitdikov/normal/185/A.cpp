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

long long pow_mod(long long v, long long st, long long mod)
{
    long long a=v, ans=1;
    for(; st; st/=2)
    {
        if (st&1) ans=(ans*a)%mod;
        a=(a*a)%mod;
    }
    return ans;
}

int main()
{   
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    long long n, ans, mod=1000000007;
    scanf("%I64d", &n);
    if (!n) {printf("%d", 1); return 0;}
    ans=pow_mod(2, n-1, mod)*(pow_mod(2, n, mod)+1)%mod;
    printf("%I64d", ans);
}