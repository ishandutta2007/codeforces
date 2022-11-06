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

int m[105];

int main()
{   
    int n, i, cur, ans;
    scanf("%d", &n);
    for(i=0; i<n; i++)
        scanf("%d", &m[i]);
    sort(m, m+n);
    cur=10; ans=0;
    for(i=0; i<n; i++)
    {
        cur+=m[i];
        if (cur>720) break;
        if (cur>360) ans+=cur-360;
    }
    printf("%d %d", i, ans);
}