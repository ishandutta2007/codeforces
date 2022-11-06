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

const int inf=1000000000;
map<int, pair<int, int> > mp;
map<int, pair<int, int> >::iterator it;

int main()
{   
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    int n, mn=inf, a, b, i;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%d %d", &a, &b);
        mp[a].first++;
        if (a!=b) mp[b].second++;
    }
    for(it=mp.begin(); it!=mp.end(); it++)
    {
        if (it->second.first+it->second.second>=(n+1)/2)
        {
            mn=min(mn, max(0, (n+1)/2-it->second.first));
        }
    }
    if (mn==inf)
        printf("-1");
    else printf("%d", mn);

}