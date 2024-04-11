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

pair<int, int> pr[25];

int main()
{   

    int n, i, j, lim, num, cur=0;
    scanf("%d %d", &lim, &n);
    for(i=0; i<n; i++)
        scanf("%d %d", &pr[i].second, &pr[i].first);
    sort(pr, pr+n);
    num=cur=0;
    for(i=n-1; i>=0; i--)
    {
        cur+=pr[i].second*pr[i].first;
        num+=pr[i].second;
        if (num>lim)
        {
            cur-=(num-lim)*pr[i].first;
            break;
        }
    }
    printf("%d", cur);
}