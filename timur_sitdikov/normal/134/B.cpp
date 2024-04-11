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

int v;
int gcd(int a, int b)
{
    if (!b) return a;
    v+=a/b;
    return gcd(b, a%b);
}

int main()
{   
    int t, n, i, j, cur, mn=1000000;
    //scanf("%d", &t);
    t=1;
    for(j=0; j<t; j++)
    {
        mn=1000000;
        scanf("%d", &n);
        for(i=1; i<=n; i++)
        {
            v=0;
            cur=gcd(n, i);
            if (cur==1 && v<mn) mn=v;
        }
        printf("%d\n", mn-1);
    }
}