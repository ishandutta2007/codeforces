#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;

typedef long long ll;

const int N = 5000;
const int M = 50000;
char str[N];
int cntS[M];

int main()
{
#ifdef UMQRA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif      

    int a;
    scanf("%d", &a);
    scanf(" %s", str);
    int len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        int curSum = 0;
        for (int s = i; s < len; s++)   
        {
            curSum += str[s] - '0';
            cntS[curSum]++;
        }
    }

    ll ans = 0;
    if (a == 0)
    {          
        ll allC = (ll)len * (ll)(len + 1) / (ll)2;
        ll allZ = cntS[0];
        ans = 2 * (allC - allZ) * allZ + allZ * allZ;
        printf("%lld", ans);
        return 0;
    }

    for (int i = 0; i < len; i++)
    {
        int curSum = 0;
        for (int s = i; s < len; s++)
        {
            curSum += str[s] - '0';
            if (curSum == 0)
                continue;
            int t = a / curSum;
            if (t * curSum == a && t < M)
            {
                ans += cntS[t];
            }
        }
    }

    printf("%lld", ans);

    return 0;
}