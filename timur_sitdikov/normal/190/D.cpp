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

pair<int, int> nums[400005], segs[400005];
char col[400005];

int main()
{   
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    int n, m, i, j, top=0, top1=0;
    long long ans=0;
    scanf("%d %d", &n, &m);
    for(i=0; i<n; i++)
    {
        scanf("%d", &nums[i].first);
        nums[i].second=i;
    }
    sort(nums, nums+n);
    for(i=0; i<n; )
    {
        for(j=i; j<n && nums[j].first==nums[i].first && j-i+1<m; j++)j=j;
        for(; j<n && nums[j].first==nums[i].first; i++, j++)
        {segs[top].first=nums[i].second; segs[top].second=nums[j].second; top++;}
        i=j;
    }
    sort(segs, segs+top);
    for(i=top-2, j=top-1; i>=0; i--)
        if (segs[i].second>segs[j].second) col[i]=1;
        else j=i;
        j=-1;
    for(i=0; i<top; i++)
    {
        if (col[i]) continue;
        ans+=(long long)(n-segs[i].second)*(long long)(segs[i].first-j);
        j=segs[i].first;
    }
    printf("%I64d", ans);
}