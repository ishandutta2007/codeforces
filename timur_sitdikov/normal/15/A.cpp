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

bool cmp(pair <int, int> a, pair <int, int> b)
{return a.first <b.first ;}

int main()
{   

    int i, tmp, ans=2, n, t;
    pair <int, int> pr[1005];
    scanf("%d %d", &n, &t);
    for(i=0; i<n; i++)
    {
        scanf("%d %d", &pr[i].first, &pr[i].second);
        pr[i].first<<=1; pr[i].second<<=1;
    }
    sort(pr, pr+n, cmp);
    t<<=1;
    for(i=1; i<n; i++)
    {
        tmp=pr[i].first-pr[i].second/2-pr[i-1].first-pr[i-1].second/2;
        if (tmp>t) ans+=2;
        else if (tmp==t) ans++;
    }
    printf("%d", ans);
}