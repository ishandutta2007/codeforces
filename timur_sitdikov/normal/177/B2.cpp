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
   /* freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    long long n, i, ans=0;
    scanf("%I64d", &n);
    for(i=2; i*i<=n; )
    {
        if (n%i) i++;
        else
        {
            ans+=n;
            n/=i;
        }
    }
    if (n>1) ans+=n;
    ans++;
    printf("%I64d", ans);
}