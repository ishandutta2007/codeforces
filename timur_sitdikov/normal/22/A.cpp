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

int main()
{   

    int m[105], n, i;
    scanf("%d", &n);
    for(i=0; i<n; i++)
        scanf("%d", &m[i]);
    qsort(m, n, sizeof(int), cmp);
    for(i=1; i<n; i++)
        if (m[i]!=m[0]) 
        {printf("%d", m[i]); return 0;}
    printf("NO");
}