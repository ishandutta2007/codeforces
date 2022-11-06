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

int val[100005], m[100005];

int main()
{   
    int n, i, sum=0, cur;
    long long ans=0;
    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
        scanf("%d", &m[i]);
        sum+=m[i];
    }
    if (sum%3) {printf("0"); return 0;}
    for(cur=0, i=1; i<n; i++)
    {
        cur+=m[i];
        if (cur==sum/3) val[i]=1;
        if (cur==sum*2/3) ans+=(long long)val[i-1];
        val[i]+=val[i-1];
    }
    printf("%I64d", ans);
}