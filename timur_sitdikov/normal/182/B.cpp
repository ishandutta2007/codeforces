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

bool cmp(int a, int b)
{return a<b;}

int main()
{   
   /* freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    int i, d, n, a, ans=0;
    scanf("%d %d", &d, &n);
    for(i=0; i<n; i++)
    {
        scanf("%d", &a);
        if (i+1<n) ans+=d-a;
    }
    printf("%d", ans);
}