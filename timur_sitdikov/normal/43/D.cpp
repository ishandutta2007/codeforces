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
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, m, i, j, s;
    cin >> n >> m;
    if (n==1  && m!=2 || m==1 && n!=2) 
        printf("1\n%d %d %d %d\n", n, m, 1, 1);
    else if ((n&1) && (m&1))
        printf("1\n%d %d %d %d\n", 1, m, 1, 1);
    else printf("0\n");
    s=1; j=1;
    if (!(n&1) || m&1)
    {
        for(i=1; i<=n; i++)
            printf("%d %d\n", i, 1);
        for(i=n; i>0; i--, s=-s)
        {
            j+=s;
            for(; j<=m && j>1; j+=s)
                printf("%d %d\n", i, j);
        }
    }
    else
    {
        for(i=1; i<=m; i++)
            printf("%d %d\n", 1, i);
        for(i=m; i>0; i--, s=-s)
        {
            j+=s;
            for(; j<=n && j>1; j+=s)
                printf("%d %d\n", j, i);
        }
    }
    printf("1 1");
}