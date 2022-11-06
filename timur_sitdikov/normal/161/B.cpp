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

pair <int, int> tt[1005], kk[1005];
int n1, n2, top;
vector <int> vv[1005];

int main()
{   

    int k, i, j, n, a, tmp;
    long long ans=0, sum=0;
    scanf("%d %d", &n, &k);
    for(i=0; i<n; i++)
    {
        scanf("%d %d", &a, &tmp);
        if (tmp==1) tt[n1++]=make_pair(a, i+1);
        else kk[n2++]=make_pair(a, i+1);
        sum+=(long long)a;
    }
    sort(tt, tt+n1);
    sort(kk, kk+n2);
    if (n1<k)
    {
        for(i=n1-1; i>=0; i--)
        {
            vv[top++].push_back(tt[i].second);
            ans+=(long long)tt[i].first;
        }
        for(i=0; top<k; i++)
            vv[top++].push_back(kk[i].second);
        for(; i<n2; i++)
            vv[top-1].push_back(kk[i].second);
    }
    else
    {
        for(i=n1-1; top<k-1; i--)
        {
            vv[top++].push_back(tt[i].second);
            ans+=(long long)tt[i].first;
        }
        if (n1>0 && n2>0) ans+=(long long)min(tt[0].first, kk[0].first);
        else if (n1>0) ans+=(long long)tt[0].first;
        else ans+=(long long)kk[0].first;
        for(; i>=0; i--)
            vv[top].push_back(tt[i].second);
        for(i=0; i<n2; i++)
            vv[top].push_back(kk[i].second);
    }
    printf("%I64d.", sum-(ans+1)/2);
    if (ans&1) printf("5");
    else printf("0");
    putchar('\n');
    for(i=0; i<k; i++)
    {
        printf("%d ", (int)vv[i].size());
        for(j=0; j<(int)vv[i].size(); j++)
            printf("%d ", vv[i][j]);
        putchar('\n');
    }
}