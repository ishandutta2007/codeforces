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

int m[8], x[10], y[10];

int check()
{
    if (x[m[1]]-x[m[0]]!=x[m[3]]-x[m[2]]) return 0;
    if (y[m[1]]-y[m[0]]!=y[m[3]]-y[m[2]]) return 0;
    if (x[m[5]]-x[m[4]]!=x[m[7]]-x[m[6]]) return 0;
    if (y[m[5]]-y[m[4]]!=y[m[7]]-y[m[6]]) return 0;
    if (x[m[2]]-x[m[0]]!=x[m[3]]-x[m[1]]) return 0;
    if (y[m[2]]-y[m[0]]!=y[m[3]]-y[m[1]]) return 0;
    if (x[m[6]]-x[m[4]]!=x[m[7]]-x[m[5]]) return 0;
    if (y[m[6]]-y[m[4]]!=y[m[7]]-y[m[5]]) return 0;
    if ((x[m[1]]-x[m[0]])*(x[m[1]]-x[m[0]])+(y[m[1]]-y[m[0]])*(y[m[1]]-y[m[0]])!=
        (x[m[2]]-x[m[0]])*(x[m[2]]-x[m[0]])+(y[m[2]]-y[m[0]])*(y[m[2]]-y[m[0]])) return 0;
    if ((x[m[1]]-x[m[0]])*(x[m[2]]-x[m[0]])+(y[m[1]]-y[m[0]])*(y[m[2]]-y[m[0]])) return 0;
    if ((x[m[5]]-x[m[4]])*(x[m[6]]-x[m[4]])+(y[m[5]]-y[m[4]])*(y[m[6]]-y[m[4]])) return 0;
    return 1;
}

int main()
{   
    int i, j, f=1*2*3*4*5*6*7*8;
    for(i=0; i<8; i++)
        m[i]=i+1;
    for(i=1; i<=8; i++)
        scanf("%d %d", &x[i], &y[i]);
    for(i=0; i<=f; i++)
    {
        if (check())
        {
            printf("YES\n");
            for(i=0; i<4; i++)
                printf("%d ", m[i]);
            putchar('\n');
            for(; i<8; i++)
                printf("%d ", m[i]);
            return 0;
        }
        next_permutation(m, m+8);
    }
    printf("NO");
}