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

int a[100005], b[100005], ans[100005];

int main()
{   
   /* freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    int mod, n, m, i, j, sum=0;
    scanf("%d %d %d", &n, &m, &mod);
    for(i=0; i<n; i++) scanf("%d", &a[i]);
    for(i=0; i<m; i++) scanf("%d", &b[i]);
    for(i=0; i<n; i++)
    {
        if (i<m) sum+=b[i];
        if (i>=n-m+1) 
            sum-=b[i-(n-m+1)];
        if (sum<0) sum+=mod;
        sum%=mod;
        ans[i]=(a[i]+sum)%mod;
    }
    for(i=0; i<n; i++) printf("%d ", ans[i]);
}