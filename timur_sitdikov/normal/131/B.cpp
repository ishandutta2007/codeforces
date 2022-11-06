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

int cmp(const void *c1, const void *c2)
{return *(int*)c1-*(int*)c2;}

bool cmp(int a, int b)
{return a<b;}

int main()
{   
    long long ans=0;
    map <long long, long long> mp;
    long long n, i, a;
    for(i=-10; i<=10; i++) mp[i]=0;
    scanf("%I64d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%I64d", &a);
        mp[a]++;
    }
    for(i=-10; i<0; i++)
        ans+=mp[i]*mp[-i];
    ans+=mp[0]*(mp[0]-1)/2;
    printf("%I64d\n", ans);
}