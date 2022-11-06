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
#define mp make_pair
#define point complex<double>

const int maxn=100005;
long long ans[maxn], a[maxn], s[maxn];

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    long long n, q, i, j, t, tmp;
    scanf("%I64d", &n);
    for(i=0; i<n; i++)
        scanf("%I64d", &a[i]);
    sort(a, a+n);
    s[0]=a[0];
    for(i=1; i<n; i++)
        s[i]=s[i-1]+a[i];
    scanf("%I64d", &q);
    for(j=0; j<q; j++)
    {
        scanf("%I64d", &t);
        if (ans[t])
        {
            printf("%I64d ", ans[t]);
            continue;
        }
        tmp=1;
        for(i=n-2; i>=0; i-=tmp)
        {
            ans[t]+=s[i];
            tmp*=t;
        }
        printf("%I64d ", ans[t]);
    }
}