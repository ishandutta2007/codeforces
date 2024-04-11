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
    int i, n, l[105], r[105], p1, p2, p3, t1, t2, ans=0;
    scanf("%d %d %d %d %d %d", &n, &p1, &p2, &p3, &t1, &t2);
    for(i=0; i<n; i++)
    {
        scanf("%d %d", &l[i], &r[i]);
        ans+=(r[i]-l[i])*p1;
    }
    for(i=1; i<n; i++)
    {
        ans+=p1*min(l[i]-r[i-1], t1);
        if (l[i]-r[i-1]>t1) ans+=min(l[i]-r[i-1]-t1, t2)*p2;
        if (l[i]-r[i-1]-t1>t2) ans+=(l[i]-r[i-1]-t1-t2)*p3;
    }
    printf("%d", ans);
}