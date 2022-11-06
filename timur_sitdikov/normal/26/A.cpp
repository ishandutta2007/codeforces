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
    /*freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    int i, j, v, n, ans=0, ct;
    scanf("%d", &n);
    for(i=6; i<=n; i++)
    {
        ct=0; v=i;
        for(j=2; j*j<=v; j++)
            if (!(v%j))
            {
                ct++;
                while((!(v%j))) v/=j;
            }
        if (v>1) ct++;
        if (ct==2) ans++;
    }
    printf("%d", ans);
}