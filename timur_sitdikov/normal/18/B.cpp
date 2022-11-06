#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int cmp(const void *c1, const void *c2)
{return 0;}

int main()
{   
 
    long long n, i, m, d, l, cur, cur1;
    scanf("%I64d %I64d %I64d %I64d", &n, &d, &m, &l);
    cur1=((n-1)*m+l)/d*d+d;
    for(cur=0, i=1; i<m; i++)
    {
        cur+=d%m;
        if (cur>=m) cur-=m;
        if (cur>l) break;
    }
    if (i<m) printf("%I64d\n", i*d);
    else printf("%I64d\n", cur1);
}