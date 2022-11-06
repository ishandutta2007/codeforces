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

int pow(int a, int st)
{
    int ans=1;
    for(int i=1; i<=st; i++)
        ans*=a;
    return ans;
}

int main()
{   
  /*  freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    int a, b, c, n, i, j, tmp, f;
    cin >> a >> b >> n;
    if (!a && !b)
    {
        printf("1");
        return 0;
    }
    if (!a || b%a)
    {
        printf("No solution");
        return 0;
    }
    c=b/a;
    for(i=-1000; i<=1000; i++)
    {
        tmp=1;
        for(j=1; j<=n; j++)
        {
            tmp*=i;
            if (abs(tmp)>abs(c)) 
                break;
        }
        if (tmp==c)
        {
            printf("%d", i);
            return 0;
        }
    }
    printf("No solution");
}